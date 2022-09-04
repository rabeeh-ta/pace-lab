; add no from 1 to 10 and find sum
		AREA SUMOFTEN, CODE, READONLY
			
		ENTRY
		MOV 	R0, #1
		MOV		R1, #10
		MOV		R2, #0
		
LOOP	ADD		R2, R2, R0
		ADD		R0, R0, #1
		ADD		R1, R1, #-1
		CMP 	R1, #0
		BNE		LOOP
		LDR		R3, RESULT
		STR		R2, [R3]
S		B		S

RESULT	DCD		0X40000000
		END