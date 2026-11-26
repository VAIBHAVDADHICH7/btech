/* Exp 8: Functions and Recursive Functions */
#include <stdio.h>

unsigned long long factorial(int n) {
    return (n <= 1) ? 1 : (unsigned long long)n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main(void) {
    int n = 6;
    printf("Factorial(%d) = %llu\n", n, factorial(n));
    printf("Fibonacci series (%d terms): ", n);
    for (int i = 0; i < n; i++) printf("%d ", fibonacci(i));
    printf("\nGCD(48, 18) = %d\n", gcd(48, 18));
    return 0;
}
