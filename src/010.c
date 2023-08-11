// 010. Summation of Primes
// src: https://projecteuler.net/problem=10

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define MAX_RANGE 2000000UL

bool is_prime(unsigned long n);


//---<main>---------------------------------------


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


//---<end main>-----------------------------------


bool is_prime(unsigned long n)
{
    for (size_t i = 3, limit = sqrt(n) + 1; i < limit; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
