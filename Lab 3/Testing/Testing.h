#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED

#include <stdlib.h>

/**
 * @brief Performs testing of a sorting algorithm.
 *
 * This function conducts testing of a sorting algorithm by sorting arrays of various sizes
 * and recording the results.
 *
 * @param dir Directory where the tests are stored.
 * @param sort Pointer to the sorting function to be tested.
 * @param results Name of the file where the results will be stored.
 * @param from Starting size of the arrays to be tested.
 * @param to Ending size of the arrays to be tested.
 * @param step Step size for increasing the array sizes during testing.
 */
void testing(char* dir, void (*sort)(int* arr, size_t n), char* results,
             size_t from, size_t to, size_t step);

#endif // TESTING_H_INCLUDED
