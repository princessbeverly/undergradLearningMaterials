#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1000   // enough space for 200th Fibonacci (about 42 digits)
#define TERMS 200         // how many terms to compute

// A function to add two big integers represented as arrays of digits
void addBigIntegers(int result[], int a[], int b[]) {
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
}

// A function to print a big integer (array of digits)
void printBigInteger(int num[]) {
    int i;
    for (i = MAX_DIGITS - 1; i >= 0; i--) {
        if (num[i] != 0) break; // skip leading zeros
    }
    if (i < 0) {
        printf("0");
    } else {
        for (; i >= 0; i--) {
            printf("%d", num[i]);
        }
    }
    printf("\n");
}

int main() {
    // Each Fibonacci number is stored as an array of digits
    int fib[TERMS][MAX_DIGITS] = {0};

    // Initialize first two Fibonacci numbers
    fib[0][0] = 0;  // F(0) = 0
    fib[1][0] = 1;  // F(1) = 1

    // Generate Fibonacci sequence
    for (int i = 2; i < TERMS; i++) {
        addBigIntegers(fib[i], fib[i-1], fib[i-2]);
    }

    // Print Fibonacci numbers
    for (int i = 0; i < TERMS; i++) {
        printf("F(%d) = ", i);
        printBigInteger(fib[i]);
    }

    return 0;
}
