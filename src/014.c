#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "utils/chrono.h"


#define MAX_LIMIT 1000000 // 1 Million


uint32_t find_max_chain(uint32_t max_num_limit)
{
    size_t max_chain_len = 1; // 1: the number itself
    size_t num_max_chain = 0;

    for (uint32_t num = 2; num < max_num_limit; num++) {
        size_t chain_len = 1;

        // Sequence
        uint64_t tmp = num;
        while (true) {
            if (tmp % 2 == 0) {
                tmp /= 2;
            } else {
                tmp = 3 * tmp + 1;
            }

            chain_len++;

            if (tmp == 1) {
                break;
            }
        }

        if (chain_len > max_chain_len) {
            max_chain_len = chain_len;
            num_max_chain = num;
        }
    }

    return num_max_chain;
}

int main(void)
{
    uint32_t number = { 0 };
    chrono
    {
        number = find_max_chain(MAX_LIMIT);
    }

    printf("Problem 014: %d\n", number);

    return 0;
}
