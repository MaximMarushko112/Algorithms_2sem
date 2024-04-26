#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED

#include <stdlib.h>

void testing(char* dir, void (*sort)(int* arr, size_t n), char* results,
             size_t from, size_t to, size_t step);

#endif // TESTING_H_INCLUDED
