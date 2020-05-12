//
// Created by semyon on 12.05.2020.
//
// Написать функцию пользователя, позволяющую выполнять решение задачи табулирования для произвольной функции одного переменного.
// Табулируемая функция передается через параметр табулирующей функции.
// Результаты табулирования выводятся на экран монитора.
#include <stdio.h>

typedef double(*function)(double x);

void tab(function f) {
    for (double i = -1000; i < 1000; i++) {
        printf("%lf \n", f(i));
    }
}

double f(double x) {
    return x * 2;
}

double f2(double x) {
    return x * x;
}

int main() {
    tab(&f);
    tab(&f2);
}
