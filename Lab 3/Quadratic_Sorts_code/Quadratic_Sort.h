#ifndef QUADRATIC_SORT_H_INCLUDED
#define QUADRATIC_SORT_H_INCLUDED

#include <stdlib.h>

/**
 * @brief Sorts an array using the bubble sort algorithm.
 *
 * This function sorts the given array using the bubble sort algorithm.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Bubble_Sort(int* arr, size_t n);

/**
 * @brief Sorts an array using the selection sort algorithm.
 *
 * This function sorts the given array using the selection sort algorithm.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Selection_Sort(int* arr, size_t n);

/**
 * @brief Sorts an array using the insertion sort algorithm.
 *
 * This function sorts the given array using the insertion sort algorithm.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Insertion_Sort(int* arr, size_t n);

/**
 * @brief Sorts an array using the shell sort algorithm.
 *
 * This function sorts the given array using the shell sort algorithm.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Shell_Sort(int* arr, size_t n);

#endif // QUADRATIC_SORT_H_INCLUDED
