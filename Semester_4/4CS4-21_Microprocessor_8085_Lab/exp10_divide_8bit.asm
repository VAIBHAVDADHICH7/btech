; Exp 10: Divide 8-bit dividend (2000H) by divisor (2001H) -> Quotient (2002H), Remainder (2003H)
LXI H, 2000H
MOV A, M       ; Dividend
INX H
MOV B, M       ; Divisor
MVI C, 00H     ; Quotient
DIV_LOOP:
    CMP B
    JC DIV_DONE
    SUB B
    INR C
    JMP DIV_LOOP
DIV_DONE:
    STA 2003H  ; Remainder
    MOV A, C
    STA 2002H  ; Quotient
HLT
