#include <stdio.h>

void findMinMax(int arr[], int size, int m, int n, int *mthMax, int *nthMin) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    *mthMax = arr[size - m];
    *nthMin = arr[n - 1];
}

int main() {
    int size, m, n;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of M: ");
    scanf("%d", &m);
    printf("Enter the value of N: ");
    scanf("%d", &n);

    int mthMax, nthMin;
    findMinMax(arr, size, m, n, &mthMax, &nthMin);
    int sum = mthMax + nthMin;
    int diff = mthMax - nthMin;
    printf("M-th maximum: %d\n", mthMax);
    printf("N-th minimum: %d\n", nthMin);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);

    return 0;
}
