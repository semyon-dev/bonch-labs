#include <stdio.h>
#include <math.h>

/*
        Лабораторная работа 6
        ЛИНЕЙНЫЕ ВЫЧИСЛИТЕЛЬНЫЕ ПОРОЦЕССЫ
        Студент гр. ИКПИ-95
        Новиков С.С.
*/

float s, m, n;

int fun(int n1, int n2, int a3, int a2, int a1, int a0) {
    s = 0;
    float k;
    for (int i = n1; i <= n2; i++) {
        s += a3 * pow(k, 3) + a2 * pow(k, 2) + a1 * k + a0;
    }
    return s;
}

int main() {
    printf("n= ");
    scanf("%f", &n);
    printf("m= ");
    scanf("%f", &m);
    float y = ((3 * fun(2, n, 0, 1, 0, 2) + 2 * fun(3, m, 1, 0, 0, 1)) / (2 + fun(3, m, 2, 0, 1, 2)));
    printf("y= %f", y);
    return 0;
}