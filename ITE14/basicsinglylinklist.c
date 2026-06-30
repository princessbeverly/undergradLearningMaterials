#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

void insert(struct node **, int );
void delete(struct node **, int );
void display(struct node **);

int main(){
    struct node *head = NULL;

    int choice = 1, data = 0, node = 0;

    do{
        printf("MENU");
        printf("\n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit\n");
        printf("Choice: "); scanf("%d", &choice);
        data = 0;

        switch(choice){
            case 1:
                printf("Inserting data");
                printf("\n Input: "); scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Delete Node");
                printf("\n Node Number: "); scanf("%d", &node);
                delete(&head, node);
                break;
            case 3:
                printf("\n Displaying...\n");
                display(&head);
                break;
            case 4:
                printf("\n Exiting...\n");
                break;
            default:
                printf("\nInvalid Input\n");
                printf("\n Do it again\n");
                break;
        }
    }while(choice != 4);

    return 0;
}

void insert(struct node **head, int data){

    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
    }else{
        temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(struct node **head){
    struct node *temp = *head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

void delete(struct node **head, int node){
    struct node *temp = *head, *prev;

    int count = 0;
    while(temp!= NULL){

        temp = temp->next;
        count++;
    }
    printf("Count = %d Node = %d ", count, node);

    if(node > count){
        printf("Nonexistent Node");
        return;
    }else{
        count = 0;
        while(temp!=NULL && count != node){
            prev = temp;
            temp = temp->next;
            count++;
        }
        prev->next = temp->next;
        free(temp);
    }
}
