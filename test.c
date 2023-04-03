#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;

    ptr = (int*)malloc(10 * sizeof(int));

    for(int i = 0; i < 10; i++){
        *(ptr+i) = i;
    }

    for(int i = 0; i < 10; i++){
        printf("%d ",*(ptr++));
    }

    printf("\n %d ",*(ptr));

    return 0;
}