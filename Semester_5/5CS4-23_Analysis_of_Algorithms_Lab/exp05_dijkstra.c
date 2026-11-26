/* Exp 5: Dijkstra's Single-Source Shortest Paths */
#include <stdio.h>
#define V 5
#define INF 99999

int main(void) {
    int g[V][V] = {
        {0,10,0,30,100}, {10,0,50,0,0}, {0,50,0,20,10}, {30,0,20,0,60}, {100,0,10,60,0}
    };
    int dist[V], vis[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[0] = 0;

    for (int c = 0; c < V - 1; c++) {
        int u = -1;
        for (int i = 0; i < V; i++) if (!vis[i] && (u == -1 || dist[i] < dist[u])) u = i;
        vis[u] = 1;
        for (int v = 0; v < V; v++)
            if (!vis[v] && g[u][v] && dist[u] + g[u][v] < dist[v]) dist[v] = dist[u] + g[u][v];
    }
    for (int i = 0; i < V; i++) printf("Shortest dist 0 -> %d = %d\n", i, dist[i]);
    return 0;
}
