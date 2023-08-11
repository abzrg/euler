// 005. Smallest Multiple
// src: https://projecteuler.net/problem=5

#include <stdio.h>
#include <stdbool.h>


#define START 2520

// Minimum and maximum of remainder
#define MIN_RANGE 1UL
#define MAX_RANGE 20UL


//---< main >-------------------------------------


int main(void)
{
    unsigned num = START;

    // When num overflows it becomes less than START
    // (There is no upper limit for num)
    while (num >= START) {
        for (size_t rem = MAX_RANGE; rem > MIN_RANGE; rem--) {
            if (num % rem != 0) {
                break;
            }

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
