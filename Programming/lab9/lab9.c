// Удалить из каждой строки ее предпоследнее слово.

#include <stdio.h>
#include <string.h>

#define row 20
#define max 129

char text[row][max];

void input() {
    int rowLocal;
    printf("Введите кол-во вводимых строк: ");
    scanf("%i", &rowLocal);
    fgets(text[0], max, stdin);
    for (int i = 0; i < rowLocal; i++) {
        fgets(text[i], max, stdin);
    }
}

int main() {
    setbuf(stdout, NULL);
    input();
    char strRes[max];
    for (int i = 0; i < row; i++) {
        strcpy(strRes, text[i]);
        strcpy(strrchr(strRes, ' '), "\0");
        strcpy(strrchr(strRes, ' '), "\0");
        strcat(strRes, strrchr(text[i], ' '));
        printf("%s\r", strRes);
    }
}