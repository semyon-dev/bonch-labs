#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "source.h"

/*
        Лабораторная работа 8
        ЛИНЕЙНЫЕ ВЫЧИСЛИТЕЛЬНЫЕ ПОРОЦЕССЫ
        Студент гр. ИКПИ-95
        Новиков С.С.
*/

// Вычислить сумму элементов для каждого столбца.
// Поменять местами столбцы с максимальным и минимальным значением суммы.
// N <= 5, M <= 10

int main() {
    srand(time(0));

    int a[N][M];

    random_array(a);
    printf("Исходный массив a:\n");
    print_array(a);

    int j;
    double sum, min_sum = 9999, max_sum = 0;
    int index_of_column_min = 0, index_of_column_max = 0;
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < M; j++) {
            sum += a[j][i];
        }
        if (sum < min_sum) {
            min_sum = sum;
            index_of_column_min = i;
        } else if (sum > max_sum) {
            max_sum = sum;
            index_of_column_max = i;
        }
        printf("сумма столбца %i равна %lf \n", i, sum);
    }

    printf("max column %i \n", index_of_column_max);
    printf("min column %i \n", index_of_column_min);

    int temp;

    for (int i = 0; i < M; i++) {
        temp = a[index_of_column_min][i];
        a[index_of_column_min][i] = a[index_of_column_max][i];
        a[index_of_column_max][i] = temp;
    }

    printf("Переделанный массив a:\n");
    print_array(a);

    return 0;
}