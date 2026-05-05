#include <stdio.h>

// Check if we can paint within given maxTime
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (time + boards[i] <= maxTime) {
            time += boards[i];
        } else {
            painters++;
            time = boards[i];
        }

        if (painters > k)
            return 0;
    }
    return 1;
}

// Main function
int minTime(int boards[], int n, int k) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += boards[i];
        if (boards[i] > max)
            max = boards[i];
    }

    int left = max, right = sum, ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            right = mid - 1; // try smaller time
        } else {
            left = mid + 1;  // increase time
        }
    }

    return ans;
}

int main() {
    int n, k;
    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];
    printf("Enter board lengths: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &boards[i]);

    printf("Minimum time: %d\n", minTime(boards, n, k));

    return 0;
}
