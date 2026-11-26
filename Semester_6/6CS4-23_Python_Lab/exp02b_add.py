# Exp 2(b): Command-Line Addition (add.py)
import sys
if len(sys.argv) != 3:
    print("Usage: python3 exp02b_add.py <num1> <num2>")
else:
    print("Sum =", float(sys.argv[1]) + float(sys.argv[2]))
