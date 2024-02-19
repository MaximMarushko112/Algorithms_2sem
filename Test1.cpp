#include <stdio.h>
#include <time.h>

#include "Stack_with_SLL.h"  // В зависимости от типа стека SLL или DA

int main() {
    struct Stack* st = stack_ctr();  // Если DA указывается размер, иначе нет
    data_type x = 1;
    clock_t start = 0, finish = 0;

    start = clock();

    for (size_t i = 0; i < 1000000; i++) {
        push(st, &x);
    }

    while (st->size >= 100000) {
        size_t start_size = st->size;

        for (size_t j = 0; j < start_size / 2; j++) {
            pop(st);
        }

        for (size_t j = 0; j < start_size / 4; j++) {
            push(st, &x);
        }
    }

    finish = clock();

    double duration = (double) (finish - start) / CLOCKS_PER_SEC;
    printf("%2.6f ms\n", duration * 1000);

    stack_dtr(st);
    return 0;
}
