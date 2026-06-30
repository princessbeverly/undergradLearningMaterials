#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
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

int main()
{
    /*
    int a, *b, **c, ***d;
    a = 5;
    b = &a;
    c = &b;
    d = &c */

    struct Node *head = NULL;
    push(3, &head);
    push(7, &head);
    push(8, &head);
    push(12, &head);
    push(17, &head);
    push(23, &head);

    printf("\nLinked List\n");
    display(&head);

    pop(&head);
    printf("After the pop, the new linked list\n");
    display(&head);

    pop(&head);
    printf("After the pop, the new linked list\n");
    display(&head);

    return 0;
}
