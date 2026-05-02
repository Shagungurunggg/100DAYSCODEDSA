#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue *q, int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        q->rear->next = q->front;   // circular link
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
    q->rear->next = q->front;
}

void dequeue(struct Queue *q) {
    if (q->front == NULL) return;

    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
        return;
    }

    struct Node *temp = q->front;
    q->front = q->front->next;
    q->rear->next = q->front;
    free(temp);
}

void display(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty");
        return;
    }

    struct Node *temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
}

int main() {
    int n, m, x;
    struct Queue q;
    q.front = q.rear = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    display(&q);

    return 0;
}
