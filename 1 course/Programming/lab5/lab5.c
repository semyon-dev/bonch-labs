#include <stdio.h>
#include <math.h>

/*
        Лабораторная работа 5
        ЛИНЕЙНЫЕ ВЫЧИСЛИТЕЛЬНЫЕ ПОРОЦЕССЫ
        Студент гр. ИКПИ-95
        Новиков С.С.
*/

int main() {

    int m, n;
    double x, a, b, y, z, c, s = 0;
    printf("x=");
    scanf("%lf", &x);
    printf("m=");
    scanf("%i", &m);
    printf("n=");
    scanf("%i", &n);

    for (int i = 1; i <= n; i++) {
        y = 0;
        z = 0;
        for (int k = 1; k <= m; k++) {
            a = (1.0 / k) + k;
            y += a;
        }

        for (int j = 1; j <= m; j++) {

            b = pow((x + (j / i)), 2.0);
            z += b;
        }

        c = (1 + (x * y)) / ((3 * i) + z);
        s += c;
    }

    printf("%lf\n", s);
    return 0;
}