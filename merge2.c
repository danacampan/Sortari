#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r, long long *compCount) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // create temporary arrays
    int L[n1], R[n2];

    // copy data to temporary arrays
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // merge the temporary arrays back into arr[l..r]
    i = 0; // index of first subarray
    j = 0; // index of second subarray
    k = l; // index of merged subarray
    while (i < n1 && j < n2) {
        (*compCount)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy any remaining elements of L[] and R[] back to arr[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, long long *compCount) {
    if (l < r) {
        // find the middle point
        int m = l + (r - l) / 2;

        // recursively sort both halves
        mergeSort(arr, l, m, compCount);
        mergeSort(arr, m + 1, r, compCount);

        // merge the sorted halves
        merge(arr, l, m, r, compCount);
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
        arr[i] = rand() % 10000;
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // start the timer

    // sort the array
    mergeSort(arr, 0, n - 1, &compCount);

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
