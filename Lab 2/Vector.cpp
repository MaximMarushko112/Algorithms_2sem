#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

Vector* Create_Vector(size_t capacity) {
    assert(capacity != 0);

    Vector* vect = (Vector*) calloc(1, sizeof(Vector));
    assert(vect != NULL);

    vect->data = (data_type*) calloc(capacity, sizeof(data_type));
    assert(vect->data != NULL);

    vect->capacity = capacity;
    return vect;
}

void Vector_Realloc(Vector* vect, size_t new_capacity) {
    assert(vect != NULL);

    vect->data = (data_type*) realloc(vect->data, new_capacity * sizeof(data_type));
    assert(vect->data != NULL);

    vect->capacity = new_capacity;
}

void Clear_Vector(Vector* vect) {
    assert(vect != NULL);
    assert(vect->data != NULL);

    free(vect->data);
    free(vect);
}
