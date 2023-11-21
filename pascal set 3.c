#include <stdio.h>
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}
void printPascalTriangle(int rows) {
    for (int i = 0; i < rows; i++) {
        // Adjust spacing for better visualization
        for (int space = 0; space < rows - i - 1; space++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoefficient(i, j));
        }
        printf("\n");
    }
}

int main() {
    int rows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    printPascalTriangle(rows);

    return 0;
}
