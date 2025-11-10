#include <stdio.h>

#define MAX 30


struct Edge {
    int u, v, w; 
} edge[MAX];

int parent[MAX];


int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}


void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, e;
    int i, j;
    int totalCost = 0;
    struct Edge temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }

    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - 1 - i; j++) {
            if (edge[j].w > edge[j + 1].w) {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }

   
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < e; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;

        if (find(u) != find(v)) {
            union_set(u, v);
            printf("%d -- %d = %d\n", u, v, w);
            totalCost += w;
        }
    }

    printf("\nTotal cost of MST = %d\n", totalCost);

    return 0;
}