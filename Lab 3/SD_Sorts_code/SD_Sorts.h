#ifndef SD_SORTS_H_INCLUDED
#define SD_SORTS_H_INCLUDED

#include <stdlib.h>

/**
 * @brief Sorts an array using the Least Significant Digit (LSD) radix sort algorithm.
 *
 * This function sorts the given array using the LSD radix sort algorithm.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void LSD_Sort(int* arr, size_t n);

/**
 * @brief Sorts an array using the Most Significant Digit (MSD) radix sort algorithm.
 *
 * This function sorts the given array using the MSD radix sort algorithm.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void MSD_Sort(int* arr, size_t n);

/**
 * @brief Performs the recursive step of the MSD radix sort algorithm.
 *
 * This function is used internally by MSD_Sort to perform the recursive step of the MSD radix sort algorithm.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 * @param shift The current bit position being considered.
 */
void MSD_Recursion(int* arr, size_t n, size_t shift);

#endif // SD_SORTS_H_INCLUDED
