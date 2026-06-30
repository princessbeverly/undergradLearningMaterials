#include <stdio.h>
#include <stdlib.h>

struct node {
    int red;
    int green;
    int blue;
    struct node *link;
    struct node *redtop;
    struct node *greentop;
    struct node *bluetop;
};

void display(struct node **top){
    struct node *temp;
    temp = *top;
    while(temp!= NULL){
        printf("%d %d %d\n", temp->red, temp->green, temp->blue);
        temp = temp->link;
    }
}
void pop(struct node **top){
    struct node *temp = *top;

    if(*top == NULL){
        printf("Stack is empty\n");
        return;
    }else{

        
        printf("Popped element = %d %d %d\n", temp->red, temp->green, temp->blue);
        temp = *top;
        *top = (*top)->link;
        free(temp);
    }
}
void push(struct node **top, int red, int green, int blue){
    struct node *newnode = malloc(sizeof(struct node));
     newnode->red = red;
     newnode->green = green;
     newnode->blue = blue;

     

    newnode->link = *top;
    *top = newnode;
}

int main(){

    struct node *top = NULL, *redtop = NULL, *greentop = NULL, *bluetop = NULL;
    //struct node *redTop = redTop->redtop, *greenTop = greenTop->greentop, *blueTop = blueTop->bluetop;
    int count = 0, red, green, blue;
    printf("How many colors do you want: "); scanf("%d", &count);

    for(int i = 0; i < count; i++) {
        printf("Color (red, green, blue): "); 
        scanf("%d %d %d", &red, &green, &blue);
        push(&top, red, green, blue);
    }
    
    if(top == NULL) {
        printf("Underflow Condition\n");
        return 0;
    }else{
        display(&top);
        
        printf("\n");

        display(&top);
        printf("\n");

        if(red == 255){
        push(&redtop, 255, 0, 0);
        }
        if(green == 255){
            push(&greentop, 0, 255, 0);
        }
        if(blue == 255){
            push(&bluetop, 0, 0, 255);
        }
        pop(&top);
        printf("Green popped:\n");
        display(&greentop);
        printf("Red popped: \n");
        display(&redtop);
        printf("Blue popped: \n");
        display(&bluetop);

    }
    return 0;
}