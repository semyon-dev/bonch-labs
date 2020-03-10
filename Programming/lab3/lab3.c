#include <stdio.h>
#include <math.h>

/*
        Лабораторная работа 3
        ЛИНЕЙНЫЕ ВЫЧИСЛИТЕЛЬНЫЕ ПОРОЦЕССЫ
        Студент гр. ИКПИ-95
        Новиков С.С.
*/

int main() {
    float n = 0;
    float x1 = 0, x2 = 0, a = 0, step = 0, y = 0;
    printf("ввод  n, a, x1, x2, \n");
    scanf("%f %f %f %d", &n, &a, &x1, &x2);
    step = (x2 - x1) / (n - 1);

    printf("num \t\t x \t\t\t y\n");

    for (int i = 0; i < n; i++) {
        y = (pow( sin(x1), 5) + a * x1) / (x1 + pow(cos(x1), 5));
        printf("%d \t\t %.4f \t\t %.4f\n", i + 1, x1, y);
        x1 += step;
    }
    return 0;
}
