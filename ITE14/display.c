#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For srand() function

#define N 100
#define NN (2*N+1)

typedef struct{
    unsigned char digit[NN];
}XP;

// Your other functions here...

// Function to generate a random extended precision integer with at most n digits
XP XPrand(int n) {
    XP xp;
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random digits for the integer
    for (i = NN - 1; i >= NN - n; --i) { // Start from the most significant digit
        // Generate a random digit (0-9)
        xp.digit[i] = rand() % 10;
    }

    // Set the remaining digits to 0
    for (; i >= 0; --i) {
        xp.digit[i] = 0;
    }

    return xp;
}



XP XPinitDecimal(const char *str) {
    XP xp;
    int i;

    // Initialize all elements of digit array to 0
    for (i = 0; i < NN; i++) {
        xp.digit[i] = 0;
    }

    // Iterate over the string and convert each character to a digit
    for (i = 0; str[i] != '\0' && i < NN; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            xp.digit[NN - strlen(str) + i] = str[i] - '0'; // Convert character to digit and store
        } else {
            // Handle non-digit characters (optional)
            printf("Invalid character: %c\n", str[i]);
            // Optionally, you might want to handle or ignore non-digit characters differently
        }
    }

    return xp;
}

// XPRand
void XPshowDecimal(XP xp) {
         int i;
            int foundNonZero = 0; // Flag to track if a non-zero digit has been found

            // Print digits
            for (i = 0; i < NN; ++i) {
                if (xp.digit[i] != 0) {
                    foundNonZero = 1; // Set the flag to indicate a non-zero digit has been found
                }

                if (foundNonZero) {
                    printf("%d", xp.digit[i]); // Print the digit
                }
            }

            // If all digits are zero, print a single zero
            if (!foundNonZero) {
                printf("0");
            }

            printf("\n");

}




int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate random values for e and n
    XP e = XPrand(5); // Generate a random integer with at most 10 digits
    XP n = XPrand(5); // Generate a random integer with at most 20 digits

    // Display the generated values
    printf("Random e:\n");
    XPshowDecimal(e);

    printf("Random n:\n");
    XPshowDecimal(n);

    const char *str = "2003",
    exp = "7",
    d = "2563";
    ; // Input string representing a decimal number
    XP M;
    //, e, d, n;

    M = XPinitDecimal(str);
    //e = XPinitDecimal(e);
    //d = XPinitDecimal(d);
    //n = XPinitDecimal()
    //M = XPrsa(M, e, n);
    XPshowDecimal(M);

    return 0;
}
