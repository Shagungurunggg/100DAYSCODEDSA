Given an array of integers, count the frequency of each distinct element and print the result.
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[100], freq[100] = {0};

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Count frequency
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) { // -1 means already counted
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1; // mark as counted
                }
            }
            printf("%d:%d\n", arr[i], count);
        }
    }

    return 0;
}
