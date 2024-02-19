#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Dynamic_Array.h"

DA* Create_DA(size_t capacity) {
    assert(capacity != 0);

    DA* array = (DA*) calloc(1, sizeof(DA));
    assert(array != NULL);

    array->array = (data_type*) calloc(capacity, sizeof(data_type));
    assert(array->array != NULL);

    array->capacity = capacity;
    return array;
}

void Realloc_Down(DA* array) {
    assert(array != NULL);

    array->array = (data_type*) realloc(array->array, array->capacity * sizeof(data_type) / MULTIPLIER);
    assert(array->array != NULL);

    array->capacity /= MULTIPLIER;
}

void Realloc_Up(DA* array) {
    assert(array);

    array->array = (data_type*) realloc(array->array, array->capacity * sizeof(data_type) * MULTIPLIER);
    assert(array->array != NULL);

    array->capacity *= MULTIPLIER;
}

void Clear_DA(DA* array) {
    assert(array != NULL);
    assert(array->array != NULL);

    free(array->array);
    free(array);
}
