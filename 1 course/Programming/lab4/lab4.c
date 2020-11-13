#include <stdio.h>
#include <math.h>

/*
        Лабораторная работа 4
        ЛИНЕЙНЫЕ ВЫЧИСЛИТЕЛЬНЫЕ ПОРОЦЕССЫ
        Студент гр. ИКПИ-95
        Новиков С.С.
*/

int main() {

    double x, y, s = 1;
    unsigned int n;
    printf("n = ");
    scanf("%i", &n);
    printf("x = ");
    scanf("%lf", &x);

    for (unsigned int i = 1; i <= n; i++) {
        s *= pow((x + 0.8) / x + cos(x * i), 1.0 / i);
        printf("%lf \t\n", s);
    }

    y = 4.2 * x + s; // вычисление конечного значения функции

    printf("y=%0.5f\n", y); // вывод значения y
    return 0;
}
