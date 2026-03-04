Given an array of integers, count the number of subarrays whose sum is equal to zero
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix = 0;
    int count = 0;

    int freq[20001] = {0};  
    int offset = 10000;  

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(prefix == 0)
            count++;

        if(freq[prefix + offset] > 0)
            count += freq[prefix + offset];

        freq[prefix + offset]++;
    }

    printf("%d\n", count);

    return 0;
}
