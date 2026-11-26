/* Exp 7: Sorting (Bubble Sort) and Searching (Linear & Binary Search) */
#include <stdio.h>

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
        }
    }
}

int linear_search(const int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

int binary_search(const int a[], int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main(void) {
    int a[] = {34, 7, 23, 32, 5, 62};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    int key = 23;

    printf("Linear search for %d before sorting: index %d\n", key, linear_search(a, n, key));
    bubble_sort(a, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\nBinary search for %d after sorting: index %d\n", key, binary_search(a, n, key));
    return 0;
}
