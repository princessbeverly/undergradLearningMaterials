#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(){
    struct node *head = NULL, *node1 = NULL, *node2 = NULL, *node3 = NULL;

    node1 = (struct node*)malloc(sizeof(struct node));
    node2 = (struct node*)malloc(sizeof(struct node));
    node3 = (struct node*)malloc(sizeof(struct node));

    node1->data = 77;
    node1->next = NULL;

    node2->data = 90;
    node2->next = NULL;

    node3->data = 132;
    node3->next = NULL;

    node1->next = node2;
    node2->next = node3;

    struct node *temp = node1;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    free(node1);
    free(node2);
    free(node3);
}
