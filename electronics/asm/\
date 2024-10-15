start: 
init: 
	clrf    PORTA           ; make sure port A output latches are low 
	clrf    PORTB           ; make sure port B output latches are low 
	bsf     STATUS,RP0      ; select memory bank 1 
	movlw 	b'00000000'     ; set port A data direction to inputs 
	movwf 	TRISA         
	movlw 	b'00001111'     ; set port B data direction to outputs 
	movwf 	TRISB          
	bcf     STATUS,RP0      ; select memory bank 0 

	;stackptr EQU B10
	tmpdata EQU B9

	goto    main 

main: 
	;movlw	0
	;movwf	stackptr
	
	movlw	b'00000001'
	movwf	PORTA

	movlw	b'10100000'	; move 1111 to the output
	movwf	PORTB

	movlw	b'00000000'
	movwf	PORTA

	movlw 	b'11111111'    
	movwf 	TRISB          
	
	movf	PORTB, W
	movwf	tmpdata	

	movlw 	b'00001111'     
	movwf 	TRISB          

	swapf	tmpdata, W 
	movwf	PORTB

noend:
	goto 	noend

	END		        ; ends the program
