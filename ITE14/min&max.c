#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void push(struct node **top, int val){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node)); // corrected assignment operator
    temp->link = NULL;
    temp->data = val;
    if(*top == NULL){
        *top = temp;
    }else{
        temp->link = *top;
        *top = temp;
    }
}

void pop(struct node **top){
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp;
    temp = *top;
    *top = (*top)->link;
    free(temp);
}

void minfind(struct node **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = *top;
    int min_value = temp->data;
    while (temp != NULL) {
        if (temp->data < min_value) {
            min_value = temp->data;
        }
        temp = temp->link;
    }
    printf("Minimum value in the stack: %d\n", min_value);
}

void maxfind(struct node **top){
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = *top;
    int max_value = temp->data; // corrected variable name
    while (temp != NULL) {
        if (temp->data > max_value) { // corrected comparison
            max_value = temp->data;
        }
        temp = temp->link;
    }
    printf("Maximum value in the stack: %d\n", max_value); // corrected print message
}

int main(){
    struct node *top = NULL;

    push(&top, 10); // corrected function call
    push(&top, 7);  // corrected function call
    push(&top, 8);  // corrected function call
    push(&top, 3);  // corrected function call
    push(&top, 17); // corrected function call
    push(&top, 23); // corrected function call

    minfind(&top); // corrected function call
    maxfind(&top); // corrected function call

    return 0;
}
