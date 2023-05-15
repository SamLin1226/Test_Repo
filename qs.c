#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}


void qsort(int *arr, int n){
    if(n == 1){
        return;
    }
    int c = 0;

    for(int i = 1; i < n; i++){
        if(arr[0] < arr[i]){
            swap(&arr[c], &arr[i]);
            c++;
        }
    }

    if(c == 0){
        c = 1;
    }

    qsort(&arr[0], c);
    qsort(&arr[c], n - c);
}

void chk_sort(int* arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1]){
            printf("Sort error!\n");
            return;
        }
    }

    printf("Sort correct!\n");
    return;
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

    chk_sort(arr, n);


    return 0;
}