Given an integer n, return true if it is a power of two. Otherwise, return false An integer n is a power of two, if there exists an integer x such that n == 2x.
#include <stdio.h>

int isPowerOfTwo(int n) {
    if (n == 1)
        return 1;   // true

    if (n <= 0 || n % 2 != 0)
        return 0;   // false

    return isPowerOfTwo(n / 2);
}

int main() {
    int n;
    scanf("%d", &n);

    if (isPowerOfTwo(n))
        printf("true");
    else
        printf("false");

    return 0;
}

