You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
#include <stdio.h>

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    int nums1[m + n], nums2[n];

    // Input nums1 (first m elements, rest 0)
    for(int i = 0; i < m + n; i++)
        scanf("%d", &nums1[i]);

    // Input nums2
    for(int i = 0; i < n; i++)
        scanf("%d", &nums2[i]);

    int i = m - 1;        // last element of nums1
    int j = n - 1;        // last element of nums2
    int k = m + n - 1;    // last position of merged array

    // Merge from back
    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }

    // Copy remaining nums2 (if any)
    while(j >= 0)
        nums1[k--] = nums2[j--];

    // Print merged array
    for(int x = 0; x < m + n; x++)
        printf("%d ", nums1[x]);

    return 0;
}
