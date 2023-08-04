/* 9. Special Pythagorean Triplet


A Pythagorean triplet is a set of three natural
numbers, a < b < c, for which,

   a^2 + b^2 = c^2.

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for
which a + b + c = 1000.

Find the product abc.

*/

#include <stdio.h>


int main(void)
{
    unsigned a = 0;
    unsigned b = 0;
    unsigned c = 0;

    for (a = 1U; a < 1000U; a++) {
        for (b = a + 1U; b < 1000U; b++) {
            c = 1000U - b - a;
            if (a * a + b * b == c * c) {
                printf("Problem 009: %u\n", a * b * c);
                return 0;
            }
        }
    }

    printf("Couldn't found\n");

    return 0;
}
