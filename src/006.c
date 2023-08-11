// 006. Sum Square Difference
// src: https://projecteuler.net/problem=6

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define MIN_RANGE 1UL
#define MAX_RANGE 100UL


//---< main >-------------------------------------


int main(void)
{
    unsigned sum = 0;
    for (size_t i = MIN_RANGE; i < MAX_RANGE+1; i++) {
        sum += i;
    }

    unsigned sum_squareds = 0;
    for (size_t i = MIN_RANGE; i < MAX_RANGE+1; i++) {
        sum_squareds += i * i;
    }

    printf("Problem 006: %u\n", (sum*sum - sum_squareds));

    return 0;
}
