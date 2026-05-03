#include <stdio.h>

int graph[100][100];
int visited[100];
int queue[100];
int n;

// BFS function
void bfs(int s) {
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
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

    bfs(s);

    return 0;
}
