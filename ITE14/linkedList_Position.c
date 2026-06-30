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

    int pos = 0, i = 1, count = 0;
    temp = head; // Reset temp to the head of the list
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }

    //INSERT AT POSITION
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position: ");
    scanf("%d", &pos);

    if(pos > count ){
        printf("Invalid Position");
    }else{
        temp = head;
        while(i < pos){
            temp = temp->next;
            i++;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    //Display
    temp = head; // Reset temp to the head of the list
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;

    }


    return 0;
}

