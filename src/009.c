// 009. Special Pythagorean Triplet
// src: https://projecteuler.net/problem=9

#include <stdio.h>


//---< main >-------------------------------------


int main(void)
{
    unsigned a = 0;
    unsigned b = 0;
    unsigned c = 0;

    for (a = 1U; a < 1000U; a++) {
        for (b = a + 1U; b < 1000U; b++) {
            c = 1000U - b - a;
            if (a * a + b * b == c * c) {
                printf("Problem 009: %u\n", a * b * c);
                return 0;
            }
        }
    }

    printf("Couldn't found\n");

    return 0;
}
