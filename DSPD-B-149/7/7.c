#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], visited[MAX], n;


void DFS_recursive(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            DFS_recursive(i);
}


void DFS_stack(int start) {
    int stack[MAX];
    int top = -1;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    stack[++top] = start;
    visited[start] = 1;

    printf("DFS (using stack): ");
    while (top != -1) {
        v = stack[top--];
        printf("%d ", v);

       
        for (i = n - 1; i >= 0; i--) {
            if (adj[v][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}


void BFS(int start) {
    int queue[MAX], front = 0, rear = 0, i;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++)
            if (adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
    }
    printf("\n");
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

   
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("DFS (Recursive): ");
    DFS_recursive(start);
    printf("\n");


    DFS_stack(start);

    BFS(start);

    return 0;
}