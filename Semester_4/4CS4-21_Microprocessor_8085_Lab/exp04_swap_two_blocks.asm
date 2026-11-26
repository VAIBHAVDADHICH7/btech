; Exp 4: Swap two blocks of N bytes at 2100H and 2200H (N at 2000H)
LDA 2000H
MOV C, A
LXI H, 2100H
LXI D, 2200H
SWAP_LOOP:
    MOV B, M       ; B <- [HL]
    LDAX D         ; A <- [DE]
    MOV M, A       ; [HL] <- A
    MOV A, B
    STAX D         ; [DE] <- B
    INX H
    INX D
    DCR C
    JNZ SWAP_LOOP
HLT
