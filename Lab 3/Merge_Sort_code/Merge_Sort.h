#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED

#include <stdlib.h>

/**
 * @brief Sorts an array using the recursive merge sort algorithm.
 *
 * This function recursively sorts the given array using the merge sort algorithm.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Recursive_Merge_Sort(int* arr, size_t n);

/**
 * @brief Sorts an array using the iterative merge sort algorithm.
 *
 * This function iteratively sorts the given array using the merge sort algorithm.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Iterative_Merge_Sort(int* arr, size_t n);

#endif // MERGE_SORT_H_INCLUDED
