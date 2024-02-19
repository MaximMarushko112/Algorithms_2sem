#ifndef STACK_WITH_DA_H_INCLUDED
#define STACK_WITH_DA_H_INCLUDED

#include "Dynamic_Array.h"

const size_t MIN_CAPACITY = 16;

struct Stack {
    DA* data;
    size_t size;
};

struct Stack* stack_ctr(size_t size);

int push(struct Stack* st, void* buffer);

int top(struct Stack* st, void* buffer);

int pop(struct Stack* st);

struct Stack* stack_dtr(struct Stack* st);

#endif // STACK_WITH_DA_H_INCLUDED
