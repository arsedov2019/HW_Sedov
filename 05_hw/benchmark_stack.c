
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define NUM_OPERATIONS 1000000

void benchmark_push(Stack* stack) {
    clock_t start = clock();
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        push(stack, i);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for %d push operations: %f seconds\n", NUM_OPERATIONS, time_spent);
}

void benchmark_pop(Stack* stack) {
    clock_t start = clock();
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        pop(stack);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for %d pop operations: %f seconds\n", NUM_OPERATIONS, time_spent);
}

int main() {
    Stack stack;
    initStack(&stack);

    printf("Starting benchmark for push operation...\n");
    benchmark_push(&stack);

    printf("Starting benchmark for pop operation...\n");
    benchmark_pop(&stack);

    destroyStack(&stack);
    return 0;
}
