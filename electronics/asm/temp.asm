start: 
init: 
	clrf    PORTA          	; make sure port A output latches are low 
	clrf    PORTB          	; make sure port B output latches are low 
	bsf     STATUS,RP0     	; select memory bank 1 
	movlw 	b'11111111'    	; set port A data direction to inputs 
	movwf   TRISA         
	movlw   b'00000000'    	; set port B data direction to outputs 
	movwf   TRISB          
	bcf     STATUS,RP0     	; select memory bank 0 

	;bsf	INTCON, INT0IE
	;bsf	INTCON, GIE

	rawtemp EQU B6

	goto    main 
showme:
	movlw 	255
	movwf 	PORTB
	goto 	main
main: 
	call 	readadc1 	; read the thermistor (at room tem its 73)
	movf	B1, W
	movwf	rawtemp

	call	readadc0
	movf	B0, W

	subwf	rawtemp, w
	btfsc	STATUS, 0
	goto 	showme 

	movlw	0 
	movwf 	PORTB

	goto 	main

	END		       	; ends the program
