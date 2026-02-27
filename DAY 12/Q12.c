Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int mat[100][100];

    // Input matrix elements
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    // Check if square matrix
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    // Check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (mat[i][j] != mat[j][i]) {
                printf("Not a Symmetric Matrix\n");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix\n");
    return 0;
}
