#ifndef Q_SORT_H_INCLUDED
#define Q_SORT_H_INCLUDED

#include <stdlib.h>

void swap(int* arr, size_t l, size_t r);

void Lomuto_Mid_Q_Sort(int* arr, size_t n);

void Hoar_Mid_Q_Sort(int* arr, size_t n);

void Fat_Mid_Q_Sort(int* arr, size_t n);

size_t Mid_Pivot(int* arr, size_t n);

size_t Median_Pivot(int* arr, size_t n);

size_t Rand_Pivot(int* arr, size_t n);

size_t Rand_Median_Pivot(int* arr, size_t n);

void Hoar_Median_Q_Sort(int* arr, size_t n);

void Hoar_Rand_Q_Sort(int* arr, size_t n);

void Hoar_Rand_Median_Q_Sort(int* arr, size_t n);

#endif // Q_SORT_H_INCLUDED
