#include <stdio.h>
#include <stdlib.h>
#include "Heap_Sort.h"

void Sift_Down(int* arr, size_t i, size_t len, size_t k) {
    while(i * k + 1 < len) {
        size_t x = i * k;
        size_t max = x + 1;
        for (size_t j = 1; j <= k && x + j < len; j++) {
            if (arr[max] < arr[x + j]) {
                max = x + j;
            }
        }
        if (arr[i] < arr[max]) {
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
            i = max;
        }
        else {
            break;
        }
    }
}

void Heap_Sort(int* arr, size_t n, size_t k) {
    for (size_t i = 0; i <= n / k; i++) {
        Sift_Down(arr, n / k - i, n, k);
    }
    for (size_t i = 0; i < n - 1; i++) {
        int temp = arr[0];
        arr[0] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
        Sift_Down(arr, 0, n - 1 - i, k);
    }
}

void Heap_Sort_2(int* arr, size_t n) {
    Heap_Sort(arr, n, 2);
}

void Heap_Sort_3(int* arr, size_t n) {
    Heap_Sort(arr, n, 3);
}

void Heap_Sort_4(int* arr, size_t n) {
    Heap_Sort(arr, n, 4);
}

void Heap_Sort_5(int* arr, size_t n) {
    Heap_Sort(arr, n, 5);
}

void Heap_Sort_6(int* arr, size_t n) {
    Heap_Sort(arr, n, 6);
}

void Heap_Sort_7(int* arr, size_t n) {
    Heap_Sort(arr, n, 7);
}

void Heap_Sort_8(int* arr, size_t n) {
    Heap_Sort(arr, n, 8);
}

void Heap_Sort_9(int* arr, size_t n) {
    Heap_Sort(arr, n, 9);
}

void Heap_Sort_10(int* arr, size_t n) {
    Heap_Sort(arr, n, 10);
}
