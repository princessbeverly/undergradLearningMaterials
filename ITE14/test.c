//PRINCESS BEVERLY R. ALA-AN
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void display(struct node*);
void makelist(struct node **, struct node**, struct node**);
void removenode(struct node**, int);
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

    printf("\nLinked List:");
    display(head);
    int myNumbers[] = {1, 5, 13, 20, 30};

    int size = sizeof(myNumbers) / sizeof(myNumbers[0]);
    for(int i = 0; i < size; i++){
        int c = myNumbers[i];
        removenode(&head, c);
    }
    printf("\nLinked Lists without Removed Values:");
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


void removenode(struct node** head, int value) {

    struct node* temp = *head, *prev;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}


