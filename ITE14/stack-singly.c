#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node **head);
void pop(struct node **head);
void push(int val, struct node **head);
int main(){
    struct Node *head = NULL;
    push(3, &head);
    push(7, &head);
    push(8, &head);
    push(12, &head);
    push(17, &head);
    push(23, &head);

    printf("\nLinked List\n");
    display(&head);

    sortdesc(&head);
    display(&head);


}

void display(struct node **head){
    struct node *temp = *head;
    while(temp!= NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void pop(struct node **head){
    struct node *temp;

    if(*head == NULL){
        printf("Stack is empty\n");
        return;
    }else{
        printf("Popped element = %d\n", (*head)->data);

        temp = *head;

        *head = (*head)->next;

        free(temp);
    }
}

void push(int val, struct node **head){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = val;
    newnode->next = *head;
    *head = newnode;
}

