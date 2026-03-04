Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, val, key;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) head = temp = newNode;
        else { temp->next = newNode; temp = newNode; }
    }

    // Read key to count
    scanf("%d", &key);

    // Count occurrences
    int count = 0;
    temp = head;
    while(temp != NULL) {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }

    printf("%d\n", count);

    return 0;
}
