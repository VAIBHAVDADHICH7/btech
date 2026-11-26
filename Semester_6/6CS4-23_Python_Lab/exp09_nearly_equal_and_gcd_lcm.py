# Exp 9: nearly_equal(a, b) & One-line GCD/LCM
import math

def nearly_equal(a: str, b: str) -> bool:
    if abs(len(a) - len(b)) > 1: return False
    i = j = edits = 0
    while i < len(a) and j < len(b):
        if a[i] != b[j]:
            edits += 1
            if edits > 1: return False
            if len(a) > len(b): i += 1
            elif len(b) > len(a): j += 1
            else: i += 1; j += 1
        else:
            i += 1; j += 1
    return edits + abs(len(a) - i - (len(b) - j)) == 1

gcd = lambda a, b: math.gcd(a, b)
lcm = lambda a, b: abs(a * b) // math.gcd(a, b)

print("nearly_equal('python', 'pytho'):", nearly_equal("python", "pytho"))
print("GCD(24, 36) =", gcd(24, 36), "| LCM(24, 36) =", lcm(24, 36))
