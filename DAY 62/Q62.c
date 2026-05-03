#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* newNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add v to u list
        struct Node* temp1 = newNode(v);
        temp1->next = adj[u];
        adj[u] = temp1;

        // Add u to v list (undirected graph)
        struct Node* temp2 = newNode(u);
        temp2->next = adj[v];
        adj[v] = temp2;
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d:", i);

        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
