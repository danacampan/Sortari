#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n, int *compCount) {
    int i, j, temp;
    *compCount = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*compCount)++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[2000];
    int i, n, compCount;

    srand(time(NULL));
    n = sizeof(arr) / sizeof(arr[0]);

    // initialize the array with random numbers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // start the timer

    // sort the array
    bubbleSort(arr, n, &compCount);

    clock_gettime(CLOCK_MONOTONIC, &end); // stop the timer
    double time_spent = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;

    // print the sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %.3f milliseconds", time_spent);
    printf("\nNumber of comparisons: %d", compCount);

    return 0;
}
