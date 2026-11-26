# Exp 8: Reverse Each Line & Count Chars, Words, Lines
from pathlib import Path

lines = Path(__file__).read_text(encoding="utf-8").splitlines()
print("First 2 lines reversed:")
for line in lines[:2]:
    print(" ", line[::-1])
chars = sum(len(l) for l in lines)
words = sum(len(l.split()) for l in lines)
print(f"Lines: {len(lines)}, Words: {words}, Chars: {chars}")
