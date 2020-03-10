#include <stdio.h>
#include <math.h>

/*
        Лабораторная работа 1
        ЛИНЕЙНЫЕ ВЫЧИСЛИТЕЛЬНЫЕ ПОРОЦЕССЫ
        Студент гр. ИКПИ-95
        Новиков С.С.
*/

int main() {
    double x,a,b;
    printf("введите x\n");
    scanf("%lf", &x);
    printf("введите a\n");
    scanf("%lf", &a);
    printf("введите b\n");
    scanf("%lf", &b);

    double y = sqrt(fabs(cos(x)+3))/3;
    double p = pow(y + 15 * a, 1.0/4);
    double z = (sin(b)+p)/p;

    //Вывод результатов
    printf("%lf\n", y);
    printf("%lf\n",z);
    return 0;
}