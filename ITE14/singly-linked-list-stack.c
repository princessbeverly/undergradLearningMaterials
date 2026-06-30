#include<stdio.h>
#include<stdlib.h>

/*
        red - 255 0 0
        green - 0 255 0
        blue - 0 0 255

        1. ask user how many colors to input.
        2. after stacking
        3. sort it by red, green, green and blue
        4. the stacking should be empty after sorting it to red, blue, green


        struct node {
            int red;
            int green;
            int blue;
            struct node *next;
        }

        do not remove the double pointer but you can add more parameters
    */

struct Node
{
    int data;
    int red;
    int green;
    int blue;
    struct Node *next;
};

//print the linked list
void display(struct Node **head)
{
    struct Node *temp = *head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

void displayRed(struct Node **head)
{
    struct Node *temp = *head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->red);
         temp = temp->next;
    }
    printf("NULL\n");
}

void displayBlue(struct Node **head)
{
    struct Node *temp = *head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->blue);
         temp = temp->next;
    }
    printf("NULL\n");
}

void displayGreen(struct Node **head)
{
    struct Node *temp = *head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->green);
         temp = temp->next;
    }
    printf("NULL\n");
}

void pop(struct Node **head)
{
    //temp is used to free the head node
    struct Node *temp;

    if(*head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", (*head)->data);

        //backup the head node
        temp = *head;

        //make the head node points to the next node.
        //logically removing the node
        *head = (*head)->next;

        //free the poped element's memory
        free(temp);
    }
}

void push(int val, struct Node **head)  //struct Node **head = &head    //struct Node *head
{
    //create new node
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    //make the new node points to the head node
    newNode->next = *head;

    //make the new node as head node
    //so that head will always point the last inserted data
    *head = newNode;
}

void pushRed(int val, struct Node **head){
    //create new node
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->red = val;

    //make the new node points to the head node
    newNode->next = *head;

    //make the new node as head node
    //so that head will always point the last inserted data
    *head = newNode;
}

void pushGreen(int val, struct Node **head){
    //create new node
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->green = val;

    //make the new node points to the head node
    newNode->next = *head;

    //make the new node as head node
    //so that head will always point the last inserted data
    *head = newNode;
}

void pushBlue(int val, struct Node **head){
    //create new node
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->blue = val;

    //make the new node points to the head node
    newNode->next = *head;

    //make the new node as head node
    //so that head will always point the last inserted data
    *head = newNode;
}


void sortingColors(struct Node **head) {
    struct Node *temp = *head;
    struct Node *slide = NULL; // Unused variable slide removed
    // Iterate the entire linked list
    while (temp != NULL) {
        if (temp->next != NULL && temp->next->next != NULL) {
            int red = temp->data;
            int green = temp->next->data;
            int blue = temp->next->next->data;
            if (red == 0 && green == 0 && blue == 255) {
                // Call pushGreen appropriately
                pushGreen(red, head);
                pushGreen(green, head);
                pushGreen(blue, head);
                pop(head);
                pop(head);
                pop(head);
            }
            if (red == 255 && green == 0 && blue == 0) {
                // Call pushRed appropriately
                pushRed(red, head);
                pushRed(green, head);
                pushRed(blue, head);
                pop(head);
                pop(head);
                pop(head);
            }
            if (red == 0 && green == 255 && blue == 0) {
                // Call pushBlue appropriately
                pushBlue(red, head);
                pushBlue(green, head);
                pushBlue(blue, head);
                pop(head);
                pop(head);
                pop(head);
            }
        }
        temp = temp->next;
    }
}


int main()
{
    struct node *head = NULL;
    int count = 0;

    printf("How many colors to input? ");
    scanf("%d", &count);

    for(int i = 0; i < count; i++){
        int red, green, blue;
        printf("Enter color: ");
        scanf("%d %d %d", &red, &green, &blue);
        push(red, &head);
        push(green, &head);
        push(blue, &head);
    }

    display(&head);

    sortingColors(&head);

    printf("Sorted Blue: ");
    displayBlue(&head);
    printf("Sorted Green: ");
    displayGreen(&head);
    printf("Sorted Red: ");
    displayRed(&head);

    return 0;
}
