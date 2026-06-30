#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void enqueue(struct node **, struct node **, int);
void dequeue(struct node **, struct node **);
void display(struct node **, struct node **);
int main(){
    struct node *front = NULL, *rear = NULL;
    int choice = 1;
    int data = 0;

    while(choice != 0){
        printf("Enter your choice:\n1.Enqueue\n2.Dequeue\n0.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data:\n");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                display(&front, &rear);
                break;
            case 2:
                dequeue(&front, &rear);
                display(&front, &rear);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

void enqueue(struct node **front, struct node **rear, int data){

        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if(*front == NULL && *rear == NULL){
            *front = *rear = newnode;
        }else{
            (*rear)->next = newnode;
            *rear = newnode;
        }

}

void dequeue(struct node **front, struct node **rear){
    struct node *temp = *front;
    if(*front == NULL && *rear == NULL){
        printf("Queue is empty\n");
    }else{
        *front = (*front)->next;
        free(temp);
    }
}

void display(struct node **front, struct node **rear){
    struct node *temp;

    if(*front == NULL && *rear == NULL){
        printf("Queue is empty\n");
    }else{
        temp = *front;
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
