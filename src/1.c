/* 1. Multiples of 3 and 5

If we list all the natural numbers below 10 that
are multiples of 3 or 5, we get 3, 5, 6 and 9. The
sum of these multiples is 23. Find the sum of all
the multiples of 3 or 5 below 1000.

*/

#include <stdio.h>


#define MAX_RANGE 1000UL


int main(void)
{
    unsigned sum = 0U;

    for (size_t n = 0; n < MAX_RANGE; n++)
        if (n % 3 == 0 || n % 5 == 0)
            sum += n;

    printf("Problem 001: %u\n", sum);

    return 0;
}
