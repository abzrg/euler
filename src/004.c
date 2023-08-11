// 004. Largest Palindrome Product
// src: https://projecteuler.net/problem=4

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


// 999*999 = 998001 (6 digits)
#define MAX_DIGITS 8UL


bool is_palindromic(unsigned number);
size_t count_digits(unsigned number);
unsigned largest_palindromic(size_t begin, size_t end);


//---< main >-------------------------------------


int main(void)
{
    printf("Problem 004: %u\n", largest_palindromic(100,1000));

    return 0;
}


//---< end main >---------------------------------


unsigned largest_palindromic(size_t begin, size_t end)
{
    unsigned lpn = { 0 };

    for (size_t m = begin; m < end; m++) {
        for (size_t n = begin; n < end; n++) {
            if (n < m) {
                continue;
            }

            size_t r = m*n;
            if (is_palindromic(r) && (r > lpn)) {
                lpn = r;
            }
        }
    }

    return lpn;
}


bool is_palindromic(unsigned number)
{
    unsigned tmp = number;
    size_t no_digits = count_digits(number);

    // Put all the digits in an array
    unsigned digits[MAX_DIGITS] = { 0 };
    for (size_t i = 0; i < no_digits+1; i++) {
        digits[i] = tmp % 10;
        tmp /= 10;
    }

    // Compare both sides
    size_t i = 0;
    size_t j = no_digits - 1;
    while (i < j) {
        if (digits[i] != digits[j]) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}


size_t count_digits(unsigned number)
{
    size_t digits = 0;

    while(number != 0) {
        number /= 10;
        digits++;
    }

    return digits;
}
