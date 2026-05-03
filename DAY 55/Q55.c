#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order (-1 = NULL)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* q[1000];
    int front = 0, rear = 0, i = 1;

    struct Node* root = newNode(arr[0]);
    q[rear++] = root;

    while (i < n) {
        struct Node* curr = q[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Right view
void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Node* q[1000];
    int front = 0, rear = 0;

    q[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* curr = q[front++];

            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left) q[rear++] = curr->left;
            if (curr->right) q[rear++] = curr->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}
