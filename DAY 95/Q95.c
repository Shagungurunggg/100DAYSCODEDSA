#include <stdio.h>
#include <stdlib.h>

// Insertion sort for each bucket
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    // Create n buckets
    float **buckets = (float **)malloc(n * sizeof(float *));
    int *bucketSize = (int *)calloc(n, sizeof(int));

    // Allocate memory for each bucket
    for (int i = 0; i < n; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = arr[i] * n;
        buckets[idx][bucketSize[idx]++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketSize[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSize);
}

// Print array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter numbers in range [0,1): ");
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
