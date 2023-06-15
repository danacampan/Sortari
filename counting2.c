#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void countingSort(int arr[], int n, int k) {
    int i, j;
    int *count = calloc(k, sizeof(int));
    int *output = malloc(n * sizeof(int));

   
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

   
    for (i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

   
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }


    free(count);
    free(output);
}

int main() {
    int arr[10000];
    int i, n, k;

    srand(time(NULL));
    n = sizeof(arr) / sizeof(arr[0]);
    k = 100; // the maximum element value

    
    for (i = 0; i < n; i++) {
        arr[i] = rand() % k ;
    }

    clock_t start = clock(); // start the timer

    // sort the array
    countingSort(arr, n, k);

    clock_t end = clock(); // stop the timer
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // print the sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %f seconds", time_spent);

    return 0;
}
