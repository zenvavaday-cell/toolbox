#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

// Prevents the compiler from optimizing away a variable calculation
// by forcing it to assume the variable is read/used.
void escape(void* p) {
    asm volatile("" : : "g"(p) : "memory");
}

// Prevents the compiler from optimizing away operations that write to memory
void clobber() {
    asm volatile("" : : : "memory");
}

// Target function we want to benchmark
int target_operation(int input) {
    return input * 42 + 7; 
}

int main() {
    struct timespec start, end;
    uint64_t total_ns = 0;
    int iterations = 10000000; // 10 Million iterations
    volatile int dummy_result = 0; 

    // Warm-up phase to load instructions into the CPU cache
    for (int i = 0; i < 10000; i++) {
        dummy_result = target_operation(i);
    }
    escape((void*)&dummy_result);

    // Start benchmark timing
    if (clock_gettime(CLOCK_MONOTONIC, &start) != 0) {
        perror("clock_gettime");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < iterations; i++) {
        int res = target_operation(i);
        
        // Trick the compiler into thinking 'res' is used in every loop iteration
        escape(&res); 
    }
    clobber(); // Force any remaining memory writes to commit

    if (clock_gettime(CLOCK_MONOTONIC, &end) != 0) {
        perror("clock_gettime");
        return EXIT_FAILURE;
    }

    // Calculate elapsed time in nanoseconds
    total_ns = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
    double avg_ns = (double)total_ns / iterations;

    printf("Total iterations: %d\n", iterations);
    printf("Total time:       %.4f ms\n", (double)total_ns / 1000000.0);
    printf("Average time:     %.2f ns per operation\n", avg_ns);

    return 0;
}
