#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void display(struct node*);
void makelist(struct node **, struct node**, struct node**);
int getlen(struct node *);
void reverselist(struct node *);
int main(){

    struct node *newnode, *head, *temp;
    head = NULL;
    int j = 5, product = 1;
    for(int i = 1; i <= 5; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        product = j*i;
        newnode->data = product;
        makelist(&newnode, &head, &temp);
    }

    reverselist(head);
    display(head);
    return 0;
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

int getlen(struct node *head){
    int count = 0;
    struct node * temp = head;
    while(temp!= NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

void reverselist(struct node *head){
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = NULL;
    currentnode = nextnode = head;
    while(nextnode!= NULL){
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
}