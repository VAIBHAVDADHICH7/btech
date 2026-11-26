/* Exp 8: Prim's Minimum Cost Spanning Tree */
#include <stdio.h>
#define V 4
#define INF 99999

int main(void) {
    int g[V][V] = {{0,2,0,6},{2,0,3,8},{0,3,0,5},{6,8,5,0}};
    int key[V], mst[V] = {0}, par[V], cost = 0;
    for (int i = 0; i < V; i++) { key[i] = INF; par[i] = -1; }
    key[0] = 0;
    for (int c = 0; c < V; c++) {
        int u = -1;
        for (int i = 0; i < V; i++) if (!mst[i] && (u == -1 || key[i] < key[u])) u = i;
        mst[u] = 1;
        for (int v = 0; v < V; v++)
            if (g[u][v] && !mst[v] && g[u][v] < key[v]) { par[v] = u; key[v] = g[u][v]; }
    }
    for (int i = 1; i < V; i++) {
        printf("Prim Edge: %d -- %d (w=%d)\n", par[i], i, g[i][par[i]]);
        cost += g[i][par[i]];
    }
    printf("Total Prim MST Cost = %d\n", cost);
    return 0;
}
