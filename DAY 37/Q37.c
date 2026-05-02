#include <stdio.h>

int pq[1000];
int size = 0;

void insert(int x) {
    int i = size++;
    
    while (i > 0 && pq[(i - 1) / 2] > x) {
        pq[i] = pq[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    
    pq[i] = x;
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && pq[left] < pq[smallest])
        smallest = left;

    if (right < size && pq[right] < pq[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = pq[i];
        pq[i] = pq[smallest];
        pq[smallest] = temp;
        heapify(smallest);
    }
}

void deleteMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);
    pq[0] = pq[size - 1];
    size--;
    heapify(0);
}

void peek() {
    if (size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main() {
    int N, x;
    char op[10];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {
            deleteMin();
        }
        else if (op[0] == 'p') {
            peek();
        }
    }

    return 0;
}
