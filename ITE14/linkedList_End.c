
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(){

    struct node *head, *newnode, *temp;
    head = NULL;
    int choice = 1;

    while(choice != 0){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL){
            head = temp = newnode;
        }else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nDo you want to enter more data?(1/0): ");
        scanf("%d", &choice);
    }

    temp = head; // Reset temp to the head of the list

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    //INSERT AT END
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data You want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
        temp->next = newnode;

    //DISPLAY
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
