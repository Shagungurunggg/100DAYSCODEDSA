#include <stdio.h>
#include <stdlib.h>

// Counting Sort function
void countingSort(int arr[], int n) {
    int max = arr[0];

    // Find maximum element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Create frequency array
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Store frequency
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Prefix sum (cumulative count)
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Output array
    int output[n];

    // Build output array (stable: traverse from end)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter non-negative elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
