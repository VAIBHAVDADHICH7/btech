/* Exp 7: (a) BFS Reachability & (b) DFS Connectivity Check */
#include <stdio.h>
#define V 4

int g[V][V] = {{0,1,1,0},{1,0,0,1},{1,0,0,1},{0,1,1,0}};

void dfs(int u, int vis[]) {
    vis[u] = 1;
    for (int v = 0; v < V; v++) if (g[u][v] && !vis[v]) dfs(v, vis);
}

int main(void) {
    int vis[V] = {0}, q[V], f = 0, r = 0;
    vis[0] = 1; q[r++] = 0;
    printf("Reachable from 0 (BFS): ");
    while (f < r) {
        int u = q[f++]; printf("%d ", u);
        for (int v = 0; v < V; v++) if (g[u][v] && !vis[v]) { vis[v] = 1; q[r++] = v; }
    }
    int dvis[V] = {0}, conn = 1;
    dfs(0, dvis);
    for (int i = 0; i < V; i++) if (!dvis[i]) conn = 0;
    printf("\nGraph is %s\n", conn ? "CONNECTED" : "DISCONNECTED");
    return 0;
}
