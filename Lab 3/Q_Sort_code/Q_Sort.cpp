#include <stdio.h>
#include "Q_Sort.h"

void swap(int* arr, size_t l, size_t r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

void Hoar(int* arr, size_t l, size_t r, int piv) {
    while (l < r) {
        while (arr[l] < piv) {
            l++;
        }
        while (arr[r] > piv) {
            r--;
        }
        if (l >= r) {
            break;
        }
        else {
            swap(arr, l, r);
            l++;
            r--;
        }
    }
}

size_t Mid_Pivot(int* arr, size_t n) {
    return n / 2;
}

size_t Median_Pivot(int* arr, size_t n) {
    if ((arr[0] < arr[n / 2] && arr[n / 2] < arr[n - 1]) || (arr[0] > arr[n / 2] && arr[n / 2] > arr[n - 1])) {
        return n / 2;
    }
    else if ((arr[n / 2] < arr[0] && arr[0] < arr[n - 1]) || (arr[n / 2] > arr[0] && arr[0] > arr[n - 1])) {
        return 0;
    }
    return n - 1;
}

size_t Rand_Pivot(int* arr, size_t n) {
    return rand() % n;
}

size_t Rand_Median_Pivot(int* arr, size_t n) {
    int a = rand() % n;
    int b = rand() % n;
    int c = rand() % n;
    if ((arr[a] < arr[b] && arr[b] < arr[c]) || (arr[a] > arr[b] && arr[b] > arr[c])) {
        return b;
    }
    else if ((arr[b] < arr[a] && arr[a] < arr[c]) || (arr[b] > arr[a] && arr[a] > arr[c])) {
        return a;
    }
    return c;
}

void Lomuto_Mid_Q_Sort(int* arr, size_t n) {
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
        size_t l = 0, pivot = Mid_Pivot(arr, n);
        int piv = arr[pivot];
        swap(arr, pivot, n - 1);
        for (size_t r = 0; r < n; r++) {
            if (arr[r] < piv) {
                swap(arr, r, l);
                l++;
            }
        }
        swap(arr, n - 1, l);
        if (l < 1) {
            l = 1;
        }
        Lomuto_Mid_Q_Sort(arr, l);
        arr += l;
        n -= l;
    }
}

void Hoar_Mid_Q_Sort(int* arr, size_t n) {
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
        size_t l = 0, r = n - 1, pivot = Mid_Pivot(arr, n);
        int piv = arr[pivot];
        Hoar(arr, l, r, piv);
        if (r <= 1) {
            r = 1;
        }
        else if (r >= n - 2) {
            r = n - 2;
        }
        Hoar_Mid_Q_Sort(arr, r + 1);
        arr += r;
        n -= r;
    }
}

void Fat_Mid_Q_Sort(int* arr, size_t n) {
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
        size_t pivot = Mid_Pivot(arr, n);
        int piv = arr[pivot];
        size_t l = 0, mid = 0, r = n - 1;
        while (mid <= r) {
            if (arr[mid] < piv) {
                swap(arr, l, mid);
                l++;
                mid++;
            }
            else if (arr[mid] == piv) {
                mid++;
            }
            else {
                swap(arr, mid, r);
                r--;
            }
        }
        Fat_Mid_Q_Sort(arr, l);
        arr += r + 1;
        n -= r + 1;
    }
}

void Hoar_Median_Q_Sort(int* arr, size_t n) {
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
        size_t l = 0, r = n - 1, pivot = Median_Pivot(arr, n);
        int piv = arr[pivot];
        Hoar(arr, l, r, piv);
        if (r <= 1) {
            r = 1;
        }
        else if (r >= n - 2) {
            r = n - 2;
        }
        Hoar_Median_Q_Sort(arr, r + 1);
        arr += r;
        n -= r;
    }
}

void Hoar_Rand_Q_Sort(int* arr, size_t n) {
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
        size_t l = 0, r = n - 1, pivot = Rand_Pivot(arr, n);
        int piv = arr[pivot];
        Hoar(arr, l, r, piv);
        if (r <= 1) {
            r = 1;
        }
        else if (r >= n - 2) {
            r = n - 2;
        }
        Hoar_Rand_Q_Sort(arr, r + 1);
        arr += r;
        n -= r;
    }
}

void Hoar_Rand_Median_Q_Sort(int* arr, size_t n) {
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
        size_t l = 0, r = n - 1, pivot = Rand_Median_Pivot(arr, n);
        int piv = arr[pivot];
        Hoar(arr, l, r, piv);
        if (r <= 1) {
            r = 1;
        }
        else if (r >= n - 2) {
            r = n - 2;
        }
        Hoar_Rand_Median_Q_Sort(arr, r + 1);
        arr += r;
        n -= r;
    }
}
