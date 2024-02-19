#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Stack_with_DA.h"

int main() {
    struct Stack* st = stack_ctr(100);
    data_type x = 1;
    clock_t start = 0, finish = 0;

    start = clock();

    for (size_t i = 1; i <= 1000000; i++) {
        push(st, &x);

        double duration = 0;

        if (i % 1000 == 0) {
            finish = clock();

            duration = (double) (finish - start) / CLOCKS_PER_SEC;

            printf("%2.6f, ", duration * 1000);
        }
    }

    stack_dtr(st);

    return 0;
}
