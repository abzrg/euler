#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils/chrono.h"

#define MAX_LIMIT   1000000 // 1 Million
#define NUM_THREADS 8 // Number of threads to use

static size_t max_chain_len = 1; // 1: the number itself
static size_t num_max_chain = 0;

// Mutex for protecting the shared max_chain_len and num_max_chain variables
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // NOLINT

void* find_max_chain(void* arg)
{
    long int start = *((long int*)arg);

    for (long int num = start; num < MAX_LIMIT; num += NUM_THREADS) {
        size_t chain_len = 1;

        // Sequence
        long int tmp = num;
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

        // Update max_chain_len and num_max_chain if needed
        pthread_mutex_lock(&mutex);
        if (chain_len > max_chain_len) {
            max_chain_len = chain_len;
            num_max_chain = num;
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main(void)
{
    pthread_t threads[NUM_THREADS];
    long int thread_args[NUM_THREADS];

    chrono
    {
        for (int i = 0; i < NUM_THREADS; i++) {
            thread_args[i] = i + 2; // Start each thread at a different number
            pthread_create(&threads[i], NULL, find_max_chain, &thread_args[i]);
        }

        for (int i = 0; i < NUM_THREADS; i++) {
            pthread_join(threads[i], NULL);
        }
    }

    printf("Problem 014: %ld\n", num_max_chain);

    return 0;
}
