#ifndef DYNAMIC_ARRAY_H_INCLUDED
#define DYNAMIC_ARRAY_H_INCLUDED

const int MULTIPLIER = 2;

typedef int data_type;

struct DA {
    data_type* array;
    size_t capacity;
};

typedef struct DA DA;

DA* Create_DA(size_t capacity);

void Realloc_Down(DA* array);

void Realloc_Up(DA* array);

void Clear_DA(DA* array);

#endif // DYNAMIC_ARRAY_H_INCLUDED
