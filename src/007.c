// 007. 10001st Prime
// src: https://projecteuler.net/problem=7

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define NTH_PRIME 10001UL
#define PRIME_START 3UL


//---< main >-------------------------------------


int main(void)
{
    unsigned num = PRIME_START;

    // Counting the number 2 as the first prime
    size_t order = 1;

    while (true) {
        bool is_prime = true;

        for (size_t i = 2UL, max_search = sqrt(num); i < (max_search + 1); i++) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            order++;
        }

        if (order == NTH_PRIME) {
            break;
        }

        num += 2;
    }

    printf("Problem 007: %u\n", num);

    return 0;
}
