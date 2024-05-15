#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Heap_Sort_code/Heap_Sort.h"
#include "../Merge_Sort_code/Merge_Sort.h"
#include "../SD_Sorts_code/SD_Sorts.h"
#include "Testing.h"
#include "../Q_Sort_code/Q_Sort.h"
#include "../Quadratic_Sorts_code/Quadratic_Sort.h"

int main(int argc, char* argv[]) {
    char* dir = argv[1];
    char* sort = argv[2];
    char* res = argv[3];
    int from = atoi(argv[4]);
    int to = atoi(argv[5]);
    int step = atoi(argv[6]);

    if (strcmp(sort, "Bubble_Sort") == 0)
        testing(dir, Bubble_Sort, res, from, to, step);
    else if (strcmp(sort, "Selection_Sort") == 0)
        testing(dir, Selection_Sort, res, from, to, step);
    else if (strcmp(sort, "Insertion_Sort") == 0)
        testing(dir, Insertion_Sort, res, from, to, step);
    else if (strcmp(sort, "Shell_Sort") == 0)
        testing(dir, Shell_Sort, res, from, to, step);

    else if (strcmp(sort, "Heap_Sort_2") == 0)
        testing(dir, Heap_Sort_2, res, from, to, step);
    else if (strcmp(sort, "Heap_Sort_3") == 0)
        testing(dir, Heap_Sort_3, res, from, to, step);
    else if (strcmp(sort, "Heap_Sort_4") == 0)
        testing(dir, Heap_Sort_4, res, from, to, step);
    else if (strcmp(sort, "Heap_Sort_5") == 0)
        testing(dir, Heap_Sort_5, res, from, to, step);
    else if (strcmp(sort, "Heap_Sort_6") == 0)
        testing(dir, Heap_Sort_6, res, from, to, step);
    else if (strcmp(sort, "Heap_Sort_7") == 0)
        testing(dir, Heap_Sort_7, res, from, to, step);
    else if (strcmp(sort, "Heap_Sort_8") == 0)
        testing(dir, Heap_Sort_8, res, from, to, step);
    else if (strcmp(sort, "Heap_Sort_9") == 0)
        testing(dir, Heap_Sort_9, res, from, to, step);
    else if (strcmp(sort, "Heap_Sort_10") == 0)
        testing(dir, Heap_Sort_10, res, from, to, step);

    else if (strcmp(sort, "Recursive_Merge_Sort") == 0)
        testing(dir, Recursive_Merge_Sort, res, from, to, step);
    else if (strcmp(sort, "Iterative_Merge_Sort") == 0)
        testing(dir, Iterative_Merge_Sort, res, from, to, step);

    else if (strcmp(sort, "Lomuto_Mid_Q_Sort") == 0)
        testing(dir, Lomuto_Mid_Q_Sort, res, from, to, step);
    else if (strcmp(sort, "Hoar_Mid_Q_Sort") == 0)
        testing(dir, Hoar_Mid_Q_Sort, res, from, to, step);
    else if (strcmp(sort, "Fat_Mid_Q_Sort") == 0)
        testing(dir, Fat_Mid_Q_Sort, res, from, to, step);
    else if (strcmp(sort, "Hoar_Median_Q_Sort") == 0)
        testing(dir, Hoar_Median_Q_Sort, res, from, to, step);
    else if (strcmp(sort, "Hoar_Rand_Q_Sort") == 0)
        testing(dir, Hoar_Rand_Q_Sort, res, from, to, step);
    else if (strcmp(sort, "Hoar_Rand_Median_Q_Sort") == 0)
        testing(dir, Hoar_Rand_Median_Q_Sort, res, from, to, step);

    else if (strcmp(sort, "LSD_Sort") == 0)
        testing(dir, LSD_Sort, res, from, to, step);
    else if (strcmp(sort, "MSD_Sort") == 0)
        testing(dir, MSD_Sort, res, from, to, step);

    else
        printf("Wrong Sort: %s\n", sort);
    printf("End!");
}
