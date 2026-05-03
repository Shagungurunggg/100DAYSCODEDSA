#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int flag = 1;

    // Check Min-Heap property
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left])
            flag = 0;

        if (right < n && arr[i] > arr[right])
            flag = 0;
    }

    if (flag)
        printf("Yes");
    else
        printf("No");

    return 0;
}
