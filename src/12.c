// 012. Highly Divisible Triangular Number
// src: https://projecteuler.net/problem=12

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

// For timing (on macos)
#define TIME

#ifdef TIME
#include <mach/mach_time.h>
#endif


#define NUM_FACTOR_MAX 500


inline size_t count_factors(unsigned num);


// ---<main>--------------------------------------


int main(void)
{
#ifdef TIME
    uint64_t start_time = mach_absolute_time();
#endif


    //---< START TIMING >-----------------------------------
    size_t facs_count = 0;
    unsigned number = 2;

    for (size_t i = 0; facs_count <= NUM_FACTOR_MAX; i++) {
        number = i * (i + 1) / 2;
        facs_count = count_factors(number);
    }
    //---< END TIMING >-------------------------------------


#ifdef TIME
    // Get the current time after executing the function
    uint64_t end_time = mach_absolute_time();

    // Convert elapsed time to seconds using the timebase info
    mach_timebase_info_data_t timebase;
    mach_timebase_info(&timebase);
    double elapsed_time = (double)(end_time - start_time) *
                          (double)timebase.numer / (double)timebase.denom / 1e9;

    printf("\nElapsed Time: %e seconds\n", elapsed_time);
#endif


    printf("Problem 012: %u\n", number);

    return 0;
}


// ---<end main>----------------------------------


size_t count_factors(unsigned num)
{
    size_t count = 0;

    for (size_t i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            // Count both i and num/i as factors
            count += 2;

            if (i * i == num) {
                // Subtract 1 if i is a perfect square root
                count--;
            }
        }
    }

    return count;
}
