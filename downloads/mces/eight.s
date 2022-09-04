		AREA ONESANDZEROS, CODE, READONLY
			
		LDR		R0, MEMORY
		LDR		R1, [R0]
		MOV		R4, #32
		
ROTATE	RORS	R1, #1
		BCS		ONES
		ADD	 	R3, R3, #1
		B		NEXT
		
ONES	ADD		R2, R2, #1
NEXT	SUBS	R4, #1
		CMP		R4, #0
		BNE		ROTATE
		
		STRB	R2, [R0, #5]
		STRB	R3, [R0, #6]
		
S		B		S

MEMORY	DCD		0X40000000
		
		END
		