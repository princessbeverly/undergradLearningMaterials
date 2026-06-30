#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node * next;
};

int main( )
{
    struct node *node1 = NULL, *node2 = NULL, *node3 = NULL;

    node1 = (struct node *) malloc(sizeof(struct node));
    node2 = (struct node *) malloc(sizeof(struct node));
    node3 = (struct node *) malloc(sizeof(struct node));


    if (node1==NULL || node2==NULL || node3==NULL) {
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
    struct node
    *node4 = NULL,
    *node5 = NULL,
    *node6 = NULL,
    *node7 = NULL,
    *node8 = NULL;

    node4 = (struct node *) malloc(sizeof(struct node));
    node5 = (struct node *) malloc(sizeof(struct node));
    node6 = (struct node *) malloc(sizeof(struct node));
    node7 = (struct node *) malloc(sizeof(struct node));
    node8 = (struct node *) malloc(sizeof(struct node));

    if(node4==NULL || node5==NULL || node6==NULL || node7==NULL || node8==NULL){
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


    //checking...
    traverse(node1);






    //remove 8th node
    node8 = NULL;
    node7->next = NULL;
    free(node8);
    //checking...
    traverse(node1);





    //remove 5th node
    node5 = NULL;
    node4->next = node6;
    free(node5);
    //checking...
    traverse(node1);





    //sum of even values
    struct node *next_node = NULL;
    next_node = node1;
    int
    sum=0,
    val=0;
    printf("\n");
    while(next_node != NULL){
        val = next_node->val;
        printf("-> node[%d]", val);
        if((val % 2) == 0){
            sum += val;
        }
        next_node = next_node->next;
    }
    printf("\nsum = %d\n", sum);






    //insert new node between 44 and 55
    struct node *new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        return 1;
    }
    new_node->val = 55;
    node4->next = new_node;
    new_node->next = node6;
    //checking...
    traverse(node1);






    //swap 4th and 1st node
    node4->next = node2;
    node3->next = node1;
    node1->next = new_node;
    //checking...
    traverse(node4);





    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);
    free(node8);

    return 0 ;
}
void traverse(struct node *node){
    printf("\n");
    while(node != NULL){
        printf("-> node[%d]", node->val);
        node = node->next;
    }
    printf("\n");
}
