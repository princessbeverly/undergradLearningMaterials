// PRINCESS BEVERLY R. ALA-AN BK1
//NUMBER 1
#include <stdio.h>
#include <stdlib.h>

struct arrayStruct {
    int x;
};

void ascending(struct arrayStruct *, int);
int main(){
    struct arrayStruct arr[10];
    printf("INput 10 numbers:\n");
    for(int i = 0; i < 10; i++){
        printf("%d :", i+1); scanf("%d", &arr[i].x);
    }
    ascending(arr, 10);
    return 0;
}

void ascending(struct arrayStruct *arr, int a){
    int i = 0, j = 0, temp = 0;

    //ascending order
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(arr[i].x < arr[j].x){
                temp = arr[i].x;
                arr[i].x = arr[j].x;
                arr[j].x = temp;
            }
        }
    }
    printf("Descending Order:\n");
    for(i = 0; i < 10; i++){
        printf("%d ", arr[i].x);
    }
}
