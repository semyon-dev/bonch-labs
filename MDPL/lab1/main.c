#include <stdio.h>

extern int int8();

extern int uint8();

extern int int16();

extern int uint16();

__uint8_t au8, bu8, cu8;
__uint16_t au16, bu16, cu16;
__int8_t a8, b8, c8;
__int16_t a16int, b16int, c16int;

__int16_t chisl, znam, res;

__uint8_t choose;

int main() {

    setbuf(stdout, NULL);

    printf("Выберите тип входных данных: \n");
    printf("1 - int8 \n");
    printf("2 - uint8 \n");
    printf("3 - int16 \n");
    printf("4 - uint16 \n");

    scanf("%hhu", &choose);

    switch (choose) {
        case 1:
            scanf("%hhi", &a8);
            scanf("%hhi", &b8);
            scanf("%hhi", &c8);
            int8();
            break;
        case 2:
            scanf("%hhu", &au8);
            scanf("%hhu", &bu8);
            scanf("%hhu", &cu8);
            uint8();
            break;
        case 3:
            scanf("%hi", &a16int);
            scanf("%hi", &b16int);
            scanf("%hi", &c16int);
            int16();
            break;
        case 4:
            scanf("%hu", &au16);
            scanf("%hu", &bu16);
            scanf("%hu", &cu16);
            uint16();
            break;
        default:
            printf("Такого параметра");
    }

    printf("числитель: %hi \n", chisl);
    printf("знаменатель: %hi \n", znam);
    printf("результат: %hi \n", res);

    return 0;
}