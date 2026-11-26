; Exp 11: Generate Square Wave on SOD Pin of 8085 (observe on CRO)
START:
    MVI A, C0H     ; D7=1 (SOD=1), D6=1 (SOE=1)
    SIM
    CALL DELAY
    MVI A, 40H     ; D7=0 (SOD=0), D6=1 (SOE=1)
    SIM
    CALL DELAY
    JMP START

DELAY:
    MVI B, FFH
D1: DCR B
    JNZ D1
    RET
