#ifndef LABS_SOURCE_H
#define LABS_SOURCE_H
#endif

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void random_array(double mas[], int n) {
    for (int i = 0; i < n; i++) {
        mas[i] = 1 + rand() % 10;
    }
}

void print_array(double mas[], int n) {
    for (int i = 0; i < n; i++)
        printf("arr[%i]=%4.3lf \n", i, mas[i]);
}