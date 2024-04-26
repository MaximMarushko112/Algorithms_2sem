#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Testing.h"

void testing(char* dir, void (*sort)(int* arr, size_t n), char* results,
             size_t from, size_t to, size_t step) {
    FILE* res = fopen(results, "w");
    for (size_t i = from; i <= to; i += step) {
        double time = 0;
        for (char j = 1; j <= 5; j++) {
            char* file = (char*) calloc(strlen(dir) + 30, sizeof(char));
            char* file_in = (char*) calloc(strlen(dir) + 30, sizeof(char));
            char* file_out = (char*) calloc(strlen(dir) + 30, sizeof(char));
            file = strcpy(file, dir);
            file = strcat(file, "\\{");
            char* num = (char*) calloc(8, sizeof(char));
            int flag = 0, k = 1000000, l = 0;
            while (k > 0) {
                int digit = i % (k * 10) / k;
                if (digit != 0) {
                    num[l] = '0' + digit;
                    flag = 1;
                    l++;
                }
                else if (flag != 0 || k == 0) {
                    num[l] = '0';
                    l++;
                }
                k /= 10;
            }
            file = strcat(file, num);
            file = strcat(file, "}_{");
            char digit[2] = "0";
            digit[0] = '0' + j;
            file = strcat(file, digit);
            file = strcat(file, "}.");
            file_in = strcpy(file_in, file);
            file_in = strcat(file_in, "in");
            FILE* input = fopen(file_in, "r");

            int* arr = (int*) calloc(i, sizeof(int));
            for (size_t x = 0; x < i; x++) {
                fscanf(input, "%d", arr + x);
            }

            clock_t start = clock();
            (*sort)(arr, i);
            clock_t finish = clock();
            time += (double) ((finish - start) / (double) CLOCKS_PER_SEC * 1000000);

            file_out = strcpy(file_out, file);
            file_out = strcat(file_out, "out");
            FILE* output = fopen(file_out, "r");
            int answer = 0;
            for (size_t x = 0; x < i; x++) {
                fscanf(output, "%d", &answer);
                //printf("%d %d\n", arr[x], answer);
                assert(arr[x] == answer);
            }

            fclose(input);
            fclose(output);
            free(file);
            free(file_in);
            free(file_out);
            free(arr);
        }
        fprintf(res, "%d %2.10f\n", i, time / 5.0);
        printf("%d %2.10f\n", i, time / 5.0);
    }
    fclose(res);
}

