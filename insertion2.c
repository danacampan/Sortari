#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n, long long *compCount) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*compCount)++;
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[2000];
    int i, n;
    long long compCount = 0;

    srand(time(NULL));
    n = sizeof(arr) / sizeof(arr[0]);

    // initialize the array with random numbers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // start the timer

    // sort the array
    insertionSort(arr, n, &compCount);

    clock_gettime(CLOCK_MONOTONIC, &end); // stop the timer
    double time_spent = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;

    // print the sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %.3f milliseconds", time_spent);
    printf("\nNumber of comparisons: %lld", compCount);

    return 0;
}
