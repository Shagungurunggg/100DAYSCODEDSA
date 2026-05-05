#include <stdio.h>

int integerSqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    int left = 1, right = x, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if ((long long)mid * mid == x)
            return mid;

        if ((long long)mid * mid < x) {
            ans = mid;       // possible answer
            left = mid + 1;  // search right
        } else {
            right = mid - 1; // search left
        }
    }

    return ans;
}

int main() {
    int x;
    printf("Enter number: ");
    scanf("%d", &x);

    printf("Integer square root: %d\n", integerSqrt(x));
    return 0;
}
