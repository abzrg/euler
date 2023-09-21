// 017: Number Letter Counts
// src: https://projecteuler.net/problem=17

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    const uint32_t num;
    const size_t str_len;
} number_strlen_t;

#define SPECIAL_NUMS_LEN 36
static const number_strlen_t special_nums[SPECIAL_NUMS_LEN] = {
    { .num = 1, .str_len = strlen("one") },
    { .num = 2, .str_len = strlen("two") },
    { .num = 3, .str_len = strlen("three") },
    { .num = 4, .str_len = strlen("four") },
    { .num = 5, .str_len = strlen("five") },
    { .num = 6, .str_len = strlen("six") },
    { .num = 7, .str_len = strlen("seven") },
    { .num = 8, .str_len = strlen("eight") },
    { .num = 9, .str_len = strlen("nine") },
    { .num = 10, .str_len = strlen("ten") },
    { .num = 11, .str_len = strlen("eleven") },
    { .num = 12, .str_len = strlen("twelve") },
    { .num = 13, .str_len = strlen("thirteen") },
    { .num = 14, .str_len = strlen("fourteen") },
    { .num = 15, .str_len = strlen("fifteen") },
    { .num = 16, .str_len = strlen("sixteen") },
    { .num = 17, .str_len = strlen("seventeen") },
    { .num = 18, .str_len = strlen("eighteen") },
    { .num = 19, .str_len = strlen("nineteen") },
    { .num = 20, .str_len = strlen("twenty") },
    { .num = 30, .str_len = strlen("thirty") },
    { .num = 40, .str_len = strlen("forty") },
    { .num = 50, .str_len = strlen("fifty") },
    { .num = 60, .str_len = strlen("sixty") },
    { .num = 70, .str_len = strlen("seventy") },
    { .num = 80, .str_len = strlen("eighty") },
    { .num = 90, .str_len = strlen("ninety") },
    { .num = 100, .str_len = strlen("onehundred") },
    { .num = 200, .str_len = strlen("twohundred") },
    { .num = 300, .str_len = strlen("threehundred") },
    { .num = 400, .str_len = strlen("fourhundred") },
    { .num = 500, .str_len = strlen("fivehundred") },
    { .num = 600, .str_len = strlen("sixhundred") },
    { .num = 700, .str_len = strlen("sevenhundred") },
    { .num = 800, .str_len = strlen("eighthundred") },
    { .num = 900, .str_len = strlen("ninehundred") },
};

static inline size_t get_special_number_len(uint32_t num)
{
    size_t numlen = 0UL;
    for (size_t i = 0; i < SPECIAL_NUMS_LEN; i++) {
        if (num == special_nums[i].num) {
            numlen = special_nums[i].str_len;
            break;
        }
    }

    return numlen;
}

static inline size_t get_number_len(uint32_t num)
{
    assert(num < 1000 && num > 0
           && "get_number_len: input number out of range. 0 < num < 1000");

    size_t numlen = 0;

    uint32_t ones = num % 10; // NOLINT
    uint32_t tens = num / 10 % 10; // NOLINT
    uint32_t hundreds = num / 100 % 10; // NOLINT

    if (tens == 1 && ones != 0) { // 11, 111, ...
        if (num < 99) { // NOLINT
            numlen += get_special_number_len(num); // 11
        } else {
            numlen += get_special_number_len(num - 100 * hundreds); // 111 -> 11 // NOLINT
        }
    } else { // 24, 742
        numlen += get_special_number_len(ones);
        numlen += get_special_number_len(tens * 10); // NOLINT
    }
    numlen += get_special_number_len(hundreds * 100); // NOLINT

    if (num > 99 && num % 100 != 0) { // 101, 110 // NOLINT
        numlen += strlen("and");
    }

    return numlen;
}

int main(void)
{
#if 0 // test
    printf("num: %d, len: %zu\n", 1, get_number_len(1));
    printf("num: %d, len: %zu\n", 10, get_number_len(10));
    printf("num: %d, len: %zu\n", 11, get_number_len(11));
    printf("num: %d, len: %zu\n", 20, get_number_len(20));
    printf("num: %d, len: %zu\n", 21, get_number_len(21));
    printf("num: %d, len: %zu\n", 99, get_number_len(99));
    printf("num: %d, len: %zu\n", 100, get_number_len(100));
    printf("num: %d, len: %zu\n", 101, get_number_len(101));
    printf("num: %d, len: %zu\n", 110, get_number_len(110));
    printf("num: %d, len: %zu\n", 111, get_number_len(111));
    printf("num: %d, len: %zu\n", 121, get_number_len(121));
    printf("num: %d, len: %zu\n", 149, get_number_len(149));
#endif

    uint32_t sum = 0;

    // sum of letters of numbers from 0 to 19
    for (uint32_t num = 1; num < 1000; num++) { // NOLINT
        sum += get_number_len(num);
    }
    sum += strlen("onethousand");


    printf("Problem 017: %d\n", sum);

    return 0;
}
