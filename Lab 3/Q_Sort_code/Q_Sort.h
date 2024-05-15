#ifndef Q_SORT_H_INCLUDED
#define Q_SORT_H_INCLUDED

#include <stdlib.h>

/**
 * @brief Swaps two elements in an array.
 *
 * @param arr Pointer to the array containing elements to be swapped.
 * @param l Index of the first element.
 * @param r Index of the second element.
 */
void swap(int* arr, size_t l, size_t r);

/**
 * @brief Partitions the array using Hoare's partitioning scheme for quicksort.
 *
 * @param arr Pointer to the array to be partitioned.
 * @param l Starting index of the partition.
 * @param r Ending index of the partition.
 * @param piv Pivot element for partitioning.
 */
void Hoar(int* arr, size_t l, size_t r, int piv);

/**
 * @brief Sorts an array using Lomuto's partitioning scheme with median pivot for quicksort.
 *
 * This function sorts the given array using Lomuto's partitioning scheme with a pivot
 * chosen as the middle element.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Lomuto_Mid_Q_Sort(int* arr, size_t n);

/**
 * @brief Sorts an array using Hoare's partitioning scheme with median pivot for quicksort.
 *
 * This function sorts the given array using Hoare's partitioning scheme with a pivot
 * chosen as the middle element.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Hoar_Mid_Q_Sort(int* arr, size_t n);

/**
 * @brief Sorts an array using Fat Hoare's partitioning scheme with median pivot for quicksort.
 *
 * This function sorts the given array using Fat Hoare's partitioning scheme with a pivot
 * chosen as the middle element.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Fat_Mid_Q_Sort(int* arr, size_t n);

/**
 * @brief Finds the index of the median pivot in an array.
 *
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 * @return Index of the middle pivot.
 */
size_t Mid_Pivot(int* arr, size_t n);

/**
 * @brief Finds the index of the median pivot in an array using median-of-three method.
 *
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 * @return Index of the median pivot.
 */
size_t Median_Pivot(int* arr, size_t n);

/**
 * @brief Finds the index of a random pivot in an array.
 *
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 * @return Index of the random pivot.
 */
size_t Rand_Pivot(int* arr, size_t n);

/**
 * @brief Finds the index of a random median pivot in an array.
 *
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 * @return Index of the random median pivot.
 */
size_t Rand_Median_Pivot(int* arr, size_t n);

/**
 * @brief Sorts an array using Hoare's partitioning scheme with median pivot for quicksort.
 *
 * This function sorts the given array using Hoare's partitioning scheme with a pivot
 * chosen as the median of three elements (first, middle, last).
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Hoar_Median_Q_Sort(int* arr, size_t n);

/**
 * @brief Sorts an array using Hoare's partitioning scheme with random pivot for quicksort.
 *
 * This function sorts the given array using Hoare's partitioning scheme with a random pivot.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Hoar_Rand_Q_Sort(int* arr, size_t n);

/**
 * @brief Sorts an array using Hoare's partitioning scheme with random median pivot for quicksort.
 *
 * This function sorts the given array using Hoare's partitioning scheme with a random median pivot.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Hoar_Rand_Median_Q_Sort(int* arr, size_t n);

#endif // Q_SORT_H_INCLUDED
