#ifndef HEAP_SORT_H_INCLUDED
#define HEAP_SORT_H_INCLUDED

#include <stdlib.h>

/**
 * @brief Performs the Sift Down operation on a heap represented by an array.
 *
 * @param arr Pointer to the array representing the binary heap.
 * @param i Index of the element to perform Sift Down operation.
 * @param len Length of the heap.
 * @param k Size of the heap.
 */
void Sift_Down(int* arr, size_t i, size_t len, size_t k);

/**
 * @brief Sorts an array using the Heap Sort algorithm with a given heap size.
 *
 * This function sorts the given array using the Heap Sort algorithm.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 * @param k Size of the heap.
 */
void Heap_Sort(int* arr, size_t n, size_t k);

/**
 * @brief Sorts an array using the Heap Sort algorithm. Size of heap is 2.
  *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Heap_Sort_2(int* arr, size_t n);

/**
 * @brief Sorts an array using the Heap Sort algorithm. Size of heap is 3.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Heap_Sort_3(int* arr, size_t n);

/**
 * @brief Sorts an array using the Heap Sort algorithm. Size of heap is 4.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Heap_Sort_4(int* arr, size_t n);

/**
 * @brief Sorts an array using the Heap Sort algorithm. Size of heap is 5.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Heap_Sort_5(int* arr, size_t n);

/**
 * @brief Sorts an array using the Heap Sort algorithm. Size of heap is 6.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Heap_Sort_6(int* arr, size_t n);

/**
 * @brief Sorts an array using the Heap Sort algorithm. Size of heap is 7.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Heap_Sort_7(int* arr, size_t n);

/**
 * @brief Sorts an array using the Heap Sort algorithm. Size of heap is 8.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Heap_Sort_8(int* arr, size_t n);

/**
 * @brief Sorts an array using the Heap Sort algorithm. Size of heap is 9.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Heap_Sort_9(int* arr, size_t n);

/**
 * @brief Sorts an array using the Heap Sort algorithm. Size of heap is 10.
 *
 * @param arr Pointer to the array to be sorted.
 * @param n Number of elements in the array.
 */
void Heap_Sort_10(int* arr, size_t n);

#endif // HEAP_SORT_H_INCLUDED
