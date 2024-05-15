#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int cmpor(const void* num1, const void* num2);

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    int* arr = (int*) calloc(len, sizeof(int));
    assert(arr != NULL);

    for (int i = 0; i < len; i++) {
        scanf("%d", arr + i);
        if (arr[i] <= 0) {
        }
    }

    qsort(arr, len, sizeof(int), cmpor);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

int cmpor(const void* num1, const void* num2) {
    const int a = *((const int*) num1);
    const int b = *((const int*) num2);
    if (a < b)
        return -1;
    if (a == b)
        return 0;
    return 1;
}
