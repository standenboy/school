start: 
init: 
	clrf     PORTA          ; make sure port A output latches are low 
	clrf     PORTB          ; make sure port B output latches are low 
	bsf      STATUS,RP0     ; select memory bank 1 
	movlw 	 b'11111111'    ; set port A data direction to inputs 
	movwf 	 TRISA         
	movlw 	 b'00000000'    ; set port B data direction to outputs 
	movwf 	 TRISB          
	bcf      STATUS,RP0     ; select memory bank 0 
	goto     main 
main: 
	END		        ; ends the program