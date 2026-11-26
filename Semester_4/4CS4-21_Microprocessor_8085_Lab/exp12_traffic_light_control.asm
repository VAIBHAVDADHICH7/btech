; Exp 12: Traffic Light Control via 8255 PPI (Control Port 83H, Port A 80H)
MVI A, 80H     ; All ports as Output
OUT 83H
TRAFFIC_CYCLE:
    MVI A, 21H ; Road1 Green, Road2 Red
    OUT 80H
    CALL LONG_DELAY
    MVI A, 22H ; Road1 Yellow, Road2 Red
    OUT 80H
    CALL SHORT_DELAY
    MVI A, 0CH ; Road1 Red, Road2 Green
    OUT 80H
    CALL LONG_DELAY
    MVI A, 14H ; Road1 Red, Road2 Yellow
    OUT 80H
    CALL SHORT_DELAY
    JMP TRAFFIC_CYCLE

LONG_DELAY:
    MVI C, 0AH
L1: CALL SHORT_DELAY
    DCR C
    JNZ L1
    RET

SHORT_DELAY:
    LXI D, FFFFH
S1: DCX D
    MOV A, D
    ORA E
    JNZ S1
    RET
