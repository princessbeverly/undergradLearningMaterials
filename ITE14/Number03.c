/*
STACK
Given a linked list with integer values,
find a way to count the items in the linked list
and return the most frequent number.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void count(struct node **);
void push(struct node **, int);
void display(struct node **);
int main(){
    struct node *top = NULL;
    int choice = 1;
    int data = 0;

    while(choice != 0){
        printf("1. Push\n2. Display\n3. Count\n0. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                display(&top);
                break;
            case 3:
                count(&top);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }
    }

return 0;
}

// arguments: top and data
void push(struct node **top, int data){
    // allocate new node
    struct node *newnode = malloc(sizeof(struct node));
    //establish stack
    newnode->data = data;
    newnode->link = *top;
    *top = newnode;
}

void display(struct node **top){
    struct node *temp;
    temp = *top;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

void count(struct node **top){
    struct node *temp;
    temp = *top;
    int count = 0;
    while(temp!= NULL){
        temp = temp->link;
        count++;
    }

    int arr[count];
    int i = 0;
    int data = 0;
    while(temp != NULL){
        arr[i++] = temp->data;
        temp = temp->link;
    }
    int done = 0;
    int max = 0;
    do {
			done = 0;
			temp = *top;
	        while (temp->link != NULL) {
		        int y = temp->data;
			        if(y == temp->link->data) {
				        max = y;
			        }
		        temp = temp->link;
		        }
	} while (done);

    printf("%d\n", max);
}


