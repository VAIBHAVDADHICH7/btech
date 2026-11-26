/* Exp 3: Nested if-else and switch Statements */
#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    int largest;
    if (a >= b) {
        if (a >= c) largest = a;
        else largest = c;
    } else {
        if (b >= c) largest = b;
        else largest = c;
    }
    printf("Largest of (%d, %d, %d) = %d\n\n", a, b, c, largest);

    double x, y;
    char op;
    printf("Simple Calculator (e.g. 10 + 5): ");
    scanf("%lf %c %lf", &x, &op, &y);

    switch (op) {
        case '+': printf("Result = %.2f\n", x + y); break;
        case '-': printf("Result = %.2f\n", x - y); break;
        case '*': printf("Result = %.2f\n", x * y); break;
        case '/':
            if (y != 0) printf("Result = %.2f\n", x / y);
            else printf("Error: Division by zero.\n");
            break;
        default: printf("Invalid operator '%c'.\n", op);
    }
    return 0;
}
