; Exp 5: Find square of 8-bit number at 2000H using repeated addition, store 16-bit result at 2001H-2002H
LDA 2000H
MOV B, A       ; Counter = N
MOV E, A       ; Value = N
MVI D, 00H
LXI H, 0000H   ; Accumulator = 0
SQ_LOOP:
    DAD D      ; HL <- HL + N
    DCR B
    JNZ SQ_LOOP
SHLD 2001H
HLT
