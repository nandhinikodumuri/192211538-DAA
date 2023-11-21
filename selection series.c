#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main() {
    int n;
    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Filling the array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 and 999
    }

    printf("\nArray before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    start = clock(); // Start measuring time

    selectionSort(arr, n);

    end = clock(); // End measuring time

    printf("\n\nArray after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTime taken to perform selection sort: %f seconds\n", time_taken);

    return 0;
}
