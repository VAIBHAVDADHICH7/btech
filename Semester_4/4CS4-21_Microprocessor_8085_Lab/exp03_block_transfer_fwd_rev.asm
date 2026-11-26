; Exp 3: Transfer block of N bytes (count at 2000H) from 2100H to 2200H (Forward) and 2300H (Reverse)
LDA 2000H      ; Count N
MOV C, A
LXI H, 2100H   ; Source
LXI D, 2200H   ; Dest (Forward)
FWD_LOOP:
    MOV A, M
    STAX D
    INX H
    INX D
    DCR C
    JNZ FWD_LOOP

; Reverse Transfer to 2300H
LDA 2000H
MOV C, A
LXI H, 2100H
LXI D, 2300H
ADD E          ; Point D to end of destination block
DCR A
MOV E, A
REV_LOOP:
    MOV A, M
    STAX D
    INX H
    DCX D
    DCR C
    JNZ REV_LOOP
HLT
