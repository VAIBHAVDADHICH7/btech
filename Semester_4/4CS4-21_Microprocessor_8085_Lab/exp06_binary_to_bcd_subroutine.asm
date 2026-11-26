; Exp 6: Main program + Subroutine to convert 8-bit Binary (2000H) to unpacked BCD (2001H..2003H)
LXI SP, 27FFH
LDA 2000H
CALL BIN2BCD
HLT

BIN2BCD:
    MVI B, 00H     ; Hundreds
    MVI C, 00H     ; Tens
HUND_LOOP:
    CPI 64H        ; 100 decimal
    JC TENS_LOOP
    SUI 64H
    INR B
    JMP HUND_LOOP
TENS_LOOP:
    CPI 0AH        ; 10 decimal
    JC STORE_BCD
    SUI 0AH
    INR C
    JMP TENS_LOOP
STORE_BCD:
    STA 2001H      ; Units
    MOV A, C
    STA 2002H      ; Tens
    MOV A, B
    STA 2003H      ; Hundreds
    RET
