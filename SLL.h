#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

const size_t ELEM_NUM = 1;

typedef int data_type;

struct Elem_of_SLL {
    data_type elem;
    struct Elem_of_SLL* next;
};

typedef struct Elem_of_SLL* SLL;

SLL Create_SLL();

SLL SLL_New_Elem(SLL list);

SLL SLL_Delete_Last(SLL list);

void Clear_SLL(SLL list);

#endif // SLL_H_INCLUDED
