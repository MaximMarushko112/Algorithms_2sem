#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(size_t* arr, size_t l, size_t r);
void Sift_Down(size_t* arr, size_t pos, size_t len);
void Sift_Up(size_t* arr, size_t pos);
void Line(size_t* arr, size_t len);
void NLog(size_t* arr, size_t len);
void Testing(char* dir, void (*heap)(size_t* arr, size_t len), char* results,
             size_t from, size_t to, size_t step);

int main() {
    Testing("C:\\Users\\PC\\Desktop\\Algorithms_2sem\\Lab 4\\tests", Line,
     "C:\\Users\\PC\\Desktop\\Algorithms_2sem\\Lab 4\\Line.out", 100000, 1000000, 100000);
    Testing("C:\\Users\\PC\\Desktop\\Algorithms_2sem\\Lab 4\\tests", NLog,
     "C:\\Users\\PC\\Desktop\\Algorithms_2sem\\Lab 4\\NLog.out", 100000, 1000000, 100000);
}

void swap(size_t* arr, size_t l, size_t r) {
    size_t temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

void Sift_Down(size_t* arr, size_t pos, size_t len) {
    int flag = 1;
    while (flag) {
        if (2 * pos + 2 < len) {
            size_t max = 0;
            if (arr[2 * pos + 1] < arr[2 * pos + 2]) {
                max = 2 * pos + 2;
            }
            else {
                max = 2 * pos + 1;
            }
            if (arr[pos] < arr[max]) {
                swap(arr, pos, max);
                pos = max;
            }
            else {
                flag = 0;
                break;
            }
        }
        else if (2 * pos + 1 < len) {
            if (arr[pos] < arr[2 * pos + 1]) {
                swap(arr, pos, 2 * pos + 1);

            }
            flag = 0;
            break;
        }
        else {
            flag = 0;
            break;
        }

    }
}

void Sift_Up(size_t* arr, size_t pos) {
    while (pos != 0) {
        if (arr[pos] > arr[(pos - 1) / 2]) {
            swap(arr, pos, (pos - 1) / 2);
            pos = (pos - 1) / 2;
        }
        else {
            break;
        }
    }
}

void Line(size_t* arr, size_t len) {
    for (int i = len / 2; i >= 0; i--) {
        Sift_Down(arr, i, len);
    }
}

void NLog(size_t* arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        Sift_Up(arr, i);
    }
}

void Testing(char* dir, void (*heap)(size_t* arr, size_t len), char* results,
             size_t from, size_t to, size_t step) {
    FILE* res = fopen(results, "w");
    for (size_t i = from; i <= to; i += step) {
        double time = 0;
        for (char j = 1; j <= 5; j++) {
            char* file = (char*) calloc(strlen(dir) + 30, sizeof(char));
            char* file_in = (char*) calloc(strlen(dir) + 30, sizeof(char));
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

            size_t* arr = (size_t*) calloc(i, sizeof(size_t));
            for (size_t x = 0; x < i; x++) {
                fscanf(input, "%d", arr + x);
            }

            clock_t start = clock();
            (*heap)(arr, i);
            clock_t finish = clock();
            time += (double) ((finish - start) / ((double) CLOCKS_PER_SEC / 1000));

            fclose(input);
            free(file);
            free(file_in);
            free(arr);
        }
        fprintf(res, "%d %2.3f\n", i, time / 5.0);
        printf("%d %2.3f\n", i, time / 5.0);
    }
    fclose(res);
}
