#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void display(struct node*);
void makelist(struct node **, struct node**, struct node**);
int search(int, struct node *, int);
void maindelete();
int main(){

    struct node *newnode, *head, *temp;
    struct node *saizu;
    head = NULL;
    int j = 5, product = 1;
    for(int i = 1; i <= 5; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        product = j*i;
        newnode->data = product;
        makelist(&newnode, &head, &temp);
    }
    display(head);
    int myNumbers[] = {1, 5, 8, 20};
    int size = sizeof(myNumbers)/sizeof(myNumbers[0]);
    int data = 0, datacompared = 0, position[size];
    temp = head;
    for(int i = 1; i <= size; i++){
        int position = myNumbers[i];
            //position = search(size, head, data);
        maindelete(position, &head, &temp);
        display(head);
    }
    printf("Printing New Linked List:\n");
    display(head);

}

void makelist(struct node **newnode, struct node **head, struct node **temp){
    (*newnode)->next = NULL;

    if(*head == NULL){
        *head = *temp = *newnode;
    }else{
        (*temp)->next = *newnode;
        *temp = *newnode;
    }
}

void display(struct node *head){
    printf("\n");
    int count = 0;
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\n");
}



void maindelete(int position, struct node **head, struct node **temp){
    int i = 1;
    struct node *nextnode = (struct node*)malloc(sizeof(struct node));
    if(position == 1){
        *temp = *head;
        *head = (*head)->next;
        free(*temp);

    }else if(position != 1){
        *temp = *head;
        while(i < position-1){
            *temp = (*temp)->next;
            i++;
        }
        nextnode = (*temp)->next;
        (*temp)->next = (nextnode)->next;
        free(nextnode);
    }

}


