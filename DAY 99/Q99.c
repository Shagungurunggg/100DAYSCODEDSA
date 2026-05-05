#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int pos;
    int speed;
} Car;

// Sort by position descending
int compare(const void *a, const void *b) {
    return ((Car *)b)->pos - ((Car *)a)->pos;
}

// Function to find number of fleets
int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > lastTime) {
            fleets++;          // new fleet
            lastTime = time;   // update slowest fleet time
        }
    }

    return fleets;
}

int main() {
    int n, target;
    printf("Enter number of cars and target: ");
    scanf("%d %d", &n, &target);

    int position[n], speed[n];

    printf("Enter positions: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    printf("Enter speeds: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    printf("Number of fleets: %d\n", carFleet(target, position, speed, n));

    return 0;
}
