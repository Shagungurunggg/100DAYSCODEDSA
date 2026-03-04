Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int val;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to get the length of a linked list
int getLength(struct Node* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection
struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Advance the longer list by difference in lengths
    while(lenA > lenB) { headA = headA->next; lenA--; }
    while(lenB > lenA) { headB = headB->next; lenB--; }

    // Traverse together
    while(headA != NULL && headB != NULL) {
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL; // No intersection
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *temp1 = NULL;
    struct Node *head2 = NULL, *temp2 = NULL;

    // First list
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if(head1 == NULL) head1 = temp1 = newNode;
        else { temp1->next = newNode; temp1 = newNode; }
    }

    // Second list
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if(head2 == NULL) head2 = temp2 = newNode;
        else { temp2->next = newNode; temp2 = newNode; }
    }

    // For testing, we can manually create an intersection by linking last node of list2 to a node in list1.
    // Example: link last node of list2 to the 2nd node of list1
    // Uncomment below for testing intersection:
    // temp2->next = head1->next;

    struct Node* intersect = getIntersectionNode(head1, head2);
    if(intersect) printf("%d\n", intersect->val);
    else printf("No Intersection\n");

    return 0;
}
