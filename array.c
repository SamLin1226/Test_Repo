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

void q_sort_t(int *array, int n){
    if(n == 1)
        return;
    
    int c = 0;
    for(int i = 1; i < n; i++){
        if(*array > *(array + i)){
            swap(array + c, array + i);
            c++;
        }
    }

    if (c == 0){
        c = 1 ;
    }
    
    q_sort_t(array, c);
    q_sort_t(array + c, n - c);
    return;
}

void bubble_sort(int *array, int n){
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(array[i] < array[j]){
                swap(&array[i], &array[j]);
            }
        }
    }

    return;
}

void chk_sort(int* arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            printf("Sort error!\n");
            return;
        }
    }

    printf("Sort correct!\n");
    return;
}


int main() {
    int *array, *rand_array;
    int n = 100;
    int *a, *b; 


    clock_t t1,t2,t3,t4;            
    rand_array = new_rand_array(n);
    array = new_array(n);

    
    print_array(array, n);



    cpy_array(rand_array, array, n);
    print_array(rand_array, n);


    t1 = clock();
    q_sort_t(rand_array, n);
    t2 = clock();
    chk_sort(rand_array, n);
    printf("q time = %f \n", (double)(t2-t1)/CLOCKS_PER_SEC);


    t3 = clock();
    bubble_sort(array, n);
    t4 = clock();
    chk_sort(array, n);
    printf("b time = %f \n", (double)(t4-t3)/CLOCKS_PER_SEC);

    //print_array(rand_array, n);
    //print_array(array, n);



    return 0;
}