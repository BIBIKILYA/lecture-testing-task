#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define NUM_OPERATIONS 10000000 // Количество операций push/pop

void benchmarkPush(Stack* stack) {
    clock_t start = clock(); // Записываем начальное время
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        push(stack, i); // Выполняем операцию push
    }
    clock_t end = clock(); // Записываем конечное время
    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC; // Считаем время
    printf("Benchmark PUSH: %d operations took %.6f seconds\n", NUM_OPERATIONS, elapsed_time);
}

void benchmarkPop(Stack* stack) {
    clock_t start = clock(); // Записываем начальное время
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        pop(stack); // Выполняем операцию pop
    }
    clock_t end = clock(); // Записываем конечное время
    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC; // Считаем время
    printf("Benchmark POP: %d operations took %.6f seconds\n", NUM_OPERATIONS, elapsed_time);
}

int main() {
    Stack stack;
    initStack(&stack);

    printf("Starting benchmark for PUSH...\n");
    benchmarkPush(&stack);

    printf("Starting benchmark for POP...\n");
    benchmarkPop(&stack);

    destroyStack(&stack); // Чистим стек

    return 0;
}
