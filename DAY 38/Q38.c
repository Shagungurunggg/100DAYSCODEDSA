#include <stdio.h>
#define MAX 1000

int deque[MAX];
int front = -1, rear = -1;

/* Check Empty */
int empty() {
    return (front == -1);
}

/* Size */
int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

/* Push Front */
void push_front(int val) {
    if (front == -1) {
        front = rear = MAX / 2;
    } else {
        front--;
    }
    deque[front] = val;
}

/* Push Back */
void push_back(int val) {
    if (rear == -1) {
        front = rear = MAX / 2;
    } else {
        rear++;
    }
    deque[rear] = val;
}

/* Pop Front */
void pop_front() {
    if (empty()) return;
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

/* Pop Back */
void pop_back() {
    if (empty()) return;
    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

/* Front Element */
int get_front() {
    if (empty()) return -1;
    return deque[front];
}

/* Back Element */
int get_back() {
    if (empty()) return -1;
    return deque[rear];
}

/* Clear */
void clear() {
    front = rear = -1;
}

/* Reverse */
void reverse() {
    if (empty()) return;
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

/* Sort */
void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

/* Display */
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();       // 2 5 10 20
    pop_front();
    pop_back();
    display();       // 5 10

    reverse();
    display();       // 10 5

    sort();
    display();       // 5 10

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());
    printf("Size: %d\n", size());

    clear();
    display();

    return 0;
}
