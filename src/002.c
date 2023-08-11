// 002. Even Fibonacci Numbers
// src: https://projecteuler.net/problem=2

#include <stdio.h>
#include <stdbool.h>


#define UPPER_LIMIT (size_t)4e6


//---< main >-------------------------------------


int main(void)
{
    unsigned sum = 0;
    unsigned m = 1;
    unsigned n = 2;

    bool leave = false;
    while(!leave) {
        leave = (m >= UPPER_LIMIT || n >= UPPER_LIMIT);

        // (n & 1): checks whether the n is odd
        (n & 1) || (sum += n);

        unsigned tmp = m;
        m = n;
        n = tmp + n;
    }

    printf("Problem 002: %u\n", sum);

    return 0;
}
