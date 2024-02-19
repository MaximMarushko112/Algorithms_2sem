#ifndef STACK_WITH_SLL_H_INCLUDED
#define STACK_WITH_SLL_H_INCLUDED

#include "SLL.h"

struct Stack {
    SLL data;
    size_t size;
};

struct Stack* stack_ctr();

int push(struct Stack* st, void* buffer);

int top(struct Stack* st, void* buffer);

int pop(struct Stack* st);

struct Stack* stack_dtr(struct Stack* st);

#endif // STACK_WITH_SLL_H_INCLUDED
