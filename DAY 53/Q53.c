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

// Build tree from level order
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

// Print nodes at given vertical line
void printVertical(struct Node* root, int line, int hd) {
    if (root == NULL) return;

    if (hd == line)
        printf("%d ", root->data);

    printVertical(root->left, line, hd - 1);
    printVertical(root->right, line, hd + 1);
}

// Find min and max horizontal distance
void findMinMax(struct Node* root, int hd, int *min, int *max) {
    if (root == NULL) return;

    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;

    findMinMax(root->left, hd - 1, min, max);
    findMinMax(root->right, hd + 1, min, max);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    int min = 0, max = 0;
    findMinMax(root, 0, &min, &max);

    for (int i = min; i <= max; i++) {
        printVertical(root, i, 0);
        printf("\n");
    }

    return 0;
}
