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

	VARA 	 equ B20
	VARB 	 equ B21

	goto     main 
main: 
	btfsc	 PORTA, 0
	incf	 VARA, 0

	btfsc	 PORTA, 1
	goto 	 NEXTVAR
	
	goto 	 main

NEXTVAR:
	btfsc	 PORTA, 0
	incf	 VARB, 0

	btfsc	 PORTA, 1
	goto 	 ADDITION

	goto 	 NEXTVAR

ADDITION:
	movlw	 0
	addwf	 VARA, 0
	addwf	 VARB, 0
	
	movwf	 PORTB

	END		        ; ends the program
