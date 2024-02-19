#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Stack_with_Vector.h" //If you need Vector use "Stack_with_Vector", else "..._SLL"

int main() {
    struct Stack* st = Stack_CTR(100); // If you use Vector CTR need size
    data_type x = 1;
    clock_t start = 0, finish = 0;

    for (size_t i = 0; i < 1000000; i++) {
        Stack_Push(st, &x);
    }

    start = clock();

    for (size_t i = 0; i < 1000000; i++) {
        if (rand() % 2 == 1) {
            Stack_Push(st, &x);
        }
        else {
            Stack_Pop(st);
        }
    }

    finish = clock();

    double duration = (double) (finish - start) / CLOCKS_PER_SEC;
    printf("%2.6f ms\n", duration * 1000);

    Stack_DTR(st);

    return 0;
}
