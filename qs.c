#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}


void qsort(int *arr, int n){
    if(n == 1)
        return;

    int m = 0;

    for (int i = 0; i < n; i++){
        if(*(arr + i) > *arr){
            swap(arr + m, arr + i);
            m++;
        }
    }

    if(m == 0)
        m = 1;


    qsort(arr, m);
    qsort(arr + m, n-m);
    
}


int main (){

    int *arr;
    int n = 100;

    arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }

    qsort(arr, n);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}