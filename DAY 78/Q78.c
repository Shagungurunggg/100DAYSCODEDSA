#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph with large values
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int visited[MAX] = {0};
    int minEdge[MAX];
    int totalWeight = 0;

    // Initialize all keys as infinite
    for (int i = 1; i <= n; i++) {
        minEdge[i] = INT_MAX;
    }

    // Start from node 1
    minEdge[1] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;

        // Pick minimum key vertex not yet visited
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || minEdge[j] < minEdge[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalWeight += minEdge[u];

        // Update adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < minEdge[v]) {
                minEdge[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}
