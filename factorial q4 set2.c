#include <stdio.h>

// Function to calculate factorial recursively
unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    unsigned int number;
    printf("Enter a positive integer: ");
    scanf("%u", &number);

    unsigned long long fact = factorial(number);
    printf("Factorial of %u = %llu\n", number, fact);

    return 0;
}
