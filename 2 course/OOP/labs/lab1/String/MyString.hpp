#pragma once

class MyString {
public:
    MyString();

    MyString(const char *str);

    MyString(MyString &str);

    MyString(MyString &&str) noexcept;

    ~MyString();

    void reserve(size_t size);

    const char *c_str() const;

    char operator[](size_t i) const;

    const MyString &operator=(const MyString &str) = delete;

    //условие
    size_t length() const;

    void copy(const MyString &str);

    void copy(const char *str);

    MyString subStr(size_t index, size_t count) const;

    void remove(size_t index, size_t count);

    void insert(const char *str, size_t index);

    void read(); //считать с консоли
    void print();

private:
    char *str;
    size_t size;
    size_t capacity;
};

std::ostream &operator<<(std::ostream &out, const MyString &str);