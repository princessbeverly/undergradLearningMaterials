#include <stdio.h>

int num = 1;

void procedure_to_add_one(){
    if (num != 6)
        return num;

    return num+=1;
}

int main(){
    procedure_to_add_one();
    printf("%d", num);

}
