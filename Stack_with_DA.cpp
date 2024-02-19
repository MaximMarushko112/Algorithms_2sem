#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dynamic_Array.h"
#include "Stack_with_DA.h"

struct Stack* stack_ctr(size_t size) {
    struct Stack* st = (struct Stack*) calloc(1, sizeof(struct Stack));
    assert(st != NULL);

    st->data = Create_DA(size);
    st->size = 0;

    return st;
}

int push(struct Stack* st, void* buffer) {
    assert(st != NULL);
    assert(st->data != NULL);
    assert(buffer != NULL);

    if (st->size >= st->data->capacity) {
        Realloc_Up(st->data);
    }

    *(st->data->array + st->size) = *((data_type*) buffer);
    st->size++;
    return 1;
}

int top(struct Stack* st, void* buffer) {
    assert(st != NULL);
    assert(st->data != NULL);
    assert(buffer != NULL);

    if (memcpy(buffer, st->data->array + st->size, sizeof(data_type)) != NULL) {
        return 1;
    }

    return 0;
}

int pop(struct Stack* st) {
    assert(st != NULL);
    assert(st->data != NULL);

    st->data->array[--st->size] = 0;

    if (st->size * MULTIPLIER <= st->data->capacity / MULTIPLIER) {
        if(st->data->capacity >= MIN_CAPACITY * MULTIPLIER) {
            Realloc_Down(st->data);
        }
    }

    return 1;
}

struct Stack* stack_dtr(struct Stack* st) {
    assert(st != NULL);
    assert(st->data != NULL);

    Clear_DA(st->data);
    free(st);

    return NULL;
}
