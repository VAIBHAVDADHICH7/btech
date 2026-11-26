# Exp 1: Basic Data Types in Python
a, b, c, d, e = 42, 3.14, "Python", True, 2 + 3j
for val in (a, b, c, d, e):
    print(f"{val!r} -> {type(val).__name__}")
