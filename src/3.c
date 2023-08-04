/* 3. Largest Prime Factor

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number
600851475143?


600851475143
 |          \
8462696833   71     (1)
 |        \
10086647 _ ` 839    (2)
 |        \
 |         ` 1471   (3)
6857 (4)


*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define NUMBER 600851475143UL


size_t largest_prime_factor(size_t number);


int main(void)
{
    printf("Problem 003: %zu\n", largest_prime_factor(NUMBER));

    return 0;
}


size_t largest_prime_factor(size_t number)
{
    if (number < 2)
        return 0;
    if (number == 2)
        return 2;

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


        // - stackoverflow discussion:
        //     https://stackoverflow.com/q/76707116/13041067
        number /= (i & mask & (~(size_t)1)) | ((~mask | i) & 1);

        /* Other possible ways:

           number /= ((i ^ 1) & mask) ^ 1;
           number /= (( i & mask ) >> 1 << 1) | ((~mask | i) & 1);
           number /= ((mask & i) | !mask); // Eric Postpischil

        */

        i += 2;
    }

    return lpf;
}
