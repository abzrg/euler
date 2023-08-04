/* 6.Sum Square Difference

The sum of the squares of the first ten natural
numbers is,

1^2 + 2^2 + ... + 10^2 = 385.

The square of the sum of the first ten natural
numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025.

Hence the difference between the sum of the
squares of the first ten natural numbers and the
square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares
of the first one hundred natural numbers and the
square of the sum.

*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define MIN_RANGE 1UL
#define MAX_RANGE 100UL


int main(void)
{
    unsigned sum = 0;
    for (size_t i = MIN_RANGE; i < MAX_RANGE+1; i++)
        sum += i;

    unsigned sum_squareds = 0;
    for (size_t i = MIN_RANGE; i < MAX_RANGE+1; i++)
        sum_squareds += i * i;

    printf("Problem 006: %u\n", (sum*sum - sum_squareds));

    return 0;
}
