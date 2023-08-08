/* 10. Summation of Primes

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define MAX_RANGE 2000000UL

bool is_prime(unsigned long n);


int main(void)
{
    unsigned long prime_sum = 2UL;

    for (size_t n = 3; n < MAX_RANGE; n += 2) {
        if (is_prime(n)) {
            prime_sum += n;
        }
    }

    printf("Problem 010: %lu\n", prime_sum);

    return 0;
}


bool is_prime(unsigned long n)
{
    for (size_t i = 3, max_search = (size_t)sqrt(n) + 1;
            i < max_search;
            i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
