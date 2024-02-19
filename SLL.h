#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

const size_t ELEM_NUM = 1;

typedef int data_type;

struct elem_of_SLL {
    data_type elem;
    struct elem_of_SLL* next;
};

typedef struct elem_of_SLL* SLL;

SLL Create_SLL();

SLL New(SLL list);

SLL Delete_Last(SLL list);

void Clear_SLL(SLL list);

#endif // SLL_H_INCLUDED
