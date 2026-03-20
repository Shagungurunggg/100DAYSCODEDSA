Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
  #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i] != '\0') {

        // If operand (digit)
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        }
        // If operator
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            switch (exp[i]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
        i++;
    }

    return pop(&stack);
}

// Main function
int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}
