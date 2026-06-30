int pos = 0, i = 1;
temp = head;
//enter posiiton

while(i < pos-1){
    temp  = temp->next;
    i++;
}

nextnode = temp->next;
temp->next = nextnode->next;
free(nextnode);
