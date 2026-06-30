// ALA-AN, PRINCESS BEVERLY
// BNO1
// MACHINE PROBLEM 1

/*
Input: Prompt the user to enter a binary string

Processing: Simulate each DFA transition based on the provided regular expression until the end of the string is reached.

Output: Display one of the following:

"Accepted Input String" - if the string ends in an accepting state
"Not Accepted Input String" - if the string ends in a non-accepting stage
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int state1(char*);
int state2(char*);
int binarychecker(char *);

int main() {
    char user[100];
    char choice;

    while (1) {  // infinite loop, break when user decides to stop
        printf("Input Binary String: ");
        scanf("%s", user);

        // checking user input
        if (binarychecker(user) == 0) {
            printf("\nInvalid user input!\n");
        } else {
            // user input passed!
            int string = state1(user);

            // checking if the string is accepted or not
            if (string == 1) {
                printf("Accepted Input String\n");
            } else {
                printf("Not Accepted Input String\n");
            }
        }

        // ask if the user wants to try again
        printf("\nDo you want to try again? (y/n): ");
        scanf(" %c", &choice);  // putting space before %c to clear newline

        if (choice == 'n' || choice == 'N') {
            printf("Exiting program...\n");
            break;  // exit while loop
        }
    }

    return 0;
}


//Checking User Input through this function
int binarychecker(char *num){

    //checking user input

    int i = 0;

    // loops through the entire string
    while(num[i] != '\0'){
        char c = num[i];

        // checks if the character is an integer
        if(isdigit(c)){

            if(c == '0' || c == '1'){
                // if it's a binary number it continues with the loop
            }else{
                // if not binary number, it returns 0
                return 0;
            }
        }else{
            // if the character is not an integer it returns 0
            return 0;
        }
        i++;
    }

    // if all the characters are binary numbers
    return 1;
}
int state1(char* num){
    //Entering First State

    int i = 0;
    int capacity = strlen(num);
    char nextState[capacity];
    int validity = 0;

    for(i = 0; i < strlen(num); i++){
        if(num[i] == '1'){
            // character is still in 1st state
            // validity stays 0
            validity = 0;
        }else if(num[i]=='0'){
            // delivering the rest of the string to the next state
            strncpy(nextState, num + i, sizeof(nextState) - 1);
            nextState[sizeof(nextState) -1 ] = '\0';

            // checks if it qualifies to the next state after state 2
            validity = state2(nextState);

            //breaks the loop
            break;
        }
    }

    // checks the validity returned from state 2
    if(validity == 1){
        // returns to main; it reaches final state
        return 1;
    }else{
        // returns to main; it did not reach final state
        return 0;
    }
}
int state2(char* fromState1){
    //entering second state with the remaining string to check

    int i = 0;


    for(i = 0; i < strlen(fromState1); i++){
        char c = fromState1[i];
        if(c == '0'){
            // character stays in state 2
            //printf("%c = in 2nd state\n", c);
        }else if(c == '1'){
            // this means that it reaches the final state
            // returns 1 back to state 1 confirming that the string reaches third state
            return 1;
        }
    }

    return 0;
}
