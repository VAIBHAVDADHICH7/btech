/* Exp 6: Kruskal's Minimum Cost Spanning Tree */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int u, v, w; } Edge;
int parent[10];
int find(int i) { return parent[i] == i ? i : (parent[i] = find(parent[i])); }
int cmp(const void *a, const void *b) { return ((Edge *)a)->w - ((Edge *)b)->w; }

int main(void) {
    Edge edges[] = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    int E = 5, V = 4, cost = 0;
    for (int i = 0; i < V; i++) parent[i] = i;
    qsort(edges, (size_t)E, sizeof(Edge), cmp);
    printf("Kruskal MST Edges:\n");
    for (int i = 0; i < E; i++) {
        int a = find(edges[i].u), b = find(edges[i].v);
        if (a != b) {
            parent[a] = b; cost += edges[i].w;
            printf("  %d -- %d (w=%d)\n", edges[i].u, edges[i].v, edges[i].w);
        }
    }
    printf("Total MST Cost = %d\n", cost);
    return 0;
}
