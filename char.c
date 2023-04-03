#include <stdio.h>
#include <stdlib.h>

int main () {
    char a[] = "012345";
    char *c;

    c = (char*)calloc(7, sizeof(char));
    for(int i = 0; i < 6; i++){
        c[i] = 48 + i;
    }
    c[6] = '\0';

    //printf(a);
    //printf("\n");

    printf("%s\n", c);
    printf("%s\n", a);
    
    return 0;
}