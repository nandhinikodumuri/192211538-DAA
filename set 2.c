#include <stdio.h>
#define MAX 100

int set[MAX], subset[MAX];
int n, sum;
int count = 0;

void subsetSum(int index, int currentSum, int remainingSum) {
    if (currentSum == sum) {
        printf("Subset %d: ", ++count);
        for (int i = 0; i < index; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    for (int i = index; i < n; i++) {
        subset[index] = set[i];

        if (currentSum + set[i] <= sum) {
            subsetSum(index + 1, currentSum + set[i], remainingSum - set[i]);
        }
    }
}

void findSubsets() {
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += set[i];
    }

    if (set[0] <= sum && totalSum >= sum) {
        subsetSum(0, 0, totalSum);
    } else {
        printf("No subset found with the given sum.\n");
    }
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the desired sum: ");
    scanf("%d", &sum);

    findSubsets();

    return 0;
}
