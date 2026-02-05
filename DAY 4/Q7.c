Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int l = 0, r = n - 1, temp;

    while(l < r) {
        temp = a[l];
        a[l] = a[r];
        a[r] = temp;

        l++;
        r--;
    }

    // Print reversed array
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

