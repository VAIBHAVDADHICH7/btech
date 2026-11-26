/* Exp 12: Input Data through Command Line Arguments */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num1> <num2> ...\n", argv[0]);
        return 1;
    }
    double sum = 0.0;
    printf("Program: %s | Argument count: %d\n", argv[0], argc - 1);
    for (int i = 1; i < argc; i++) {
        double val = atof(argv[i]);
        sum += val;
        printf("  argv[%d] = %.2f\n", i, val);
    }
    printf("Sum = %.2f | Average = %.2f\n", sum, sum / (argc - 1));
    return 0;
}
