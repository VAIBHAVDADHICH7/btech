/* Exp 4: 0/1 Knapsack using Dynamic Programming */
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main(void) {
    int val[] = {60, 100, 120}, wt[] = {10, 20, 30}, n = 3, W = 50;
    int dp[4][51] = {{0}};
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++)
            dp[i][w] = (wt[i-1] <= w) ? max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]) : dp[i-1][w];
    printf("Max 0/1 Knapsack Value = %d\n", dp[n][W]);
    return 0;
}
