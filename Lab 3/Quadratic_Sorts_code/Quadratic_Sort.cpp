#include <stdio.h>
#include <stdlib.h>

#include "Quadratic_Sort.h"

void Bubble_Sort(int* arr, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Selection_Sort(int* arr, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t max = 0;
        for (size_t j = 0; j < n - i; j++) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        int temp = arr[max];
        arr[max] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
        }
    }
}

void Insertion_Sort(int* arr, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else {
                break;
            }
        }
    }
}

void Shell_Sort(int* arr, size_t n) {
    size_t step = 1;
    while (step <= n / 9) {
        step = step * 3 + 1;
    }
    for (; step > 0; step /= 3) {
        for (size_t i = step; i < n; i += step) {
            size_t j = i;
            int temp = arr[i];
            for (; j >= step && arr[j - step] > temp; j -= step) {
                arr[j] = arr[j - step];
            }
            arr[j] = temp;
        }
    }
}
