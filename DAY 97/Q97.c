#include <stdio.h>
#include <stdlib.h>

// Structure for meeting
typedef struct {
    int start, end;
} Meeting;

// Compare by start time
int compare(const void *a, const void *b) {
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

// Min-heap functions
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

int pop(int heap[], int *size) {
    int val = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return val;
}

// Function to find minimum rooms
int minMeetingRooms(Meeting meetings[], int n) {
    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n]; // min-heap for end times
    int size = 0;

    push(heap, &size, meetings[0].end);

    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= heap[0]) {
            pop(heap, &size); // reuse room
        }
        push(heap, &size, meetings[i].end);
    }

    return size;
}

int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Meeting meetings[n];
    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    printf("Minimum rooms required: %d\n", minMeetingRooms(meetings, n));

    return 0;
}
