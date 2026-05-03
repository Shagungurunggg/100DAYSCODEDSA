#include <stdio.h>

int main() {
    int n, src;
    scanf("%d", &n);

    int graph[100][100];

    // Input weighted adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    scanf("%d", &src);

    int dist[100], visited[100] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Dijkstra
    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0 &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output shortest distances
    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}
