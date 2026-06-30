#include <stdio.h>
#include <stdlib.h>

struct node {
    int red;
    int blue;
    int green;
    struct node *next;
};

void push(struct node *RGB, )
int main(){

    struct node *redHead = NULL, *blueHead = NULL,
    int count = 0, red = 0, blue = 0, green = 0;
    printf("How many colors to input: "); scanf("%d", &count);

    for(int i = 0; i < count; i++){
        printf("Input: "); scanf("%d %d %d", &red, &green, &blue);
    }


}
