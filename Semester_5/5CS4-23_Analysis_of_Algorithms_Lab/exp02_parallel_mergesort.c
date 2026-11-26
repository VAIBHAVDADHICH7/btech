/* Exp 2: Parallelized Merge Sort using POSIX Threads (-pthread) */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct { int *arr, l, r, depth; } Task;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc((size_t)n1 * sizeof(int)), *R = malloc((size_t)n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    free(L); free(R);
}

void *pmergesort(void *arg) {
    Task *t = (Task *)arg;
    if (t->l >= t->r) return NULL;
    int m = t->l + (t->r - t->l) / 2;
    Task left = {t->arr, t->l, m, t->depth - 1};
    Task right = {t->arr, m + 1, t->r, t->depth - 1};
    if (t->depth > 0) {
        pthread_t th;
        pthread_create(&th, NULL, pmergesort, &left);
        pmergesort(&right);
        pthread_join(th, NULL);
    } else {
        pmergesort(&left); pmergesort(&right);
    }
    merge(t->arr, t->l, m, t->r);
    return NULL;
}

int main(void) {
    int n = 20000;
    int *a = malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++) a[i] = rand();
    Task root = {a, 0, n - 1, 2};
    clock_t t0 = clock();
    pmergesort(&root);
    printf("Parallel MergeSort n=%d -> %.3f ms\n", n, (double)(clock() - t0) * 1000.0 / CLOCKS_PER_SEC);
    free(a);
    return 0;
}
