void maxfind(struct node **top){
    struct node *temp;
    temp = *top;
    int max = temp->data;
    while(temp!= NULL){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->link;
    }
    printf("%d\n", max);
}