#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void makelist(struct node **, struct node**, struct node**);
void display(struct node*);
void deleteStart(struct node **, struct node **);
void deletePos(struct node **, struct node **, struct node**);

int lenght(struct node *);
int main(){

    struct node *newnode, *head, *temp, *prevnode;
    head = NULL;
    int choice = 1;

    while(choice != 0){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        makelist(&newnode, &head, &temp);
        printf("Do you want to add more? ");
        scanf("%d", &choice);
    }

    int j = 5;
    for(int i = 0; i < 5; ){
        j = newnode->data;
        j *= i+1;

    }

    display(head);
    deleteStart(&temp, &head);
    display(head);
    deleteEnd(&temp, &head, &prevnode);
    display(head);

    int position = 0;
    printf("Enter position: ");
    scanf("%d", &position);


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

int length(struct node *head){
    struct node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

void deleteStart(struct node **temp, struct node **head){
    *temp = *head;
    *head = (*head)->next;
    free(*temp);
}

void deleteEnd(struct node **temp, struct node **head, struct node **prevnode){
    //initialize
    *temp = *head;
    //if it's an empty list
    if(*temp == NULL){
        return;
    }
    //if it's one node
    if((*temp)->next == NULL){
        free(*temp);
        *head = NULL;
        return;
    }
    //traverses till the last node
    while((*temp)->next != NULL){
        *prevnode = *temp;
        *temp = (*temp)->next;
    }
    //updates previous node
    (*prevnode)->next = NULL;
    //free last node
    free(*temp);
}

void deletePos(struct node **head, struct node **temp, struct node **prevnode, int position){
    struct node *nextnode;
    *temp = *head;
    int len = lenght(head), i = 1;
    if(position < len){
        return;
    }

    if(position > i){
        (*temp)->next =
    }

}

