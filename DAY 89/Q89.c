#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages
        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }

        if (students > m)
            return 0;
    }
    return 1;
}

// Function to find minimum possible maximum pages
int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1; // not possible

    int sum = 0, max = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int left = max, right = sum, ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1; // try smaller value
        } else {
            left = mid + 1;  // increase limit
        }
    }

    return ans;
}

int main() {
    int n, m;
    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int arr[n];
    printf("Enter pages in each book: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = allocateBooks(arr, n, m);

    if (result == -1)
        printf("Allocation not possible\n");
    else
        printf("Minimum maximum pages: %d\n", result);

    return 0;
}
