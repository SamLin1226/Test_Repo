#include <stdio.h>
#include <stdlib.h>


int q1(unsigned int num, int pos){

    return ((num & (1 << pos)) ? 1 : 0);
}

void q2(){
    int a = 4;
    printf("%d\n", a << 1);     // 4*2
    printf("%d\n", a >> 1);     // 4/2 
}

void q3(){
    int n = 10;
    int sum = 0;

    for(int i = 2; i <= n; i++){
        sum += (i-1) * i ;  
    } 
    printf("%d\n", sum);
}


int main(){
    unsigned int a = 5;
    int pos = 2;
    
    if(q1(a, pos)){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
    q2();
    q3();
}