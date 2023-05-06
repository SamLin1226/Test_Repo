#include <stdio.h>
#include <stdlib.h>


void shift(int *arr, int idx, int arrySize, int numShift){
    for(int j = 0; j < numShift; j++){
        for(int i = arrySize - 1; i > idx; i--){
            arr[i] = arr[i - 1];
        }
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if (n == 0){
        return;
    }
    
    if(m == 0){
        for(int i = 0; i < nums1Size; i++){
            nums1[i] = nums2[i];
        }
        return;
    }

    int j = 0;
    for(int i = 0; i < nums1Size; i++){
        if(j >= n){
            break;
        }
        if(nums1[i] < nums2[j]){
            continue;
        }
        else{
            shift(nums1, i, nums1Size, 1);
            nums1[i] = nums2[j++];
        }
        
    }

    if(j != n){
        for(int i = m + j; i < nums1Size; i++){
            nums1[i] = nums2[j++];
        }
    }
     
}

void print_array(int* array, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}


int main(){

#if 1
    int nums1Size = 6;
    int nums2Size = 5;
    int m = 1;
    int o = 5;
    int nums1[6] = {4,0,0,0,0,0};
    int nums2[5] = {1,2,3,5,6}; 
    
#else
    int nums1Size = 2;
    int nums2Size = 1;
    int m = 1;
    int o = 1;
    int nums1[2] = {2,0};
    int nums2[1] = {1};

#endif    


    merge(nums1, nums1Size, m, nums2, nums2Size, o);

    print_array(nums1, nums1Size);

    return 1;
}