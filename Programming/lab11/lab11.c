// Лабораторная работа 11
// Created by Новиков С.С. on 07.05.2020.
// Студент гр. ИКПИ-95
// 17 вариант
//
// В файле хранится числовая матрица. В первой строке файла записаны два числа:
// количество строк и столбцов матрицы, а затем сама матрица.
// Сформировать новый файл, содержащий только те строки исходной матрицы,
// сумма чисел в которых превышает заданную величину.

#include <stdio.h>

int main() {
    int row = 0, column = 0;
    int sum = 0; // заданная величина

    FILE *file_data, *file_result;
    char *filename_data = "data.txt";
    char *filename_result = "result.txt";

    printf("Введите заданную величину: ");
    scanf("%d", &sum);

    // чтение из файла
    if ((file_data = fopen(filename_data, "r")) == NULL) {
        perror("Ошибка при открытии файла с данными, проверьте есть ли файл data.txt!");
        return 1;
    }
    fscanf(file_data, "%d %d\n", &row, &column);
    printf("Строк: %d Колонок: %d\n", row, column);

    if ((file_result = fopen(filename_result, "w")) == NULL) {
        perror("Ошибка при открытии/создании файла result.txt!");
        return 1;
    }

    int t = 0, count = 0;
    for (int j = 0; j < row; j++) {
        int all[column];
        for (int i = 0; i < column; i++) {
            t = 0;
            fscanf(file_data, "%d", &t);
            all[i] = t;
            count += t;
        }
        // если сумма чисел строи больше чем заданная сумма - записываем строку в файл
        if (count > sum) {
            for (int f = 0; f < column; f++) {
                fprintf(file_result, "%d ", all[f]);
            }
            fprintf(file_result, "\n");
        }
    }
    fclose(file_data);
    fclose(file_result);
    printf("Результат сохранен в %s", filename_result);
}