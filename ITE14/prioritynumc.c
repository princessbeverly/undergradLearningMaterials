/*
* A queue in C is basically a linear data structure to store and manipulate the data elements.
* It follows the order of First In First Out (FIFO).

* In queues, the first element entered is the first element to be removed.

* A queue is open at both ends. One end is provided for the insertion of data (Rear)
* and the other end for the deletion of data (Front).

*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int prioritynum;
    struct node *next;
};

void enqueue(struct node ** front, int prioritynum, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->prioritynum = prioritynum;
    temp->next = NULL;
    if(*front == NULL){
        *front = temp;
        return;
    }
    struct node *temp2 = *front;
    while(temp2->next!= NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

void dequeue(struct node **front){
    if(*front == NULL){
        return;
    }
    struct node *temp = *front;
    *front = (*front)->next;
    free(temp);
}

void display(struct node *front){
    struct node *temp = front;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *front = NULL;
    enqueue(&front, 1, 10);
    enqueue(&front, 2, 20);
    enqueue(&front, 3, 30);
    enqueue(&front, 4, 40);
    enqueue(&front, 5, 50);
    display(front);
    dequeue(&front);
    dequeue(&front);
}