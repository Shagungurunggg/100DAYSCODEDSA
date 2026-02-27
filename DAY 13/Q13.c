You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.
  #include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int mat[100][100];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while(top <= bottom && left <= right) {
        // Print top row
        for(int i = left; i <= right; i++)
            printf("%d ", mat[top][i]);
        top++;

        // Print right column
        for(int i = top; i <= bottom; i++)
            printf("%d ", mat[i][right]);
        right--;

        if(top <= bottom) {
            // Print bottom row
            for(int i = right; i >= left; i--)
                printf("%d ", mat[bottom][i]);
            bottom--;
        }

        if(left <= right) {
            // Print left column
            for(int i = bottom; i >= top; i--)
                printf("%d ", mat[i][left]);
            left++;
        }
    }

    return 0;
}
