#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n, int *compCount) {
    int i, j, minIndex, temp;
    *compCount = 0;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            (*compCount)++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int arr[100000];
    int i, n, compCount;

    srand(time(NULL));
    n = sizeof(arr) / sizeof(arr[0]);

    // initialize the array with random numbers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    clock_t start = clock(); // start the timer

    // sort the array
    selectionSort(arr, n, &compCount);

    clock_t end = clock(); // stop the timer
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // print the sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %f seconds", time_spent);
    printf("\nNumber of comparisons: %d", compCount);

    return 0;
}
