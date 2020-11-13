// Найти сколько элементов массива A={a[i]} удовлетворяет условию с <= a[i] <= d

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define len 10
int arr_size = len;

int64_t c, d;

__int64_t my_array[len];

extern uint64_t asmF(int64_t c, int64_t d);

void cMode() {
    uint64_t counter = 0;
    for (uint64_t i = 0; i < arr_size; i++) {
        if (c <= my_array[i] && my_array[i] <= d) {
            counter++;
        }
    }
    printf("Проверка из си: %ld\n", counter);
}

void asmMode() {
    uint64_t sum = asmF(c, d);
    printf("Результат из nasm: %ld\n", sum);
}

int main() {
    for (int64_t i = 0; i < arr_size; i++) {
        my_array[i] = (int64_t) rand() % 21 - 10;
        printf("%ld\n", my_array[i]);
    }

    printf("Enter c: ");
    scanf("%ld", &c);
    printf("Enter d: ");
    scanf("%ld", &d);
    cMode();
    asmMode();

    return 0;
}