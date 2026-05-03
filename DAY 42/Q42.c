#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int queue[n], stack[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    int top = -1;

    for (int i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
