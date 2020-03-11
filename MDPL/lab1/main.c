#include <stdio.h>

extern int mainA();

__uint8_t a, b, c;
__int16_t chisl, znam, res;

int main() {

    scanf("%hhu", &a);
    scanf("%hhu", &b);
    scanf("%hhu", &c);

    mainA();

    printf("числ: %hd \n", chisl);
    printf("знам: %hd \n", znam);
    printf("результат: %hd \n", res);

    return 0;
}