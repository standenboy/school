start: 
init: 
	clrf    PORTA          	; make sure port A output latches are low 
	clrf 	PORTB
	bsf     STATUS,RP0     	; select memory bank 1 

	movlw 	b'11111111'    	; set port A data direction to inputs 
	movwf   TRISA         
	movlw   b'00000000'    	; set port B data direction to outputs 
	movwf   TRISB          
	bcf     STATUS,RP0     	; select memory bank 0 

	bsf	INTCON, INT0IE
	bsf	INTCON, GIE

	rawtemp EQU B6
	countdown EQU B7

	movlw	5	
	movwf	countdown
	movlw 	0

	goto    main 

interrupt:
	btfss	INTCON, INT0IF
	retfie

	clrf 	PORTB

	bcf 	INTCON, INT0IF
	bsf 	INTCON, GIE
	bsf 	INTCON,	INT0IE 
	
	; USE A TRANSITOR WITH 1K resistor to the power rail of chip

	goto 	start		; restarts the program
	retfie

beep:				; a for loop that beeps a buzzer and turns on a led then sets a led on
				; if nothing is done

	bcf 	PORTB, 3 	; turn off the status
	bsf	PORTB, 0	; put a RED LED on PORTB:0
	bsf	PORTB, 1	; put a BUZZER on PORTB:1
	call 	wait1000ms
	bcf	PORTB, 0
	bcf	PORTB, 1
	call	wait1000ms

	decfsz	countdown, F
	goto	beep
	
	bsf	PORTB, 2	; put an AMBER LED on PORTB:2

	goto 	start	
main: 				; reads the temprature
	bsf  	PORTB,3		; put a GREEN LED for status on PORTB:3

	call 	readadc1 	; put a THERMISTOR on PORTA:1
	movf	B1, W
	movwf	rawtemp
				
	call	readadc0	; put a POT on PORTA:0	
	movf	B0, W

	subwf	rawtemp, w	; subtract the from the threshold value
	btfss	STATUS, 0 	; if higher than desired temp
	goto 	beep		; ^	

	clrf	STATUS

	goto 	main

	END		       	; ends the program
