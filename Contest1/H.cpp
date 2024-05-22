#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b);
void swap(const void* first, const void* second);
void Hoar_Mid_Q_Sort(int* arr, size_t n, int (*cmp)(const void* a, const void* b));
void Partition(size_t* l, size_t* r, int* arr, size_t n, int (*cmp)(const void* a, const void* b));

int main() {
    size_t n = 0;
    int checker = scanf("%lu", &n);
    assert(checker != 1);
    int* arr = (int*) calloc(n, sizeof(int));
    assert(arr != NULL);
    for (size_t i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    Hoar_Mid_Q_Sort(arr, n, cmp);
    for (size_t i = 0; i < n - 1; i++) 
        printf("%d ", arr[i]);
    printf("%d", arr[n - 1]);

    free(arr);
}

int cmp(const void* a, const void* b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

void swap(const void* first, const void* second) {
    int t = *(int*)first;
    *(int*)first = *(int*)second;
    *(int*)second = t;
}

void Hoar_Mid_Q_Sort(int* arr, size_t n, int (*cmp)(const void* a, const void* b)) {
    assert(arr != NULL);
    
    while (n != 0) {
        if (n <= 1) {
            return;
        }
        else if (n == 2) {
            if (cmp(arr, arr + 1) > 0) {
                swap(arr, arr + 1);
            }
            return;
        }
        size_t l = 0, r = n - 1;
        Partition(&l, &r, arr, n, cmp);
        Hoar_Mid_Q_Sort(arr, r + 1, cmp);
        arr += r;
        n -= r;
    }
}

void Partition(size_t* l, size_t* r, int* arr, size_t n, int (*cmp)(const void* a, const void* b)) {
    size_t pivot = n / 2;
    while (*l < *r) {
        while (cmp(arr + *l, arr + pivot) < 0) {
            (*l)++;
        }
        while (cmp(arr + *r, arr + pivot) > 0) {
            (*r)--;
        }
        if (*l >= *r) {
            break;
        }
        else {
            swap(arr + *l, arr + *r);
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