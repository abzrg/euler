#include <assert.h>
#include <stdio.h>
#include <string.h>


#define EXTRADIGITS 4
static_assert(EXTRADIGITS > 0, "EXTRADIGITS must be greater than 0.");

#define NUMDIGITS           50
#define BUFSIZE             (NUMDIGITS + 2) /* 2: newline and nullbyte */

#define NUMNUMBERS          100
#define MAXDECIMAL_DIGIT    9
#define MAXTHREEDIGITNUMBER 999
static_assert(NUMNUMBERS < MAXTHREEDIGITNUMBER / MAXDECIMAL_DIGIT,
              "NUMNUMBERS > 111: you have to change your logic and account for "
              "thousands and ... as well");

int ctoi(char c);
char itoc(int i);


int main(void)
{
    // Reading input data from file
    FILE* file = fopen("./inputs/013.txt", "r");

    char buf[NUMDIGITS];
    int numbers[NUMNUMBERS][NUMDIGITS];

    int line_count = 0;
    while (fgets(buf, BUFSIZE, file)) {
        for (size_t i = 0; i < NUMDIGITS; i++) {
            numbers[line_count][i] = ctoi(buf[i]);
        }

        line_count++;
    }

    (void)fclose(file);


    int result[NUMDIGITS + EXTRADIGITS] = { 0 };

    // Looping over each digit
    for (int dig_idx = NUMDIGITS - 1; dig_idx > -1; dig_idx--) {
        int sum = 0;

        // Looping over each number
        for (size_t num_idx = 0; num_idx < NUMNUMBERS; num_idx++) {
            sum += numbers[num_idx][dig_idx];
        }

        sum += result[dig_idx + EXTRADIGITS];
        assert(sum < 9 * (NUMNUMBERS + 1)); // 1: adding digits of result

        int ones = sum % 10;
        int tens = (sum / 10) % 10;
        int hundreds = (sum / 100) % 10;

        result[dig_idx + EXTRADIGITS] = ones;
        result[dig_idx + EXTRADIGITS - 1] += tens;
        result[dig_idx + EXTRADIGITS - 2] += hundreds;
    }


    // Printing first 10 digits (hack)
    printf("Problem 013: ");
    for (size_t i = 0, j = 0; i < NUMDIGITS + EXTRADIGITS && j < 10; i++) {
        int digit = result[i];

        if (digit == 0 && i < 2) {
            continue;
        }

        j++;
        printf("%d", digit);
    }
    putchar('\n');


    return 0;
}


int ctoi(char c)
{
    assert(c >= '0' && c <= '9');
    return c - '0';
}

char itoc(int i)
{
    assert(i < 10 && i > -1);
    return '0' + (char)i; // NOLINT
}
