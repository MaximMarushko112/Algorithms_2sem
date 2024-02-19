#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Vector.h"
#include "Stack_with_Vector.h"

struct Stack* Stack_CTR(size_t size) {
    struct Stack* st = (struct Stack*) calloc(1, sizeof(struct Stack));
    assert(st != NULL);

    st->vect = Create_Vector(size);
    st->size = 0;

    return st;
}

int Stack_Push(struct Stack* st, void* buffer) {
    assert(st != NULL);
    assert(st->vect != NULL);
    assert(buffer != NULL);

    if (st->size >= st->vect->capacity) {
        Vector_Realloc(st->vect, st->vect->capacity * MULTIPLIER);
    }

    *(st->vect->data + st->size) = *((data_type*) buffer);
    st->size++;
    return 1;
}

int Stack_Top(struct Stack* st, void* buffer) {
    assert(st != NULL);
    assert(st->vect != NULL);
    assert(buffer != NULL);

    if (memcpy(buffer, st->vect->data + st->size, sizeof(data_type)) != NULL) {
        return 1;
    }

    return 0;
}

int Stack_Pop(struct Stack* st) {
    assert(st != NULL);
    assert(st->vect != NULL);

    st->vect->data[--st->size] = 0;

    if (st->size * MULTIPLIER <= st->vect->capacity / MULTIPLIER) {
        if(st->vect->capacity >= MIN_CAPACITY * MULTIPLIER) {
            Vector_Realloc(st->vect, st->vect->capacity / MULTIPLIER);
        }
    }

    return 1;
}

struct Stack* Stack_DTR(struct Stack* st) {
    assert(st != NULL);
    assert(st->vect != NULL);

    Clear_Vector(st->vect);
    free(st);

    return NULL;
}
