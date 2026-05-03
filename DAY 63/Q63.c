#include <stdio.h>

int graph[100][100];
int visited[100];
int n;

// DFS using recursion
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main() {
    int s;

    scanf("%d", &n);

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    scanf("%d", &s);

    dfs(s);

    return 0;
}
