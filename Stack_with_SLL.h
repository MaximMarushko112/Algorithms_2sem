#ifndef STACK_WITH_SLL_H_INCLUDED
#define STACK_WITH_SLL_H_INCLUDED

#include "SLL.h"

struct Stack {
    SLL data;
    size_t size;
};

struct Stack* Stack_CTR();

int Stack_Push(struct Stack* st, void* buffer);

int Stack_Top(struct Stack* st, void* buffer);

int Stack_Pop(struct Stack* st);

struct Stack* Stack_DTR(struct Stack* st);

#endif // STACK_WITH_SLL_H_INCLUDED
