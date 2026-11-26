/* Exp 1: Row-Major & Column-Major Address Calculation up to 4-D Arrays */
#include <stdio.h>
#include <stdint.h>

int main(void) {
    int a4[2][3][4][5];
    int D0 = 2, D1 = 3, D2 = 4, D3 = 5;
    int i = 1, j = 2, k = 3, l = 4;
    size_t w = sizeof(int);

    uintptr_t base = (uintptr_t)&a4[0][0][0][0];
    uintptr_t actual = (uintptr_t)&a4[i][j][k][l];

    /* C stores multidimensional arrays in Row-Major Order */
    size_t row_major_offset = (((i * D1 + j) * D2 + k) * D3 + l) * w;
    uintptr_t calc_row_major = base + row_major_offset;

    /* Column-Major theoretical address (as in Fortran/MATLAB) */
    size_t col_major_offset = (((l * D2 + k) * D1 + j) * D0 + i) * w;
    uintptr_t calc_col_major = base + col_major_offset;

    printf("Word size (sizeof(int)) : %zu bytes (pointer size: %zu bytes)\n", w, sizeof(void *));
    printf("Base address a4[0][0][0][0] : %p\n", (void *)base);
    printf("Actual address a4[%d][%d][%d][%d] : %p\n", i, j, k, l, (void *)actual);
    printf("Theoretical Row-Major       : %p (Match: %s)\n",
           (void *)calc_row_major, (actual == calc_row_major) ? "YES" : "NO");
    printf("Theoretical Column-Major    : %p\n", (void *)calc_col_major);
    return 0;
}
