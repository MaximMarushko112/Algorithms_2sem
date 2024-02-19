#ifndef STACK_WITH_VECTOR_H_INCLUDED
#define STACK_WITH_VECTOR_H_INCLUDED

#include "Vector.h"

const size_t MIN_CAPACITY = 16;

struct Stack {
    Vector* vect;
    size_t size;
};

struct Stack* Stack_CTR(size_t size);

int Stack_Push(struct Stack* st, void* buffer);

int Stack_Top(struct Stack* st, void* buffer);

int Stack_Pop(struct Stack* st);

struct Stack* Stack_DTR(struct Stack* st);

#endif // STACK_WITH_VECTOR_H_INCLUDED
