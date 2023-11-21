#include <stdio.h>
#include <time.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i; // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int n, key;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Input the key to search
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Record the start time
    clock_t start_time = clock();

    // Perform linear search
    int index = linearSearch(arr, n, key);

    // Record the end time
    clock_t end_time = clock();

    // Calculate the elapsed time
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    if (index != -1) {
        printf("Key found at index %d\n", index);
    } else {
        printf("Key not found in the array\n");
    }

    printf("Time taken: %f seconds\n", elapsed_time);

    return 0;
}
