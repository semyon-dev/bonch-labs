#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "MyString.hpp"

// получить длину с учетом нулевым символом
size_t CStrLength(const char *str) {
    size_t len = 0;
    while (true) {
        if (str[len] == '\0')
            return ++len;
        ++len;
    }
}

// очистка консоли
void clearStdin() {
    int c;
    while ((c = fgetc(stdin)) != EOF && c != '\n');
}

// оператор вывода
std::ostream &operator<<(std::ostream &out, const MyString &str) {
    out << str.c_str();
    return out;
}

// конструктор по умолчанию
MyString::MyString() {
    str = new char[5];
    capacity = 5;
    size = 0;
    str[0] = '\0';
}

// конструктор с параметром
MyString::MyString(const char *str) {
    size_t len = CStrLength(str);
    this->str = new char[len];
    strcat(this->str, str);
    size = len - 1;
    capacity = len;
}

// конструктор копии
MyString::MyString(MyString &str) {
    this->str = new char[str.size + 1];
    strcat(this->str, str.str);
    size = str.size;
    capacity = str.size + 1;
}

// конструктор перемещения
MyString::MyString(MyString &&str) noexcept {
    this->str = str.str;
    str.str = nullptr;
    this->size = str.size;
    this->capacity = str.capacity;
}

// деструктор
MyString::~MyString() {
    delete[] str;
}

// увеличивает место в массиве для строки
void MyString::reserve(size_t size) {
    if (capacity >= size)
        return;
    capacity = size;

    char *sub_str = new char[size];
    for (size_t i = 0; i < this->size + 1; i++) {
        sub_str[i] = str[i];
    }
    delete[] str;
    str = sub_str;
}

// возвращает си строку
const char *MyString::c_str() const {
    return str;
}

// доступ к строке
char MyString::operator[](size_t i) const {
    return str[i];
}

// получение длинны
size_t MyString::length() const {
    return size;
}

// копирование строк
void MyString::copy(const MyString &str) {
    size_t len = str.size + 1;

    if (capacity < len) {
        delete[] this->str;
        this->str = new char[len];
        capacity = len;
    }

    for (size_t i = 0; i < len; i++)
        this->str[i] = str[i];
    size = len - 1;
}

// копирование строк на основе си строки
void MyString::copy(const char *str) {
    size_t len = CStrLength(str);

    if (capacity < len) {
        delete[] this->str;
        this->str = new char[len];
        capacity = len;
    }

    for (size_t i = 0; i < len; i++) {
        this->str[i] = str[i];
    }
    size = len - 1;
}

// получние подстроки (index - откуда, count - кол-во)
MyString MyString::subStr(size_t index, size_t count) const {
    MyString string;
    string.reserve(count + 1);

    for (size_t i = 0; i < count; i++) {
        string.str[i] = str[index + i];
    }
    string.str[count] = '\0';
    string.capacity = count + 1;
    string.size = count;
    return string;
}

// вырезать подстроку
void MyString::remove(size_t index, size_t count) {
    for (size_t i = index; i + count < size + 1; i++) {
        str[i] = str[i + count];
    }
    size -= count;
}

// вставить подстроку
void MyString::insert(const char *str, size_t index) {
    size_t len = CStrLength(str) - 1;
    reserve(size + len + 1);

    //сдвиг текста ->
    for (size_t i = size; i >= index; i--) {
        this->str[i + len] = this->str[i];
    }

    //вставка
    for (size_t i = 0; i < len; i++) {
        this->str[i + index] = str[i];
    }
    size = size + len + 1;
}

//// удалить ведушие и завершающие пробелы
//void MyString::trim() {
//    // удаление ведущих
//    for (size_t i = 0; i < size; i++) {
//        if (str[i] != ' ') {
//            remove(0, i);
//            break;
//        }
//    }
//
//    // удаление завершающих
//    for (size_t i = size - 1; i != -1; i--) {
//        if (str[i] != ' ')
//            break;
//        size--;
//        str[i] = '\0';
//    }
//}

// считать с консоли
void MyString::read() {
    constexpr size_t buf_size = 10;
    char *text = reinterpret_cast<char *>(calloc(1, 1)), buffer[buf_size];
    size_t text_size;
    bool final = false;

    clearStdin();
    while (fgets(buffer, buf_size, stdin)) {
        text_size = strlen(text) + 1 + strlen(buffer);
        void *r_m = realloc(text, text_size);
        if (r_m == nullptr) {
            std::cerr << "Error realoc memory\n";
            exit(-1);
        }
        text = reinterpret_cast<char *>(r_m);
        if (!text)
            throw "Error: fgets";
        for (size_t i = 0; i < buf_size; i++)
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                final = true;
                break;
            }
        strcat(text, buffer);
        if (final)
            break;
    }
    copy(text);
}

// печать строки
void MyString::print() {
    printf("%s", str);
}