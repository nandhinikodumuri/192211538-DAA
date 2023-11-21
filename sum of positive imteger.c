#include <stdio.h>

int isPerfectNumber(int n) {
    if (n <= 1) {
        return 0; // Not a perfect number
    }

    int sum = 1; // Start with 1 as all numbers are divisible by 1

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }

    return sum == n; // Returns 1 if it's a perfect number, 0 otherwise
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectNumber(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}
