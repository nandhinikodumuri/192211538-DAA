#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindromeString(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (right > left) {
        if (tolower(str[left++]) != tolower(str[right--])) {
            return false;
        }
    }
    return true;
}

bool isPalindromeNumber(int num) {
    int reversed = 0;
    int original = num;

    while (num > 0) {
        int remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    return original == reversed;
}

int main() {
    char str[100];
    int num;

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindromeString(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindromeNumber(num)) {
        printf("The number is a palindrome.\n");
    } else {
        printf("The number is not a palindrome.\n");
    }

    return 0;
}
