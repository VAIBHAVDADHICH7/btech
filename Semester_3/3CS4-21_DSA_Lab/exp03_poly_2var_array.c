/* Exp 3: 2-Variable Polynomial Representation & Addition using Array */
#include <stdio.h>

typedef struct {
    int coeff;
    int px;
    int py;
} Term;

int add_poly(Term p1[], int n1, Term p2[], int n2, Term res[]) {
    int k = 0;
    for (int i = 0; i < n1; i++) res[k++] = p1[i];
    for (int j = 0; j < n2; j++) {
        int found = 0;
        for (int i = 0; i < k; i++) {
            if (res[i].px == p2[j].px && res[i].py == p2[j].py) {
                res[i].coeff += p2[j].coeff;
                found = 1;
                break;
            }
        }
        if (!found) res[k++] = p2[j];
    }
    return k;
}

void print_poly(Term p[], int n) {
    for (int i = 0; i < n; i++) {
        if (p[i].coeff == 0) continue;
        printf("%s%dx^%dy^%d", (i > 0 && p[i].coeff > 0) ? " + " : " ", p[i].coeff, p[i].px, p[i].py);
    }
    printf("\n");
}

int main(void) {
    Term p1[] = {{3, 2, 1}, {5, 1, 2}, {2, 0, 0}};
    Term p2[] = {{4, 2, 1}, {-2, 1, 2}, {7, 1, 0}};
    Term res[20];
    int n3 = add_poly(p1, 3, p2, 3, res);
    printf("P1(x,y) ="); print_poly(p1, 3);
    printf("P2(x,y) ="); print_poly(p2, 3);
    printf("Sum     ="); print_poly(res, n3);
    return 0;
}
