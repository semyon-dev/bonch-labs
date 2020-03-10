#include <stdio.h>

extern int _somefunc();

__uint8_t a;

int main() {
    // (-74/a+c-5)/(1+c*b/2)
    scanf("%hhu", &a);
//    scanf("%i", &b);
//    scanf("%i", &c);

    _somefunc();

    printf("a: %hhu \n", a);
    //printf("RES: %i \n", res);
    return 0;
}