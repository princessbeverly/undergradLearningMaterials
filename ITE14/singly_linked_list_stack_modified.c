// Earl James Williams Aliñgasa
// ITE 14 - BK1
// Hands-on Task :: Stacks


#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int redValue;
    int greenValue;
    int blueValue;
    struct Node *next;
} Node;


void display(Node** head)
{
    // Checking if the stack is empty
    if (*head == NULL)
    {
        printf("\n:: The stack is empty.\n");
        return;
    }

    // Traversing the stack and displaying the nodes along the way
    Node *traveler = *head;
    printf("\n\t");
    while (traveler != NULL)
    {
        printf("[%d|%d|%d] -> ", traveler->redValue, traveler->greenValue, traveler->blueValue);
        traveler = traveler->next;
    }
    printf("[NULL]\n");

    return;
}


void pop(Node** head)
{
    // Checking if the stack is empty
    if (*head == NULL)
    {
        return;
    }

    // Proceeding to pop if the stack is not empty
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);

    return;
}


void push(Node** head, int redValue, int greenValue, int blueValue) // struct Node **head = &head    //struct Node *head
{
    // Creating a new node
    Node* newNode = (Node*) malloc(sizeof(Node));

    // Validating allocated memory
    if (newNode == NULL)
    {
        printf("\n:: Failed to allocate memory for a new node.");
        printf("\n:::: Exiting program.");
        exit(1);
    }

    // Setting node values
    newNode->redValue = redValue;
    newNode->greenValue = greenValue;
    newNode->blueValue = blueValue;
    newNode->next = NULL;

    // Checking if the stack is empty
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Proceeding if the stack is not empty
    newNode->next = *head;
    *head = newNode;

    return;
}


void free_stack(Node **head)
{
    // Checking if the stack is empty
    if (*head == NULL)
    {
        return;
    }

    // Traversing the stack and freeing nodes along the way
    Node *traveler = *head;
    while (traveler != NULL)
    {
        Node *temp = traveler;
        traveler = traveler->next;
        free(temp);
    }

    return;
}


int isValidInput(int redValue, int greenValue, int blueValue)
{
    if (redValue == 255 && greenValue == 0 && blueValue == 0)
        return 1;
    else if (redValue == 0 && greenValue == 255 && blueValue == 0)
        return 1;
    else if (redValue == 0 && greenValue == 0 && blueValue == 255)
        return 1;
    else
        return 0;
}


int main()
{
    Node* rgbStackHead = NULL;
    Node* redStackHead = NULL;
    Node* greenStackHead = NULL;
    Node* blueStackHead = NULL;

    // Looping program
    while (1)
    {
        // Prompting the user for input
        printf("\n:::: HANDS-ON TASK - STACKS\n");
        printf("\nChoose an option below by entering the corresponding number.");
        printf("\n(1) Push an RGB node onto the stack.");
        printf("\n(2) Pop an RGB node from the stack.");
        printf("\n(3) Display the stacks.");
        printf("\n(Other) Exit the program.\n\n>> ");

        // Getting and processing input
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Push an RGB node

            system("@cls||clear");

            // Prompting user for input
            int red, green, blue;
            printf("\nEnter the red value (0 or 255).\n>> ");
            scanf("%d", &red);
            printf("\nEnter the green value (0 or 255).\n>> ");
            scanf("%d", &green);
            printf("\nEnter the blue value (0 or 255).\n>> ");
            scanf("%d", &blue);

            // Validating input
            while (!isValidInput(red, green, blue))
            {
                printf("\n:: One or more of your values is invalid. Please try again.\n");

                printf("\nEnter the red value (0 or 255).\n>> ");
                scanf("%d", &red);
                printf("\nEnter the green value (0 or 255).\n>> ");
                scanf("%d", &green);
                printf("\nEnter the blue value (0 or 255).\n>> ");
                scanf("%d", &blue);
            }

            push(&rgbStackHead, red, green, blue);
            printf("\n:: [%d|%d|%d] pushed.\n", red, green, blue);

            break;

        case 2: // Pop an RGB node

            // Prompting the user to choose a stack to pop
            system("@cls||clear");
            if (rgbStackHead == NULL)
            {
                printf("\n:: Nothing to pop.\n");
            }
            else
            {
                printf("\n:: [%d|%d|%d] popped.\n", rgbStackHead->redValue, rgbStackHead->greenValue, rgbStackHead->blueValue);

                // Pushing color stacks as needed
                if (red == 255)
                    push(&redStackHead, 255, 0, 0);
                else if (green == 255)
                    push(&greenStackHead, 0, 255, 0);
                else
                    push(&blueStackHead, 0, 0, 255);
            }

            pop(&rgbStackHead);


            printf("\nPopped red nodes:");
            display(&redStackHead);
            printf("Popped green nodes:");
            display(&greenStackHead);
            printf("Popped blue nodes:");
            display(&blueStackHead);

            break;

        case 3: // Display the stacks

            // Displaying stacks
            system("@cls||clear");
            printf("\nCurrent RGB stack:");
            display(&rgbStackHead);

            break;

        default: // Exit the program

            free_stack(&rgbStackHead);
            free_stack(&redStackHead);
            free_stack(&greenStackHead);
            free_stack(&blueStackHead);
            printf("\n:::: Exiting program.\n\n");

            return 0;
        }

        // Waiting for user
        printf("\n:: Press ENTER to return to the main menu.\n");
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }
}
