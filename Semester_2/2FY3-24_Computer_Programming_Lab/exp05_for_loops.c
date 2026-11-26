/* Exp 5: Iterative Statements using for Loops */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n (for factorial, prime check, and triangle pattern): ");
    scanf("%d", &n);

    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial of %d = %llu\n", n, fact);

    int is_prime = (n >= 2);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            is_prime = 0;
            break;
        }
    }
    printf("%d is %s\n", n, is_prime ? "Prime" : "Not Prime");

    printf("\nStar Pyramid (%d rows):\n", n);
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++) printf(" ");
        for (int k = 1; k <= 2 * i - 1; k++) printf("*");
        printf("\n");
    }
    return 0;
}
