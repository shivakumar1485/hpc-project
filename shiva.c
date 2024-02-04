#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
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

void mergeSort(int arr[], int n) {
    int current_size;
    int left_start;

    for (current_size = 1; current_size <= n - 1; current_size = 2 * current_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * current_size) {
            int mid = left_start + current_size - 1;
            int right_end = (left_start + 2 * current_size - 1) < (n - 1) ? (left_start + 2 * current_size - 1) : (n - 1);

            merge(arr, left_start, mid, right_end);
        }
    }
}

int main() {
    int n = 1000000; // One million elements
    int* arr = (int*)malloc(n * sizeof(int));

    // Initialize the array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    // Uncomment the following lines if you want to print the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Perform iterative merge sort
    mergeSort(arr, n);

    // Uncomment the following lines if you want to print the sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr); // Don't forget to free the allocated memory

    return 0;
}
