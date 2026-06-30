#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *newnode, *temp;
    head = NULL;
    int choice = 1;

    // Create the linked list
    while (choice != 0) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nDo you want to enter more data? (1/0): ");
        scanf("%d", &choice);
    }

    int pos = 0, i = 1;
    // Display the original linked list
    printf("\nOriginal Linked List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    struct node *nextnode;
    // Delete nodes from the end of the linked list
    temp = head;
    printf("Enter Position: ");
    scanf("%d", &pos);

    while(i < pos-1){
        temp = temp->next;
        i++;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}

