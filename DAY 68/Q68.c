#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int graph[100][100], indegree[100] = {0};
    int queue[100], front = 0, rear = 0;

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    // Add vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    // Kahn's Algorithm
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {
                indegree[v]--;

                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    return 0;
}
