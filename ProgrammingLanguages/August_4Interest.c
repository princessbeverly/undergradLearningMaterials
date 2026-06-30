#include <stdio.h>

void main (void)    {

    int principal, year;
    float rate, interest;

    printf("Enter Principal: ");
    scanf("&d", &principal);

    printf("Enter Rate: ");
    scanf("&f", &rate);

    printf("Enter Interest: ");
    scanf("&f", &interest);

    printf("Enter year: ");
    scanf("&d", &year);

    interest = (principal * rate * year)/ 100;
}



