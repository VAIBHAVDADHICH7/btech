/* Exp 10: Pointer Operations (Arithmetic, Call by Reference, Dynamic Memory) */
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
    int a = 10, b = 25;
    printf("Before swap: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("After swap : a=%d, b=%d\n", a, b);

    int n = 5;
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr) return 1;

    for (int i = 0; i < n; i++) *(arr + i) = (i + 1) * 10;

    printf("Dynamic array via pointer arithmetic:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d at address %p\n", i, *(arr + i), (void *)(arr + i));
    }
    free(arr);
    return 0;
}
