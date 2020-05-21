//
// Created by semyon on 21.05.2020.
//
//   a*b-1           , если a > b
//    -1            , a = b
//   a/b+2           , если a < b

#include <stdio.h>

extern int signedF();

extern int unsignedF();

__int16_t a_sig;
__int16_t b_sig;

__int16_t a_unsig;
__int16_t b_unsig;
__int16_t x_return; // результат

int sig() {
    int data;
    printf("a: ");
    scanf("%i", &data);
    a_sig = data;

    printf("b: ");
    scanf("%i", &data);
    b_sig = data;

    signedF();

    return x_return;
}

int unsig() {
    int data;
    printf("a: ");
    scanf("%i", &data);
    a_unsig = data;

    printf("b: ");
    scanf("%i", &data);
    b_unsig = data;

    unsignedF();

    return x_return;
}

int main() {

    setbuf(stdout, NULL);

    int mode;
    printf("1 Знаковый\n");
    printf("2 Беззнаковый\n");
    printf("Enter mode: ");
    scanf("%i", &mode);

    switch (mode) {
        case (1): {
            printf("x: %i\n", sig());
            break;
        }
        case (2): {
            printf("x: %i\n", unsig());
            break;
        }
        default:
            break;
    }

    return 0;
}
