#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *i2b(int32_t intNum)
{
    char *out;
    uint8_t idx = 0;

    out = (char *)malloc((32 + 1) * sizeof(char));
    out[32] = '\0';

    while (idx < 32)
    {
        if ((intNum & (1 << (31 - idx))))
        {
            out[idx] = '1';
        }
        else
        {
            out[idx] = '0';
        }
        idx++;
    }

    return out;
}

void set_bit(uint32_t *adrr, uint8_t bit, uint8_t val){
    if(val == 1){
        *adrr |= (1 << bit); 
    }
    else if(val == 0){
        *adrr &= ~(1 << bit);
    }
    else{
        printf("Value must be 1 or 0 !\n");
        return;
    }
}

// |_|_|_|_| |_|_|_|_| |_|_|_|_| |_|_|_|_| |_|_|_|_| |_|_|_|_| |_|_|_|_| |_|_|_|_|

int main()
{
    uint32_t *a;
    
    a = (uint32_t*) malloc(sizeof(uint32_t));

    *a = 0xF0F0F0F0;
    printf("%s\n", i2b(*a));

    set_bit(a, 31, 0);
    printf("%s\n", i2b(*a));

    set_bit(a, 27, 1);
    printf("%s\n", i2b(*a));

    set_bit(a, 27, 3);
    printf("%s\n", i2b(*a));

    return 0;
}