Given an array of integers, rotate the array to the right by k positions.
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n;  

    int result[n];

    for(int i = 0; i < n; i++) {
        result[(i + k) % n] = arr[i];
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
