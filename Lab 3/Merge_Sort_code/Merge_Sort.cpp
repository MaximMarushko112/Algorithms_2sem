#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Merge_Sort.h"

void Recursive_Merge_Sort(int* arr, size_t n) {
    if (n > 2) {
        Recursive_Merge_Sort(arr, n / 2);
        Recursive_Merge_Sort(arr + n / 2, n - n / 2);
        size_t i1 = 0, i2 = 0;
        int* merge = (int*) calloc(n, sizeof(int));
        assert(merge != NULL);
        while (i1 < n / 2 && i2 < n - n / 2) {
            if (arr[i1] < arr[n / 2 + i2]) {
                merge[i1 + i2] = arr[i1++];
            }
            else {
                merge[i1 + i2] = arr[n / 2 + i2++];
            }
        }
        while (i1 < n / 2) {
            merge[i1 + i2] = arr[i1++];
        }
        while (i2 < n - n / 2) {
            merge[i1 + i2] = arr[n / 2 + i2++];
        }
        for (size_t i = 0; i < n; i++) {
            arr[i] = merge[i];
        }
        free(merge);
    }
    else if (n == 2) {
        if (arr[0] > arr[1]) {
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
    }

}

void Iterative_Merge_Sort(int* arr, size_t n) {
    int* buffer = (int*) calloc(n, sizeof(int));
    assert(buffer != NULL);
    for (size_t len = 1; len < n; len *= 2) {
        for (size_t i = 0; i < n - len; i += 2 * len) {
            size_t i1 = 0, i2 = 0;
            while (i1 < len && i2 < len && i2 < n - i - len) {
                if (arr[i + i1] < arr[i + len + i2]) {
                    buffer[i1 + i2] = arr[i + i1];
                    i1++;
                }
                else {
                    buffer[i1 + i2] = arr[i + len + i2];
                    i2++;
                }
            }
            while (i1 < len) {
                buffer[i1 + i2] = arr[i + i1];
                i1++;
            }
            while (i2 < len && i2 < n - i - len) {
                buffer[i1 + i2] = arr[i + len + i2];
                i2++;
            }
            if (2 * len < n - i) {
                memcpy(arr + i, buffer, 2 * len * sizeof(int));
            }
            else {
                memcpy(arr + i, buffer, (n - i) * sizeof(int));
            }
        }
    }
    free(buffer);
}
