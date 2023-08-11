// 003. Largest Prime Factor
// src: https://projecteuler.net/problem=3

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define NUMBER 600851475143UL


size_t largest_prime_factor(size_t number);


//---< main >-------------------------------------


int main(void)
{
    printf("Problem 003: %zu\n", largest_prime_factor(NUMBER));

    return 0;
}


//---< end main >---------------------------------


size_t largest_prime_factor(size_t number)
{
    if (number < 2) {
        return 0;
    }

    if (number == 2) {
        return 2;
    }

    while ((number & 1) == 0) {
        number >>= 1;
    }

    // Largest Prime Factor
    size_t lpf = 2;
    size_t i = 3;
    size_t max_iter = sqrt(number);

    while (i < max_iter) {
        size_t mask =  ((number % i) - 1) >> 31;

        lpf = (i & mask) | (lpf & ~mask);

        // Stackoverflow discussion:
        // https://stackoverflow.com/q/76707116/13041067
        number /= (i & mask & (~(size_t)1)) | ((~mask | i) & 1);

        // Other possible ways:
#if 0
           number /= ((i ^ 1) & mask) ^ 1;
           number /= (( i & mask ) >> 1 << 1) | ((~mask | i) & 1);
           number /= ((mask & i) | !mask); // Eric Postpischil
#endif

        i += 2;
    }

    return lpf;
}
