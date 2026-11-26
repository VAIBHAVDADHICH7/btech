; Exp 9: Multiply two 8-bit numbers at 2000H & 2001H -> 16-bit result at 2002H-2003H
LXI H, 2000H
MOV E, M       ; Multiplicand
MVI D, 00H
INX H
MOV A, M       ; Multiplier
LXI H, 0000H   ; Product = 0
MVI B, 08H     ; 8 bits
MUL_LOOP:
    DAD H      ; Shift product left
    RAL        ; Shift multiplier MSB into Carry
    JNC SKIP_ADD
    DAD D      ; Product += Multiplicand
SKIP_ADD:
    DCR B
    JNZ MUL_LOOP
SHLD 2002H
HLT
