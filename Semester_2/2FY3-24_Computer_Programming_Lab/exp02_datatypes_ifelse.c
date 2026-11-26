/* Exp 2: Data Types, Variables, and if-else Statements */
#include <stdio.h>

int main(void) {
    char c = 'A';
    int age = 20;
    float gpa = 8.75f;
    double salary = 65000.50;

    printf("Sizes of C Data Types:\n");
    printf("char: %zu bytes | int: %zu bytes | float: %zu bytes | double: %zu bytes\n",
           sizeof(c), sizeof(age), sizeof(gpa), sizeof(salary));

    int num;
    printf("\nEnter an integer: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("%d is EVEN.\n", num);
    } else {
        printf("%d is ODD.\n", num);
    }

    if (num >= 0) {
        printf("%d is NON-NEGATIVE.\n", num);
    } else {
        printf("%d is NEGATIVE.\n", num);
    }
    return 0;
}
