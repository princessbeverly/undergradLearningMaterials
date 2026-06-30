#include <stdio.h>


int num = 1;

int function_to_add(int num){
    if(num == 6){
        //printf("%d", num);
        return num;

    }

    return function_to_add(num)+1;
}

int main(){
   // int num = 1;
    //int num = 1;
    //int res = 0;
    num = function_to_add(num);


    printf("%d", num);
}
