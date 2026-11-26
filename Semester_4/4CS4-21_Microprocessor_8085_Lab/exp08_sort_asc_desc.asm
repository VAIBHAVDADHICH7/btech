; Exp 8: Sort array at 2001H (count at 2000H) in Ascending Order (change JC to JNC for Descending)
LDA 2000H
DCR A
MOV B, A           ; Outer loop count = N-1
OUTER:
    MOV C, B
    LXI H, 2001H
INNER:
    MOV A, M
    INX H
    CMP M          ; Compare arr[j] with arr[j+1]
    JC NO_SWAP     ; For Descending order, use JNC NO_SWAP
    MOV D, M
    MOV M, A
    DCX H
    MOV M, D
    INX H
NO_SWAP:
    DCR C
    JNZ INNER
    DCR B
    JNZ OUTER
HLT
