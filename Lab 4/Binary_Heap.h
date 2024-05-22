#ifndef BINARY_HEAP_H_INCLUDED
#define BINARY_HEAP_H_INCLUDED

#include <stdlib.h>

void swap(size_t* arr, size_t l, size_t r);

void Sift_Down(size_t* arr, size_t pos, size_t len);

void Sift_Up(size_t* arr, size_t pos);

void Line(size_t* arr, size_t len);

void NLog(size_t* arr, size_t len);

void Testing(char* dir, void (*heap)(size_t* arr, size_t len), char* results,
             size_t from, size_t to, size_t step);

#endif