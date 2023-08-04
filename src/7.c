/* 7. 10001st Prime

By listing the first six prime numbers: 2, 3,
5, 7, 11, and 13, we can see that the 6th prime
is 13.

What is the 10001st prime number?

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define PRIME_START 3UL

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

        if (is_prime)
            order++;

        if (order == 10001)
            break;

        num += 2;
    }

    printf("Problem 007: %u\n", num);

    return 0;
}
