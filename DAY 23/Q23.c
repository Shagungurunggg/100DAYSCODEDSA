Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m, val;
    scanf("%d", &n);

    struct Node *list1 = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(list1 == NULL) list1 = temp = newNode;
        else { temp->next = newNode; temp = newNode; }
    }

    scanf("%d", &m);

    struct Node *list2 = NULL;
    temp = NULL;

    for(int i = 0; i < m; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(list2 == NULL) list2 = temp = newNode;
        else { temp->next = newNode; temp = newNode; }
    }

    struct Node *l1 = list1, *l2 = list2;
    struct Node *merged = NULL, *tail = NULL;

    if(l1 == NULL) merged = l2;
    else if(l2 == NULL) merged = l1;
    else {
        if(l1->data < l2->data) { merged = tail = l1; l1 = l1->next; }
        else { merged = tail = l2; l2 = l2->next; }

        while(l1 && l2) {
            if(l1->data < l2->data) { tail->next = l1; tail = l1; l1 = l1->next; }
            else { tail->next = l2; tail = l2; l2 = l2->next; }
        }
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;
    }

    temp = merged;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
