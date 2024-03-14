#ifndef SD_SORTS_H_INCLUDED
#define SD_SORTS_H_INCLUDED

#include <stdlib.h>

void LSD_Sort(int* arr, size_t n);

void MSD_Sort(int* arr, size_t n);

void MSD_Recursion(int* arr, size_t n, size_t shift);

#endif // SD_SORTS_H_INCLUDED
