#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* arr, size_t l, size_t r);
void Hoar_Mid_Q_Sort(int* arr, size_t n);
void Partition(size_t* l, size_t* r, int* arr, size_t n);

int main() {
    size_t n = 0;
    int checker = scanf("%lu", &n);
    assert(checker != 1);
    int* arr = (int*) calloc(n, sizeof(int));
    assert(arr != NULL);
    for (size_t i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    Hoar_Mid_Q_Sort(arr, n);
    for (size_t i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d ", arr[i]);
        }
        else {
            printf("%d", arr[i]);
        }
    }

    free(arr);
}

void swap(int* arr, size_t l, size_t r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

void Hoar_Mid_Q_Sort(int* arr, size_t n) {
    assert(arr != NULL);
    
    while (n != 0) {
        if (n <= 1) {
            return;
        }
        else if (n == 2) {
            if (arr[0] > arr[1]) {
                swap(arr, 0, 1);
            }
            return;
        }
        size_t l = 0, r = n - 1;
        Partition(&l, &r, arr, n);
        Hoar_Mid_Q_Sort(arr, r + 1);
        arr += r;
        n -= r;
    }
}

void Partition(size_t* l, size_t* r, int* arr, size_t n) {
    size_t pivot = n / 2;
    int piv = arr[pivot];
    while (*l < *r) {
        while (arr[*l] < piv) {
            (*l)++;
        }
        while (arr[*r] > piv) {
            (*r)--;
        }
        if (*l >= *r) {
            break;
        }
        else {
            swap(arr, *l, *r);
            (*l)++;
            (*r)--;
        }
    }
    if (*r <= 1) {
        *r = 1;
    }
    else if (*r >= n - 2) {
        *r = n - 2;
    }
}