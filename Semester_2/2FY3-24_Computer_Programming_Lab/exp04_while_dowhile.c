/* Exp 4: Iterative Statements using while and do-while Loops */
#include <stdio.h>

int main(void) {
    int n, temp, rev = 0, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += digit;
        rev = rev * 10 + digit;
        temp /= 10;
    }
    printf("Sum of digits = %d\n", sum);
    printf("Reversed number = %d (%s)\n", rev, (rev == n) ? "Palindrome" : "Not Palindrome");

    int choice;
    do {
        printf("\nMenu: 1. Greet  2. Show Square of %d  0. Exit\nChoice: ", n);
        scanf("%d", &choice);
        if (choice == 1) printf("Welcome to C Loops!\n");
        else if (choice == 2) printf("Square = %d\n", n * n);
    } while (choice != 0);

    return 0;
}
