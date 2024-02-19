#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Stack_with_DA.h" // В зависимости от типа стека SLL или DA

int main() {
    struct Stack* st = stack_ctr(100); // Если DA указывается размер, иначе нет
    data_type x = 1;
    clock_t start = 0, finish = 0;

    for (size_t i = 0; i < 1000000; i++) {
        push(st, &x);
    }

    start = clock();

    for (size_t i = 0; i < 1000000; i++) {
        if (rand() % 2 == 1) {
            push(st, &x);
        }
        else {
            pop(st);
        }
    }

    finish = clock();

    double duration = (double) (finish - start) / CLOCKS_PER_SEC;
    printf("%2.6f ms\n", duration * 1000);

    stack_dtr(st);

    return 0;
}
