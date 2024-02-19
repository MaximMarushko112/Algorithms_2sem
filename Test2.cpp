#include <stdio.h>
#include <time.h>

#include "Stack_with_SLL.h" //If you need Vector use "Stack_with_Vector", else "..._SLL"

int main() {
    struct Stack* st = Stack_CTR(); // If you use Vector CTR need size
    data_type x = 1;
    clock_t start = 0, finish = 0;

    start = clock();

    for (size_t i = 0; i < 1000000; i++) {
        Stack_Push(st, &x);
    }

    for (size_t i = 0; i < 100; i++) {
        for (size_t j = 0; j < 10000; j++) {
            Stack_Pop(st);
        }

        for (size_t j = 0; j < 10000; j++) {
            Stack_Push(st, &x);
        }
    }

    while (st->size >= 100000) {
        size_t start_size = st->size;

        for (size_t j = 0; j < start_size / 2; j++) {
            Stack_Pop(st);
        }

        for (size_t j = 0; j < start_size / 4; j++) {
            Stack_Push(st, &x);
        }
    }

    for (size_t i = 0; i < 100; i++) {
        for (size_t j = 0; j < 10000; j++) {
            Stack_Pop(st);
        }

        for (size_t j = 0; j < 10000; j++) {
            Stack_Push(st, &x);
        }
    }

    finish = clock();

    double duration = (double) (finish - start) / CLOCKS_PER_SEC;
    printf("%2.6f ms\n", duration * 1000);

    Stack_DTR(st);

    return 0;
}
