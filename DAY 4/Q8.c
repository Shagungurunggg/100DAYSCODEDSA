Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
#include <stdio.h>

int main() {
    int n, val;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &val);

    int k = 0;  

    for(int i = 0; i < n; i++) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    printf("%d\n", k);

    for(int i = 0; i < k; i++)
        printf("%d ", nums[i]);

    return 0;
}
