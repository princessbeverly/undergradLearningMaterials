#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to swap nodes x and y in a linked list
void swapNodes(struct Node** head_ref, int x, int y) {
    // If x and y are the same, no need to swap
    if (x == y) return;

    // Search for x and y, keep track of their previous nodes
    struct Node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
    struct Node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not present, return
    if (currX == NULL || currY == NULL) return;

    // If x is not the head of the list, update the previous node's next pointer
    if (prevX != NULL) prevX->next = currY;
    else *head_ref = currY; // Otherwise, update the head

    // If y is not the head of the list, update the previous node's next pointer
    if (prevY != NULL) prevY->next = currX;
    else *head_ref = currX; // Otherwise, update the head

    // Swap the next pointers of the nodes to complete the swap
    struct Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

// Function to insert a new node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Original Linked List:\n");
    printList(head);

    // Swap nodes 4 and 6
    swapNodes(&head, 4, 6);

    printf("\nLinked List after swapping nodes 4 and 6:\n");
    printList(head);

    return 0;
}
