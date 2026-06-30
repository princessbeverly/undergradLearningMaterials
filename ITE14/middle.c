#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

void removenode(struct node **, int);
void insertmiddlenode(struct node **, int, int);

void createlist(struct node **head, int value){
    struct node *temp, *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if(*head == NULL){
        *head = temp = newnode;
    }else{
        temp->next = newnode;
        temp = newnode;
    }
}
int main(){
    struct node *head = NULL;

    return;
}

void removenode(struct node **head, int position){
    // 1
    if(*head == NULL){
        return;
    }
    // 2
    struct node *temp = *head, *prevnode = NULL;

    // 3

    if(position == 0){
        *head = temp->next;
        free(temp);
        return;
    }

    // 4
    for(int i = 0; temp != NULL && i < position - 1; i++){
        prevnode = temp;
        temp = temp->next;
    }

    // 5
    if(temp == NULL || temp->next == NULL){
        return;
    }

    // 6
    struct node *next = temp->next->next;

    // 7 
    free(temp->next);

    // 8

    temp->next = next;
}

void insertmiddlenode(struct node **head, int position, int value){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    if(position > count){
        printf("Invalid Position\n");
        return;
    }else{
        temp = *head;
        for(int i = 0; temp != NULL && i < position - 1; i++){
            temp = temp->next;
        }

        newnode->data = value;
        newnode->next = temp->next;
        temp->next = newnode;
    }

}
