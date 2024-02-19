#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

const int MULTIPLIER = 2;

typedef int data_type;

struct Vector {
    data_type* data;
    size_t capacity;
};

typedef struct Vector Vector;

Vector* Create_Vector(size_t capacity);

void Vector_Realloc(Vector* vect, size_t new_capacity);

void Clear_Vector(Vector* vect);

#endif // VECTOR_H_INCLUDED
