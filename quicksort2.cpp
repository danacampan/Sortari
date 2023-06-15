#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++) {
        (*comparisons)++; // count the comparison

        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    int arr[10000];
    int i, n;

    srand(time(NULL));
    n = sizeof(arr) / sizeof(arr[0]);

    // initialize the array with random numbers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    int comparisons = 0;

    clock_t start = clock(); // start the timer

    // sort the array
    quickSort(arr, 0, n - 1, &comparisons);

    clock_t end = clock(); // stop the timer
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // print the sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of comparisons: %d", comparisons);
    printf("\nTime taken: %f seconds", time_spent);

    return 0;
}
