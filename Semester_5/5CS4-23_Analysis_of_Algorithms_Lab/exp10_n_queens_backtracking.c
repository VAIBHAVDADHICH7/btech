/* Exp 10: N-Queens Problem using Backtracking */
#include <stdio.h>
#include <stdlib.h>
#define N 4

int col[N], sols = 0;
int safe(int r, int c) {
    for (int i = 0; i < r; i++)
        if (col[i] == c || abs(col[i] - c) == abs(i - r)) return 0;
    return 1;
}
void solve(int r) {
    if (r == N) {
        printf("Solution %d: ", ++sols);
        for (int i = 0; i < N; i++) printf("(%d,%d) ", i, col[i]);
        printf("\n");
        return;
    }
    for (int c = 0; c < N; c++) if (safe(r, c)) { col[r] = c; solve(r + 1); }
}

int main(void) { solve(0); return 0; }
