start: 
init: 
	clrf    PORTA           ; make sure port A output latches are low 
	clrf    PORTB           ; make sure port B output latches are low 
	bsf     STATUS,RP0      ; select memory bank 1 
	movlw 	b'11111111'     ; set port A data direction to inputs 
	movwf 	TRISA         
	movlw 	b'00000000'     ; set port B data direction to outputs 
	movwf 	TRISB          
	bcf     STATUS,RP0      ; select memory bank 0 
	goto    main 
;; for this program use the 2k 8 bit mem chip, with WE on B2, OE on B3, and the memorys 3 least
;; sig bits to B4-B6 (inclusive), all other pins on the mem chip need to be held low, and an led 
;; needs to be on B1
;; when B1 goes high move the 3 pins from the microcontroler to leds and see the value
main: 
	movlw	b'01111000' 
	movwf	PORTB		; make we high, oe low, and 3 pins high
	call	wait1000ms

	movlw	b'00000110' 
	movwf	PORTB		; make we low, oe high, and 3 pins low 

noend:
	goto 	noend

	END		        ; ends the program
