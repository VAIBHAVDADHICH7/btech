; Exp 13: Stepper Motor Speed Control via 8255 Port A (80H)
; Adjust DELAY_VAL to vary speed
MVI A, 80H
OUT 83H
MOTOR_LOOP:
    MVI A, 09H ; Step 1
    OUT 80H
    CALL STEP_DELAY
    MVI A, 0CH ; Step 2
    OUT 80H
    CALL STEP_DELAY
    MVI A, 06H ; Step 3
    OUT 80H
    CALL STEP_DELAY
    MVI A, 03H ; Step 4
    OUT 80H
    CALL STEP_DELAY
    JMP MOTOR_LOOP

STEP_DELAY:
    LXI D, 1500H   ; Decrease for faster speed, increase for slower speed
M1: DCX D
    MOV A, D
    ORA E
    JNZ M1
    RET
