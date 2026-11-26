/* Exp 10: Insertion Sort, Bubble Sort, Quick Sort, and Heap Sort */
#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
void print_arr(const char *label, int a[], int n) {
    printf("%-15s: ", label);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) swap(&a[j], &a[j + 1]);
}

int partition(int a[], int lo, int hi) {
    int pivot = a[hi], i = lo - 1;
    for (int j = lo; j < hi; j++)
        if (a[j] <= pivot) swap(&a[++i], &a[j]);
    swap(&a[i + 1], &a[hi]);
    return i + 1;
}
void quick_sort(int a[], int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quick_sort(a, lo, p - 1);
        quick_sort(a, p + 1, hi);
    }
}

void heapify(int a[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) { swap(&a[i], &a[largest]); heapify(a, n, largest); }
}
void heap_sort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) { swap(&a[0], &a[i]); heapify(a, i, 0); }
}

int main(void) {
    int orig[] = {42, 17, 8, 99, 23, 5, 61};
    int n = 7, a[7];

    memcpy(a, orig, sizeof(orig)); insertion_sort(a, n); print_arr("Insertion Sort", a, n);
    memcpy(a, orig, sizeof(orig)); bubble_sort(a, n);    print_arr("Bubble Sort", a, n);
    memcpy(a, orig, sizeof(orig)); quick_sort(a, 0, n-1);print_arr("Quick Sort", a, n);
    memcpy(a, orig, sizeof(orig)); heap_sort(a, n);      print_arr("Heap Sort", a, n);
    return 0;
}
