Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, val, key;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) head = temp = newNode;
        else { temp->next = newNode; temp = newNode; }
    }

    scanf("%d", &key);

    temp = head;
    struct Node *prev = NULL;

    while(temp != NULL) {
        if(temp->data == key) {
            if(prev == NULL) head = temp->next; // key at head
            else prev->next = temp->next;
            free(temp);
            break; // delete only first occurrence
        }
        prev = temp;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
