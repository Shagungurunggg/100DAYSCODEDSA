#include <stdio.h>

int graph[100][100];
int visited[100], recStack[100];
int n;

// DFS cycle detection
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1) {
            if (visited[i] == 0) {
                if (dfs(i))
                    return 1;
            }
            else if (recStack[i] == 1) {
                return 1;
            }
        }
    }

    recStack[v] = 0;
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

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");

    return 0;
}
