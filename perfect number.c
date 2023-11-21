#include <stdio.h>

int sum_of_divisors(int num) {
    int sum = 1; // Start with 1 as all numbers are divisible by 1

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) // Avoid counting square root twice
                sum += num / i;
        }
    }

    return sum;
}

void printPerfectNumbers(int n) {
    int count = 0, num = 2; // Start checking from 2, the first perfect number

    while (count < n) {
        int sum = sum_of_divisors(num);
        if (sum == num) {
            printf("%d\n", num);
            count++;
        }
        num++;
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("The first %d perfect numbers are:\n", n);
    printPerfectNumbers(n);

    return 0;
}
