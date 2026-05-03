#include <stdio.h>

int graph[100][100];
int visited[100];
int n;

// DFS cycle detection
int dfs(int v, int parent) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1) {
            if (visited[i] == 0) {
                if (dfs(i, v))
                    return 1;
            }
            else if (i != parent) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    scanf("%d", &n);

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, -1)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
