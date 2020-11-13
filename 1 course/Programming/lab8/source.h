#ifndef LABS_SOURCE_H
#define LABS_SOURCE_H
#endif

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int N = 3;
const int M = 3;

void random_array(int mas[N][M]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            mas[i][j] = 1 + rand() % 10;
        }
    }
}

void print_array(int mas[N][M]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%i ", mas[j][i]);
        }
        printf("\n");
    }
}