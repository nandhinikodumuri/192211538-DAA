#include <stdio.h>
#include <math.h>

// Function to check if a number is an Armstrong number
int isArmstrong(int N) {
    int originalNumber = N;
    int numDigits = 0;
    int sum = 0;

    // Count the number of digits in the given number
    while (N != 0) {
        N /= 10;
        numDigits++;
    }

    N = originalNumber; // Reset N to its original value

    // Calculate the sum of k-th power of each digit
    while (N != 0) {
        int digit = N % 10;
        sum += pow(digit, numDigits);
        N /= 10;
    }

    // Check if the sum is equal to the original number
    return (sum == originalNumber);
}

int main() {
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);

    if (isArmstrong(N)) {
        printf("%d is an Armstrong number.\n", N);
    } else {
        printf("%d is not an Armstrong number.\n", N);
    }

    return 0;
}
