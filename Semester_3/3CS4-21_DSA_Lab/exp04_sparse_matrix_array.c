/* Exp 4: Sparse Matrix Representation, Addition, and Transpose using Array */
#include <stdio.h>

typedef struct {
    int r, c, val;
} Triplet;

void print_sparse(Triplet s[], int n) {
    printf("Row Col Val\n");
    for (int i = 0; i <= n; i++)
        printf("%3d %3d %3d\n", s[i].r, s[i].c, s[i].val);
}

void transpose(Triplet a[], Triplet t[]) {
    int n = a[0].val;
    t[0].r = a[0].c; t[0].c = a[0].r; t[0].val = n;
    int k = 1;
    for (int col = 0; col < a[0].c; col++) {
        for (int i = 1; i <= n; i++) {
            if (a[i].c == col) {
                t[k].r = a[i].c;
                t[k].c = a[i].r;
                t[k].val = a[i].val;
                k++;
            }
        }
    }
}

void add_sparse(Triplet a[], Triplet b[], Triplet res[]) {
    int i = 1, j = 1, k = 1;
    res[0].r = a[0].r; res[0].c = a[0].c;
    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].r < b[j].r || (a[i].r == b[j].r && a[i].c < b[j].c)) res[k++] = a[i++];
        else if (b[j].r < a[i].r || (b[j].r == a[i].r && b[j].c < a[i].c)) res[k++] = b[j++];
        else {
            int sum = a[i].val + b[j].val;
            if (sum != 0) { res[k] = a[i]; res[k++].val = sum; }
            i++; j++;
        }
    }
    while (i <= a[0].val) res[k++] = a[i++];
    while (j <= b[0].val) res[k++] = b[j++];
    res[0].val = k - 1;
}

int main(void) {
    Triplet A[10] = {{3, 3, 3}, {0, 1, 5}, {1, 2, 8}, {2, 0, 3}};
    Triplet B[10] = {{3, 3, 2}, {0, 1, 4}, {2, 2, 6}};
    Triplet Sum[20], Trans[10];

    add_sparse(A, B, Sum);
    printf("A + B:\n"); print_sparse(Sum, Sum[0].val);

    transpose(A, Trans);
    printf("\nTranspose of A:\n"); print_sparse(Trans, Trans[0].val);
    return 0;
}
