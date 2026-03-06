Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
  #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top){
    if(*top == NULL){
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main(){
    char token[100];
    struct Node* stack = NULL;

    while(scanf("%s", token) != EOF){
        if(isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))){  // handle negative numbers
            push(&stack, atoi(token));
        }
        else{  // operator
            int b = pop(&stack);
            int a = pop(&stack);
            switch(token[0]){
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': push(&stack, a / b); break;
            }
        }
    }

    // Result is on top of stack
    printf("%d\n", pop(&stack));
    return 0;
}
