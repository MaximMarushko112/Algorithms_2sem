#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MULTIPLIER = 2;
const size_t MIN_CAPACITY = 16;
const size_t BUFFER_LEN = 6;

typedef int data_type;

struct Vector {
    data_type* data;
    size_t capacity;
};

typedef struct Vector Vector;

struct Stack {
    Vector* vect;
    size_t size;
};

Vector* Create_Vector(size_t capacity);

void Vector_Realloc(Vector* vect, size_t new_capacity);

void Clear_Vector(Vector* vect);

struct Stack* Stack_CTR(size_t size);

int Stack_Push(struct Stack* st, void* buffer);

int Stack_Back(struct Stack* st, void* buffer);

int Stack_Pop(struct Stack* st);

struct Stack* Stack_DTR(struct Stack* st);

int main() {
    char buffer[BUFFER_LEN] = "";
    data_type x = 0;
    struct Stack* st= Stack_CTR(100);
    assert(st != NULL);

    while(strcmp(buffer, "exit") != 0) {
        scanf("%6s", buffer);
        if (strcmp(buffer, "push") == 0) {
            int checker = scanf("%d", &x);
            assert(checker != 1);
            Stack_Push(st, &x);
            printf("ok\n");
        }
        else if (strcmp(buffer, "pop") == 0) {
            if (st->size == 0) {
                printf("error\n");
            }
            else {
                Stack_Back(st, &x);
                Stack_Pop(st);
                printf("%d\n", x);
            }
        }
        else if (strcmp(buffer, "back") == 0) {
            if (st->size == 0) {
                printf("error\n");
            }
            else {
                Stack_Back(st, &x);
                printf("%d\n", x);
            }
        }
        else if (strcmp(buffer, "size") == 0) {
            printf("%d\n", st->size);
        }
        else if (strcmp(buffer, "clear") == 0) {
            st->size = 0;
            printf("ok\n");
        }
    }
    printf("bye\n");

    st = Stack_DTR(st);
    return 0;
}

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

struct Stack* Stack_CTR(size_t size) {
    struct Stack* st = (struct Stack*) calloc(1, sizeof(struct Stack));
    assert(st != NULL);

    st->vect = Create_Vector(size);
    st->size = 0;

    return st;
}

int Stack_Push(struct Stack* st, void* buffer) {
    assert(st != NULL);
    assert(st->vect != NULL);
    assert(buffer != NULL);

    if (st->size >= st->vect->capacity) {
        Vector_Realloc(st->vect, st->vect->capacity * MULTIPLIER);
    }

    *(st->vect->data + st->size) = *((data_type*) buffer);
    st->size++;
    return 1;
}

int Stack_Back(struct Stack* st, void* buffer) {
    assert(st != NULL);
    assert(st->vect != NULL);
    assert(buffer != NULL);

    if (memcpy(buffer, st->vect->data + st->size - 1, sizeof(data_type)) != NULL) {
        return 1;
    }

    return 0;
}

int Stack_Pop(struct Stack* st) {
    assert(st != NULL);
    assert(st->vect != NULL);

    st->vect->data[--st->size] = 0;

    if (st->size * MULTIPLIER <= st->vect->capacity / MULTIPLIER) {
        if(st->vect->capacity >= MIN_CAPACITY * MULTIPLIER) {
            Vector_Realloc(st->vect, st->vect->capacity / MULTIPLIER);
        }
    }

    return 1;
}

struct Stack* Stack_DTR(struct Stack* st) {
    assert(st != NULL);
    assert(st->vect != NULL);

    Clear_Vector(st->vect);
    free(st);

    return NULL;
}
