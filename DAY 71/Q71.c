#include <stdio.h>

int main() {
    int m, n;
    scanf("%d", &m);   // table size
    scanf("%d", &n);   // number of keys

    int table[100];
    
    for (int i = 0; i < m; i++)
        table[i] = -1;

    for (int j = 0; j < n; j++) {
        int key;
        scanf("%d", &key);

        int h = key % m;

        for (int i = 0; i < m; i++) {
            int idx = (h + i * i) % m;

            if (table[idx] == -1) {
                table[idx] = key;
                break;
            }
        }
    }

    // Print hash table
    for (int i = 0; i < m; i++)
        printf("%d ", table[i]);

    return 0;
}
