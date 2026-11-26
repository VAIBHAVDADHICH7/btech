/* Exp 6: 1-D Array, 2-D Array (Matrix Multiplication), and String Operations */
#include <stdio.h>
#include <string.h>

int main(void) {
    /* 1-D Array */
    int arr[5] = {12, 45, 7, 89, 23};
    int sum = 0, max = arr[0];
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
    }
    printf("1-D Array Sum = %d, Max = %d\n", sum, max);

    /* 2-D Array: 2x2 Matrix Multiplication */
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2] = {{0}};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];

    printf("\n2x2 Matrix Product:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%4d", C[i][j]);
        printf("\n");
    }

    /* String Operations */
    char s1[100] = "BTech", s2[50] = "CSE", copy[100];
    strcpy(copy, s1);
    strcat(copy, " ");
    strcat(copy, s2);
    printf("\nConcatenated String: %s (Length: %zu)\n", copy, strlen(copy));
    printf("Compare '%s' vs '%s': %d\n", s1, s2, strcmp(s1, s2));
    return 0;
}
