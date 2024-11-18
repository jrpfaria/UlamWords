#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    uint64_t word = 0b01010;
    uint64_t subword1, subword2;
    for (int i = 1; i < 5; i++){
        subword1 = word >> 5 - i;
        subword2 = word & ((1U << 5-i) - 1);

        printf("%ld + %ld\n", subword1, subword2);
    }

}