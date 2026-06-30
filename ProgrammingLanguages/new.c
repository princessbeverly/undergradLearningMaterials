#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 100000   // enough to hold 200th Fibonacci (42 digits)

/*
#define tells C preprocessor (which runs before compilation) to create a macro,
usually to give a name to a value or piece of code

macro in C is a preprocessor substitution rule created with #define

C pro
*/

// Add two big integers
void addBigIntegers(int result[], int a[], int b[]) {
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
}

// Print big integer
void printBigInteger(int num[]) {
    int i;
    for (i = MAX_DIGITS - 1; i >= 0; i--) {
        if (num[i] != 0){
            break; // skip leading zeros
        }
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
    int a[MAX_DIGITS] = {0}; // F(0)
    int b[MAX_DIGITS] = {0}; // F(1)
    int c[MAX_DIGITS] = {0}; // F(n)

    b[0] = 1; // F(1) = 1

    printf("F(0) = ");
    printBigInteger(a);
    printf("F(1) = ");
    printBigInteger(b);

    for (int i = 2; i <= 20; i++) {
        addBigIntegers(c, a, b);

        printf("F(%d) = ", i);
        printBigInteger(c);

        // Shift arrays: a = b, b = c
        memcpy(a, b, sizeof(a));
        memcpy(b, c, sizeof(b));
    }

    return 0;
}
