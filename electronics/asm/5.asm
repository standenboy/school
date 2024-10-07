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
	btfsc 	 PORTA, 0
	goto 	 led0

	btfsc 	 PORTA, 1
	goto 	 led1

	btfsc 	 PORTA, 2
	goto 	 led2

	call 	 wait1000ms
	call 	 wait1000ms

	movlw 	 b'00000000'
	movwf	 PORTB
	goto 	 main

led0:
	movlw 	 b'00000001'
	movwf	 PORTB
	goto 	 main

led1:
	movlw 	 b'00000010'
	movwf	 PORTB
	goto 	 main

led2:
	movlw 	 b'00000100'
	movwf	 PORTB
	goto 	 main

	end		        ; ends the program
