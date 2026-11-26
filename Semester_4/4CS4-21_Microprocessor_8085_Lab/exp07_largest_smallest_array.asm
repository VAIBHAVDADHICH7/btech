; Exp 7: Find Largest (2050H) and Smallest (2051H) in array starting at 2001H (count at 2000H)
LXI H, 2000H
MOV C, M       ; Count
INX H
MOV A, M       ; Max = arr[0]
MOV B, M       ; Min = arr[0]
DCR C
NEXT_EL:
    INX H
    CMP M
    JNC CHK_MIN
    MOV A, M   ; New Max
CHK_MIN:
    MOV D, A   ; Save Max
    MOV A, B
    CMP M
    JC SKIP_MIN
    MOV B, M   ; New Min
SKIP_MIN:
    MOV A, D   ; Restore Max
    DCR C
    JNZ NEXT_EL
STA 2050H      ; Store Largest
MOV A, B
STA 2051H      ; Store Smallest
HLT
