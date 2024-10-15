start: 
init: 
	clrf    PORTA           ; make sure port A output latches are low 
	clrf    PORTB           ; make sure port B output latches are low 
	bsf     STATUS, RP0     ; select memory bank 1 
	movlw 	b'11111111'     ; set port A data direction to inputs 
	movwf 	TRISA         
	movlw 	b'00000000'     ; set port B data direction to outputs 
	movwf 	TRISB          
	bcf     STATUS, RP0     ; select memory bank 0 

	bsf	INTCON, INT0IE
	bsf	INTCON, GIE

	goto    main 

interrupt:			; this will make port b go high for a set amount of time
	movlw 	255
	movwf 	PORTB
	call	wait1000ms
	movlw 	0	
	movwf 	PORTB

	bcf	INTCON, INT0IF

	retfie

main: 
	goto 	main
	END		        ; ends the program
