/*
* A queue in C is basically a linear data structure to store and manipulate the data elements.
* It follows the order of First In First Out (FIFO).

* In queues, the first element entered is the first element to be removed.

* A queue is open at both ends. One end is provided for the insertion of data (Rear)
* and the other end for the deletion of data (Front).

*/
#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node {
    int data;
    int prioritynum;
    struct node * next;
};

// Enqueue() operation on a queue
void enqueue(struct node **front, struct node **back, int num){

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prioritynum = num;
    newnode->data = num;
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
            while(temp->next!= NULL && temp->next->prioritynum > newnode->data){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}
 

// Dequeue() operation on a queue
int dequeue(struct node **front) {
    if (*front == NULL) {
        printf("\nQueue is Empty\n");
        return -1;
    } else {
        struct node * temp = *front;
        int temp_data = (*front) -> data;
        *front = (*front) -> next;
        free(temp);
        return temp_data;
    }
}

// Display all elements of the queue
void display(struct node **front, struct node **rear) {
    struct node * temp;
    if ((*front == NULL) && (*rear == NULL)) {
        printf("\nQueue is Empty\n");
    } else {
        printf("The queue is \n");
        printf("(Front)  ");
        temp = *front;
        while (temp != NULL) {
            printf("%d---", temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n\n");
        printf("  (Rear)");
    }
}

int isFull(struct node** front, struct node **rear) {
    struct node *temp = *front;
    int count = 0;
    if((*front == NULL) && (*rear == NULL)) {
        return 0;
    }else{
        while (temp != NULL && count != 5) {
            printf("%d---", temp -> data);
            temp = temp -> next;
            count++;
        }

    }

    if(count == 5){
        return 1;
    }else{
        return 0;
    }

}

int getFront(struct node **front){
    return (*front)->data;
}

int getRear(struct node **rear){
    return (*rear)->data;
}





int main() {
    struct node * front = NULL;
    struct node * rear = NULL;
    int choice, value, full,front_value, rear_value;
    printf("\nImplementation of Queue using Linked List\n");
    while (choice != 4) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Check if Full\n5.Get Front\n6.Get Rear\n7.Priority Number\n8.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                printf("Popped element is :%d\n", dequeue(&front));
                break;
            case 3:
                display(&front, &rear);
                break;
            case 4:
                full = isFull(&front, &rear);
                if(full == 0){
                    printf("Queue is not full");
                }else{
                    printf("Queue is full");
                }
                break;
            case 5:
                front_value = getFront(&front);
                printf("The front element is : %d", front_value);
                break;
            case 6:
                rear_value = getRear(&rear);
                printf("The rear element is: %d", rear_value);
                break;
            case 7:
                printf("Exiting...");
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}
