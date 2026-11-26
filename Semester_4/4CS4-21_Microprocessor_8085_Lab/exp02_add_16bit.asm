; Exp 2: Add two 16-bit numbers at 2000H-2001H and 2002H-2003H, store at 2004H-2005H
LHLD 2000H     ; HL <- first 16-bit number
XCHG           ; DE <- first number
LHLD 2002H     ; HL <- second 16-bit number
DAD D          ; HL <- HL + DE
SHLD 2004H     ; Store 16-bit sum at 2004H-2005H
HLT
