/* Exp 1: Quicksort Timing vs n */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
int part(int a[], int lo, int hi) {
    int p = a[hi], i = lo - 1;
    for (int j = lo; j < hi; j++) if (a[j] <= p) swap(&a[++i], &a[j]);
    swap(&a[i + 1], &a[hi]);
    return i + 1;
}
void qsort_rec(int a[], int lo, int hi) {
    if (lo < hi) { int p = part(a, lo, hi); qsort_rec(a, lo, p - 1); qsort_rec(a, p + 1, hi); }
}

int main(void) {
    int sizes[] = {1000, 5000, 10000, 20000};
    printf("n,time_ms\n");
    for (int s = 0; s < 4; s++) {
        int n = sizes[s];
        int *a = malloc((size_t)n * sizeof(int));
        for (int i = 0; i < n; i++) a[i] = rand();
        clock_t t0 = clock();
        qsort_rec(a, 0, n - 1);
        double ms = (double)(clock() - t0) * 1000.0 / CLOCKS_PER_SEC;
        printf("%d,%.3f\n", n, ms);
        free(a);
    }
    return 0;
}
