#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    int max_num = atoi(argv[2]);
    int seed = atoi(argv[3]);
    srand(seed);
    int* arr = (int*) calloc(len, sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % max_num;
        printf("%d ", arr[i]);
    }
    free(arr);
}
