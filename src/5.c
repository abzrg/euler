/* 5. Smallest Multiple

2520 is the smallest number that can be divided
by each of the numbers from 1 to 10 without any
remainder.

What is the smallest positive number that is
evenly divisible (divisible with no remainder)
by all of the numbers from 1 to 20?

*/

#include <stdio.h>
#include <stdbool.h>


#define START 2520

// Minimum and maximum of remainder
#define MIN_RANGE 1UL
#define MAX_RANGE 20UL


int main(void)
{
    unsigned num = START;

    // When num overflows it becomes less than START
    // (There is no upper limit for num)
    while (num >= START) {
        for (size_t rem = MAX_RANGE; rem > MIN_RANGE; rem--) {
            if (num % rem != 0)
                break;

            if (rem == 2) {
                printf("ans = %u\n", num);
                return 0;
            }
        }

        num += 20;
    }

    printf("Couldn't find the number\n");

    return 0;
}
