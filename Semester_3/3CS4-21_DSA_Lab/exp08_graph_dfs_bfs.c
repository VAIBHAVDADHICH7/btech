/* Exp 8: Graph DFS and BFS using Adjacency Matrix and Adjacency List */
#include <stdio.h>
#include <stdlib.h>
#define V 5

int adjMat[V][V] = {
    {0,1,1,0,0},
    {1,0,0,1,1},
    {1,0,0,0,1},
    {0,1,0,0,0},
    {0,1,1,0,0}
};

void dfs_mat(int u, int vis[]) {
    vis[u] = 1; printf("%d ", u);
    for (int v = 0; v < V; v++)
        if (adjMat[u][v] && !vis[v]) dfs_mat(v, vis);
}

void bfs_mat(int start) {
    int vis[V] = {0}, q[V], f = 0, r = 0;
    vis[start] = 1; q[r++] = start;
    while (f < r) {
        int u = q[f++]; printf("%d ", u);
        for (int v = 0; v < V; v++) {
            if (adjMat[u][v] && !vis[v]) { vis[v] = 1; q[r++] = v; }
        }
    }
}

typedef struct AdjNode { int v; struct AdjNode *next; } AdjNode;
AdjNode *adjList[V];

void add_edge(int u, int v) {
    AdjNode *n = malloc(sizeof(AdjNode)); n->v = v; n->next = adjList[u]; adjList[u] = n;
}

void dfs_list(int u, int vis[]) {
    vis[u] = 1; printf("%d ", u);
    for (AdjNode *p = adjList[u]; p; p = p->next)
        if (!vis[p->v]) dfs_list(p->v, vis);
}

int main(void) {
    int vis1[V] = {0}, vis2[V] = {0};
    printf("DFS (Adj Matrix): "); dfs_mat(0, vis1); printf("\n");
    printf("BFS (Adj Matrix): "); bfs_mat(0); printf("\n");

    for (int i = 0; i < V; i++)
        for (int j = V - 1; j >= 0; j--)
            if (adjMat[i][j]) add_edge(i, j);

    printf("DFS (Adj List)  : "); dfs_list(0, vis2); printf("\n");
    return 0;
}
