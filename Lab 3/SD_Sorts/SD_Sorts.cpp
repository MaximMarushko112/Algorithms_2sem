#include <stdio.h>
#include "SD_Sorts.h"

void LSD_Sort(int* arr, size_t n) {
    unsigned int mask = 255, shift = 0;
    int* res = (int*) calloc(n, sizeof(int));
    for (; mask > 0; mask <<= 8, shift += 8) {
        int byte_nums[256] = {};
        for (size_t i = 0; i < n; i++) {
            byte_nums[(arr[i] & mask) >> shift]++;
        }
        for (size_t i = 1; i < 256; i++) {
            byte_nums[i] += byte_nums[i - 1];
        }
        for (size_t i = 0; i < n; i++) {
            res[--byte_nums[(arr[n - 1 - i] & mask) >> shift]] = arr[n - 1 - i];
        }
        for (size_t i = 0; i < n; i++) {
            arr[i] = res[i];
        }
    }
    free(res);
}

void MSD_Sort(int* arr, size_t n) {
    MSD_Recursion(arr, n, 8 * (sizeof(int) - 1));
}

void MSD_Recursion(int* arr, size_t n, unsigned int shift) {
    if (n == 0) {
        return;
    }
    unsigned int mask = 255 << shift;
    int* res = (int*) calloc(n, sizeof(int));
    int byte_nums[256] = {};
    for (size_t i = 0; i < n; i++) {
        byte_nums[(arr[i] & mask) >> shift]++;
    }
    for (size_t i = 1; i < 256; i++) {
        byte_nums[i] += byte_nums[i -  1];
    }
    for (size_t i = 0; i < n; i++) {
        res[--byte_nums[(arr[n - 1 - i] & mask) >> shift]] = arr[n - 1 - i];
    }
    for (size_t i = 0; i < n; i++) {
        arr[i] = res[i];
    }
    if (shift > 0) {
        MSD_Recursion(arr, byte_nums[0], shift - 8);
        for (size_t i = 1; i < 256; i++) {
            MSD_Recursion(arr + byte_nums[i - 1], byte_nums[i] - byte_nums[i - 1], shift - 8);
        }
    }
    free(res);
}

