#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r, long long *compCount) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

   
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
      
        int m = l + (r - l) / 2;

     
        mergeSort(arr, l, m, compCount);
        mergeSort(arr, m + 1, r, compCount);
        merge(arr, l, m, r, compCount);
    }
}

int main() {
    int arr[2000];
    int i, n;
    long long compCount = 0;

    srand(time(NULL));
    n = sizeof(arr) / sizeof(arr[0]);

    
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); 

    // sort the array
    mergeSort(arr, 0, n - 1, &compCount);

    clock_gettime(CLOCK_MONOTONIC, &end); 
    double time_spent = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;

 
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %.3f milliseconds", time_spent);
    printf("\nNumber of comparisons: %lld", compCount);

    return 0;
}
