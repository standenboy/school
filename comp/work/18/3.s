loop:
 SUB R0, R0, 5
 CMP R0, #5
 BLT end
 ADD R1, R1, 1
 B loop

end:
 STR R1, 101
