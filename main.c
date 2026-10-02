#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

double getTime(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    return ts.tv_sec + ts.tv_nsec / 1000000000.0;
}

void sort(int size, int *array) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1; j++) {
            if (array[j+1] < array[j]) {
                swapped = true;
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    bool play = true;
    while (play) {
        int numRange = 0;
        int amount = 0;
        printf("Enter a number range (e.g. 100):\n");
        scanf("%d", &numRange);
        printf("Enter the amount of numbers to sort:\n");
        scanf("%d", &amount);
        int unsorted[amount];
        int attempt[amount];
        int doneSoFar = 0;
        printf("[");
        for (int i = 0; i < amount; i++) {
            unsorted[i] = rand() % numRange;
            if (i != amount - 1) {
                printf("%d, ", unsorted[i]);
            } else {
                printf("%d]", unsorted[i]);
            }
        }
        bool stillAdding = true;
        double start = getTime();
        double avgSum = 0;
        while (stillAdding) {
            double itemStart = getTime();
            int toAdd = 0;
            printf("\nEnter item: ");
            scanf("%d", &toAdd);
            attempt[doneSoFar] = toAdd;
            doneSoFar++;
            avgSum += getTime() - itemStart;
            if (doneSoFar == amount) {
                stillAdding = false;
            }
        }
        double timeTaken = getTime() - start;
        double avgTime = (double)avgSum/amount;
        sort(amount, unsorted);
        int errors = 0;
        for (int i = 0; i < amount; i++) {
            if (attempt[i] != unsorted[i]) {
                errors++;
            }
        }
        double accuracy = 100.0 * (amount - errors) / amount;
        printf("You made %d errors (%f accuracy)\n", errors, accuracy);
        printf("You took %.2f seconds to complete\n", timeTaken);
        printf("Each input took an average of %.2f to complete\n", avgTime);
        int canPlay;
        printf("Continue? (1/0)"); 
        scanf("%d", &canPlay);
        if (canPlay != 1) {
            play = false;
        }
    }
    return 0;
}