// PRINCESS BEVERLY R. ALA-AN BK1
// NUMBER 2
// DONE
#include <stdio.h>
#include <stdlib.h>
struct myArray{
    int *ptrArray;
    int size;
    int length;
};

int search(int, struct myArray *);
int delete(int, struct myArray *);

int main(){
    struct myArray *arr;
    //allocate 5 values in array arr
    arr->ptrArray = (struct myArray *)malloc(5 * sizeof(int));
    arr->size = 5;
    arr->length = 5;
    printf("length = %d", arr->length);
    //insert 5 values in array arr
    arr->ptrArray[0] = 5;
    arr->ptrArray[1] = 10;
    arr->ptrArray[2] = 15;
    arr->ptrArray[3] = 20;
    arr->ptrArray[4] = 25;

    int data = 20;
    //search element 20 and call function search
    int found = search(data, &arr->ptrArray);

    if(found == 1){
        printf("Successfully Found!\n");
    }

    data = 20;
    int deleted = delete(data, &arr->ptrArray);
    if(deleted == 1){  
        printf("Successfully Deleted!\n");
    }
    return 0;
}

int search(int data, struct myArray *arr){
    int len = arr->length;
    for(int i = 0; i < len; i++){
        if(arr->ptrArray[i] == data){
            return 1;
        }
    }
}

int delete(int data, struct myArray *arr){
    int len = arr->length;
    for(int i = 0; i < len; i++){
        if(arr->ptrArray[i] == data){
            for(int j = i; j < len - 1; j++){
                arr->ptrArray[j] = arr->ptrArray[j + 1];
            }
            arr->length--;
            return 1;
        }
}
