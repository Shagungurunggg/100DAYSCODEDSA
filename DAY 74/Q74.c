#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[100];
    int votes;
};

int main() {
    int n;
    scanf("%d", &n);

    char arr[n][100];
    struct Candidate c[100];
    int count = 0;

    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < count; j++) {
            if (strcmp(arr[i], c[j].name) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            c[found].votes++;
        } else {
            strcpy(c[count].name, arr[i]);
            c[count].votes = 1;
            count++;
        }
    }

    // Find winner
    int maxVotes = c[0].votes;
    char winner[100];
    strcpy(winner, c[0].name);

    for (int i = 1; i < count; i++) {
        if (c[i].votes > maxVotes) {
            maxVotes = c[i].votes;
            strcpy(winner, c[i].name);
        } else if (c[i].votes == maxVotes) {
            if (strcmp(c[i].name, winner) < 0) {
                strcpy(winner, c[i].name);
            }
        }
    }

    printf("%s", winner);

    return 0;
}
