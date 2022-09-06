;multiply two 16 bit numbers and output a 32 bit number

   AREA MULTIPLY, CODE, READONLY
		ENTRY
		
		LDR		R0, MEMORY
		LDRH	R1, [R0]
		LDRH	R2, [R0, #2]
		MUL 	R2, R1,R2
		STR		R2,	[R0, #4]
			
MEMORY  DCD		0X40000000
		END