#include <stdio.h>

extern int int8();

extern int uint8();

extern int int16();

extern int uint16();

__uint8_t au8, bu8, cu8;
__uint16_t au16, bu16, cu16;
__int8_t a8int, b8int, c8int;
__int16_t a16int, b16int, c16int;

__int16_t chisl, znam, res;
__int16_t chislC, znamC, resC;

__uint8_t choose;

void check(__int16_t a, __int16_t b, __int16_t c) {
    // (-74/a+c-5)/(1+c*b/2)
    chislC = ((-74 / a) + c - 5);
    znamC = (1 + c * b / 2);
    resC = chislC / znamC;
}

int main() {

    setbuf(stdout, NULL);

    printf("Выберите тип входных данных: \n");
    printf("1 - int8 \n");
    printf("2 - uint8 \n");
    printf("3 - int16 \n");
    printf("4 - uint16 \n");

    scanf("%hhu", &choose);

    printf("Теперь введите a,b,c: \n");

    switch (choose) {
        case 1:
            scanf("%hhi", &a8int);
            scanf("%hhi", &b8int);
            scanf("%hhi", &c8int);
            check(a8int, b8int, c8int);
            int8();
            break;
        case 2:
            scanf("%hhu", &au8);
            scanf("%hhu", &bu8);
            scanf("%hhu", &cu8);
            check(au8, bu8, cu8);
            uint8();
            break;
        case 3:
            scanf("%hi", &a16int);
            scanf("%hi", &b16int);
            scanf("%hi", &c16int);
            check(a16int, b16int, c16int);
            int16();
            break;
        case 4:
            scanf("%hu", &au16);
            scanf("%hu", &bu16);
            scanf("%hu", &cu16);
            check(au16, bu16, cu16);
            uint16();
            break;
        default:
            printf("Такого параметра нет \n");
            return 0;
    }

    printf("Решаем: (-74/a+c-5)/(1+c*b/2) \n");
    printf("Числитель: %hi \n", chisl);
    printf("Знаменатель: %hi \n", znam);
    printf("Результат: %hi \n", res);
    printf("Проверка через си: \n");
    printf("Числитель: %hi \n", chislC);
    printf("Знаменатель: %hi \n", znamC);
    printf("Результат: %hi \n", resC);

    return 0;
}