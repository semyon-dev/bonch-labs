/* Массив структур, содержащих сведения о фильмах.
* Каждая структура должна содержать следующие поля:
* режиссер, название, страна, жанр, год создания.
* Вывести на экран сведения о фильмах определенного жанра, созданных в некоторой стране.
*
* Новикв Семен, ИКПИ-95, вариант 17 */

#include <stdio.h>
#include <string.h> // для strcmp (сравнения)

#define count 3 // кол-во фильмов для ввода

char filter_genre[50];          // фильтр по жанру
char filter_country[50];        // фильтр по стране
unsigned short countFilter = 0; // кол-во структур подходящих под фильтр

struct film {
    char director[50];
    char country[50];
    char name[50];
    char genre[50];
    int year;
};

struct film films[count]; // массив фильмов

// функция ввода фильтров
void inputFilters() {
    printf("Введите genre для фильтра \n");
    scanf("%s", filter_genre);

    printf("Введите country для фильтра \n");
    scanf("%s", filter_country);
}

// функция ввода фильмов
void input() {
    for (int i = 0; i < count; i++) {

        printf("Ввод структуры номер: %i \n", i);

        printf("Введите name \n");
        scanf("%s", films[i].name);

        printf("Введите country \n");
        scanf("%s", films[i].country);

        printf("Введите director \n");
        scanf("%s", films[i].director);

        printf("Введите genre \n");
        scanf("%s", films[i].genre);

        printf("Введите year \n");
        scanf("%i", &films[i].year);
    }
}

// функция вывода структуры фильма
void printFilm(struct film *film) {
    printf("---------------------- \n");
    printf("Вывод подходящего фильма по критериям поиска: \n");
    printf("name: %s \n", film->name);
    printf("country: %s \n", film->country);
    printf("genre: %s \n", film->genre);
    printf("year: %i \n", film->year);
    printf("director: %s \n", film->director);
    printf("---------------------- \n");
}

// функция сравнения полей каждого фильма с раннее заданными фильтрами
void compare() {
    for (int i = 0; i < count; i++) {
        // strcmp - сравниваем фильтры и поля структур, если 0 - значит равны
        if (strcmp(films[i].genre, filter_genre) == 0 && strcmp(films[i].country, filter_country) == 0) {
            printFilm(&films[i]); // печатаем подходящую структуру
            countFilter++; // счетчик подходящих структур
        }
    }
}

// выводим кол-во подходящих структур если они есть
void printCountResult() {
    if (countFilter == 0) {
        printf("Подходящих структур не найдено! \n");
    } else {
        printf("Всего подходящих структур: %d \n", countFilter);
    }
}

int main() {
    setbuf(stdout, NULL);   // отключаем буфер
    inputFilters();             // вызов ввода фильтров
    input();                    // вызов ввода фильмов
    compare();                  // сравниваем поля каждого фильма с раннее заданными фильтрами
    printCountResult();         // выводим кол-во подходящих структур если они есть
}