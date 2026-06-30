//PRINCESS BEVERLY R. ALA-AN
//BK1
//ASSIGNMENT
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node * next;
};

int main( )
{
    struct node * node1 = NULL, * node2 = NULL, * node3 = NULL;

    node1 = (struct node *) malloc(sizeof(struct node));
    node2 = (struct node *) malloc(sizeof(struct node));
    node3 = (struct node *) malloc(sizeof(struct node));

    if (node1 == NULL || node2 == NULL || node3 == NULL) {
        return 1;
    }

    node1->val = 11;
    node1->next = NULL;

    node2->val = 22;
    node2->next = NULL;

    node3->val = 33;
    node3->next = NULL;

    node1->next = node2;
    node2->next = node3;

    //add your code here

    struct node *node4 = NULL, *node5 = NULL, *node6 = NULL, *node7 = NULL, *node8 = NULL;
    node4 = (struct node *)malloc(sizeof(struct node));
    node5 = (struct node *)malloc(sizeof(struct node));
    node6 = (struct node *)malloc(sizeof(struct node));
    node7 = (struct node *)malloc(sizeof(struct node));
    node8 = (struct node *)malloc(sizeof(struct node));

    if(node4 == NULL || node5 == NULL || node6 == NULL || node7 == NULL || node8 == NULL){
        return 1;
    }

    node4->val = 44;
    node4->next = NULL;

    node5->val = 55;
    node5->next = NULL;

    node6->val = 66;
    node6->next = NULL;

    node7->val = 77;
    node7->next = NULL;

    node8->val = 88;
    node8->next = NULL;

    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;

    printf("Linked List: ");
    struct node *current = node1;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    //remove the 8th node
                node8->next = NULL;


                current = node1;
                while (current != NULL && current->next != node8) {
                    current = current->next;
                }

                // If node8 is found, adjust pointers to bypass it
                if (current != NULL) {
                    current->next = node8->next;
                    free(node8);
                }

                // Display the entire linked list
                printf("Removing node8: ");
                current = node1;
                while (current != NULL) {
                    printf("%d -> ", current->val);
                    current = current->next;
                }
                printf("NULL\n");

    //remove the 5th node
                current = node5;
                struct node *prev = node4;

                if (current != NULL && prev != NULL) {
                    prev->next = current->next;
                    free(current);
                }

                // Display the updated linked list
                printf("Removing node5: ");
                current = node1;
                while (current != NULL) {
                    printf("%d -> ", current->val);
                    current = current->next;
                }
                printf("NULL\n");



    //show the sum of all even numbers/values in the list

                int sum = 0;
                current = node1;
                while (current != NULL) {
                    if (current->val % 2 == 0) {
                        sum += current->val;
                    }
                    current = current->next;
                }

                // Display the sum
                printf("Sum of all even numbers/values in the list is: %d\n", sum);


    //insert a new node with a value of 55 in between of node 44 and node 66

                struct node *new_node = NULL;
                new_node = (struct node*)malloc(sizeof(struct node));
                if(new_node == NULL){
                    return 1;
                }
                new_node->val = 55;
                node4->next = new_node;
                new_node->next = node6;

                printf("Inserting 55: ");
                current = node1;
                while (current != NULL) {
                    printf("%d -> ", current->val);
                    current = current->next;
                }
                printf("NULL\n");

    //swap the 4th and 1st node. Swap the entire node not the value of the node.
               node4->next = node2;
                node3->next = node1;
                node1->next = new_node;

                current = node4;
                printf("Swapping: ");
                while (current != NULL) {
                    printf("%d -> ", current->val);
                    current = current->next;
                }
                printf("NULL\n");

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);
    free(node8);
    free(new_node);
    return 0 ;
}
