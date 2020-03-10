#include <stdio.h>
#include <math.h>

/*
        Лабораторная работа 2
        ЛИНЕЙНЫЕ ВЫЧИСЛИТЕЛЬНЫЕ ПОРОЦЕССЫ
        Студент гр. ИКПИ-95
        Новиков С.С.
*/

int main() {
    double x, res = 0;
    printf("введите x: ");
    scanf("%lf", &x);
    if (x >= 4 && x < 7) {
        res = log10(1.5 * x);
    } else if (x >= 7) {
        res = pow(sin(x), 4);
    } else if (-3.5 <= x && x < 4) {
        res = 0.5 * exp(0.1 * x);
    } else if (x < -3.5) {
        res = cos(x) / (fabs(x) + 10);
    }
    printf("результат: ");
    printf("%lf", res);
}