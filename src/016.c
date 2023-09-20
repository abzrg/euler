#include <stdint.h>
#include <stdio.h>

#define POWER     1000
#define NUMDIGITS 400

int main(void)
{
    // Storing digits of the answer in reverse, meaning the
    // least significant decimal digits will be in index 0
    uint32_t sumarr[NUMDIGITS] = { [0] = 1, 0 };

    for (size_t i = 0; i < POWER; i++) {
        uint32_t carry = 0;
        for (size_t j = 0; j < NUMDIGITS; j++) {
            uint32_t digit = sumarr[j];
            digit *= 2;
            digit += carry;

            uint32_t ones = digit % 10;
            carry = digit / 10 % 10;

            sumarr[j] = ones;
        }
    }

    // Sum digits
    uint32_t sum_of_digits = 0;
    for (size_t i = 0; i < NUMDIGITS; i++) {
        sum_of_digits += sumarr[i];
    }

    printf("Problem 016: %d\n", sum_of_digits);


    return 0;
}
