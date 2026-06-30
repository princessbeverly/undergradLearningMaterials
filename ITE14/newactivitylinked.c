#include <stdio.h>
struct node{
    int data;
    struct node *next;
};
void display(struct node*);
void makelist(struct node **, struct node**, struct node**);
void deleteNodeAtPosition(struct node**, int);
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
    int myNumbers[] = {1, 3, 4};

    //getting the size of myNumbers array
    int size = sizeof(myNumbers) / sizeof(myNumbers[0]);
    for(int i = 0; i < size; i++){
        int c = myNumbers[i];
        deleteNodeAtPosition(&head, c);
    }

    search(head, myNumbers);
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


void deleteNodeAtPosition(struct node** head_ref, int position) {
    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // Store head node
    struct node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0) {
        *head_ref = temp->next; // Change head
        free(temp); // Free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct node* next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory
    temp->next = next; // Unlink the deleted node
}


