#include <stdio.h>

int graph[100][100];
int visited[100];
int stack[100];
int top = -1;
int n;

// DFS for topological sort
void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }

    stack[++top] = v;
}

int main() {
    scanf("%d", &n);

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0)
            dfs(i);
    }

    while (top != -1)
        printf("%d ", stack[top--]);

    return 0;
}
