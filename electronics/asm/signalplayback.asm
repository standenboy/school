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

	bsf	INTCON, INT0IE
	bsf	INTCON, GIE

	counter1 EQU B8

	goto    main 

interrupt:
	movf B0, W
	movwf counter1
	goto countdown

countdown:
	call wait1000ms
	decfsz counter1, F
	goto countdown

	bcf INTCON, INT0IF
	
	retfie

main: 
	call 	readadc0
	movf	B0, W
	movwf	PORTB

	goto 	main

	END		       	; ends the program
