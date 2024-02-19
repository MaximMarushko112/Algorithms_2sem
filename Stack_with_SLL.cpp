#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SLL.h"
#include "Stack_with_SLL.h"

struct Stack* Stack_CTR() {
    struct Stack* st = (struct Stack*) calloc(1, sizeof(struct Stack));
    assert(st != NULL);

    st->size = 0;

    return st;
}

int Stack_Push(struct Stack* st, void* buffer) {
    assert(st != NULL);
    assert(buffer != NULL);

    if (st->size == 0) {
        st->data = Create_SLL();
    }
    else {
        st->data = New(st->data);
    }

    st->size++;
    if (memcpy(&(st->data->elem), buffer, sizeof(data_type)) != NULL) {
        return 1;
    }

    return 0;
}

int Stack_Top(struct Stack* st, void* buffer) {
    assert(st != NULL);
    assert(buffer != NULL);

    if (memcpy(buffer, &(st->data->elem), sizeof(data_type)) != NULL) {
        return 1;
    }

    return 0;
}

int Stack_Pop(struct Stack* st) {
    assert(st != NULL);

    st->data = Delete_Last(st->data);
    st->size--;

    return 1;
}

struct Stack* Stack_DTR(struct Stack* st) {
    assert(st != NULL);

    Clear_SLL(st->data);
    free(st);

    return NULL;
}
