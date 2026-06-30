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

    // Display the original linked list
    printf("\nOriginal Linked List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Delete nodes from the end of the linked list
    struct node *prevnode = NULL;
    temp = head;
    while (temp->next != NULL) {
        prevnode = temp;
        temp = temp->next;
    }

    // If there's only one node in the list
    if (prevnode == NULL) {
        free(head);
        head = NULL;
    } else {
        free(prevnode->next);
        prevnode->next = NULL;
    }

    // Display the updated linked list
    printf("\nLinked List after Deleting Nodes from the End:\n");
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Free memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
