#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return -1;

    struct Node* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

// Main function
int main() {
    int N;
    scanf("%d", &N);

    struct Queue* q = createQueue();

    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'e') {   // enqueue
            int x;
            scanf("%d", &x);
            enqueue(q, x);
        } else if (op[0] == 'd') { // dequeue
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}
