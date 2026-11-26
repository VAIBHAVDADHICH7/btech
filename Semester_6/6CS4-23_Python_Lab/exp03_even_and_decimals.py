# Exp 3: Even Check & Decimal Equivalents 1/2 .. 1/10
n = 14
print(f"{n} is {'Even' if n % 2 == 0 else 'Odd'}")
for i in range(2, 11):
    print(f"1/{i} = {1/i:.4f}")
