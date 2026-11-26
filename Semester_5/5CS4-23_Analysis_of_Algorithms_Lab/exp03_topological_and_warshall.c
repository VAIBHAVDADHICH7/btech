/* Exp 3: (a) Topological Sort & (b) Warshall's Transitive Closure */
#include <stdio.h>
#define V 4

int main(void) {
    int g[V][V] = {{0,1,1,0},{0,0,0,1},{0,0,0,1},{0,0,0,0}};
    int indeg[V] = {0}, q[V], f = 0, r = 0;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) if (g[i][j]) indeg[j]++;
    for (int i = 0; i < V; i++) if (indeg[i] == 0) q[r++] = i;

    printf("Topological Order: ");
    while (f < r) {
        int u = q[f++]; printf("%d ", u);
        for (int v = 0; v < V; v++) if (g[u][v] && --indeg[v] == 0) q[r++] = v;
    }

    int tc[V][V];
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) tc[i][j] = g[i][j];
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) tc[i][j] = tc[i][j] || (tc[i][k] && tc[k][j]);

    printf("\nWarshall Transitive Closure:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) printf("%d ", tc[i][j]);
        printf("\n");
    }
    return 0;
}
