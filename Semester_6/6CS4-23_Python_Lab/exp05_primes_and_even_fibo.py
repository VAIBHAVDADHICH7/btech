# Exp 5: Sum of Primes < 2,000,000 & Sum of Even Fibonacci <= 4,000,000
def sum_primes(limit):
    sieve = bytearray(b"\x01") * limit
    sieve[0:2] = b"\x00\x00"
    for p in range(2, int(limit ** 0.5) + 1):
        if sieve[p]:
            sieve[p*p:limit:p] = b"\x00" * len(sieve[p*p:limit:p])
    return sum(i for i, is_p in enumerate(sieve) if is_p)

a, b, even_fib_sum = 1, 2, 0
while b <= 4_000_000:
    if b % 2 == 0: even_fib_sum += b
    a, b = b, a + b

print("Sum of primes < 2,000,000:", sum_primes(2_000_000))
print("Sum of even Fibonacci <= 4,000,000:", even_fib_sum)
