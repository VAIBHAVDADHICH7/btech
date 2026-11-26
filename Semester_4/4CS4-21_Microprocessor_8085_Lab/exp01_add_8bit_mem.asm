; Exp 1: Add contents of 2000H and 2001H, store result in 2002H
LXI H, 2000H   ; HL points to first operand
MOV A, M       ; A <- [2000H]
INX H          ; HL <- 2001H
ADD M          ; A <- A + [2001H]
INX H          ; HL <- 2002H
MOV M, A       ; [2002H] <- A
HLT
