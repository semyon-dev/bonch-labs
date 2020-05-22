// 17 (-74/a+c-5)/(1+c*b/2)
// Вычислить заданное вещественное выражение для исходных данных в форматах Float(SINGLE для переменных a и b)
// и Int(INTEGER - все остальные переменные), используя арифметические операции сопроцессора

#include <stdio.h>

float a_f, b_f, result_f;
int c_i;

extern void ASMCalc();

void CPP() {
    float t1 = (float) (-74.0 / a_f + c_i - 5);
    float t2 = (float) (1.0 + (float) c_i * b_f / 2.0);

    printf("C++ result : %f\n", t1 / t2);
}

void asmCall() {
    ASMCalc();
    printf("ASM result: %f\n", result_f);
}

int main() {
    printf("Enter a: ");
    scanf("%f", &a_f);
    printf("Enter b: ");
    scanf("%f", &b_f);
    printf("Enter c: ");
    scanf("%i", &c_i);

    CPP();
    asmCall();

    return 0;
}