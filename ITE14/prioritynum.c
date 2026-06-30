//implementing priority queue for enqueue with a data struct int data, int prioritynum, struct node *next

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int prioritynum;
    struct node *next;
};

/*
    the system for priority queue is that the maximum number is the priority number
*/

void enqueue(struct node **front, struct node **back, int num){

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prioritynum = num;
    newnode->next = NULL;
    if(*front == NULL){
        *front = newnode;
        *back = newnode;
    }
    else{
        if(newnode->prioritynum > (*front)->prioritynum){
            newnode->next = *front;
            *front = newnode;
        }
        else{
            struct node *temp = *front;
            while(temp->next!= NULL && temp->next->prioritynum > newnode->prioritynum){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}


void display_node(struct node **front, struct node **back){
    struct node *temp = *front;
    while(temp!= NULL){
        printf("%d ", temp->data->prioritynum);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *front = NULL, *rear = NULL;
    int choice = 0;
    int num;
    while(choice != 3){
        printf("1. Enqueue\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter: ");
        scanf("%d", &choice);

        if(choice == 1){
            printf("Enter data: "); scanf("%d", &num);
                enqueue(&front, &rear, num);
        }else if(choice ==2){
            display_node(&front, &rear);
        }else if(choice == 3){
            return 1;
        }else{
            printf("Invalid");
        }
    }

    return 0;
}

