#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *new_array(int n){
    int *array;
    array = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        array[i] = i;
    }
    return array;
}

int *new_rand_array(int n){
    int min, max;
    int *array;

    min = 0;
    max = 100;

    array = (int*)calloc(n, sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        array[i] = rand() % (max - min + 1) + min;
    }

    return array;
}

void print_array(int* array, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

void cpy_array(int *array1, int *array2, int n){    //copy array1 to array2
    for(int i = 0; i < n; i++){
        array2[i] = array1[i];
    }
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void q_sort(int *array, int n){
    if(n == 1)
        return;
    
    int c = 0;
    for(int i = 1; i < n; i++){
        if(*array < *(array + i)){
            swap(array + c, array + i);
            c++;
        }
    }

    if (c == 0){
        c = 1 ;
    }
    
    q_sort(array, c);
    q_sort(array + c, n - c);
    return;
}

void bubble_sort(int *array, int n){
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(array[i] > array[j]){
                swap(&array[i], &array[j]);
            }
        }
    }

    return;
}

int main() {
    int *array, *rand_array;
    int n = 10;
    
    array = new_array(n);
    rand_array = new_rand_array(n);
    cpy_array(rand_array, array, n);

    print_array(rand_array, n);

    q_sort(rand_array, n);
    bubble_sort(array, n);

    print_array(rand_array, n);
    print_array(array, n);

    return 0;
}