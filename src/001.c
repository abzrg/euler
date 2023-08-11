// 001. Multiples of 3 and 5
// src: https://projecteuler.net/problem=1

#include <stdio.h>


#define MAX_RANGE 1000UL


//---< main >-------------------------------------


int main(void)
{
    unsigned sum = 0U;

    for (size_t n = 0; n < MAX_RANGE; n++) {
        if (n % 3 == 0 || n % 5 == 0) {
            sum += n;
        }
    }

    printf("Problem 001: %u\n", sum);

    return 0;
}
