#pragma once

#include <iostream>

using namespace std;

template<typename T>
class List {

public:
    List();

    List(const T *arr, size_t count);

    List(const List &l);

    ~List();

    void pushFront(const T &elem);

    void pushBack(const T &elem);

    void removeFront();

    void removeBack();

    void print();

    bool operator==(const List &list);

    bool operator!=(const List &list);

    struct Elem {
        Elem *next;
        Elem *prev;
        T data;
    };
private:
    Elem *first;
    Elem *last;
};

template<typename T>
List<T>::List(): first(nullptr), last(nullptr) {
    this->first = nullptr;
    this->last = nullptr;
}

template<typename T>
List<T>::List(const T *arr, size_t count): first(nullptr), last(nullptr) {
    for (int i = 0; i < count; ++i) {
        pushBack(arr[i]);
    }
}

template<typename T>
List<T>::List(const List &l) {
    if (l.first == nullptr) {
        return;
    }
    auto current = l.first;
    while (current != nullptr) {
        pushBack(current->data);
        current = current->next;
    }
}

template<typename T>
List<T>::~List() {
    auto current = this->first;
    while (current != nullptr) {
        delete current->prev;
        current = current->next;
    }
}

template<typename T>
void List<T>::pushFront(const T &elem) {
    if (this->first == nullptr) {
        first = last = new Elem;
    } else {
        auto oldFirst = this->first;
        first = new Elem;
        first->next = oldFirst;
        first->prev = nullptr;
        oldFirst->prev = first;
    }
    first->data = elem;
}

template<typename T>
void List<T>::pushBack(const T &elem) {
    if (this->last == nullptr) {
        last = first = new Elem;
    } else {
        auto oldLast = this->last;
        last = new Elem;
        last->next = nullptr;
        last->prev = oldLast;
        oldLast->next = last;
    }
    last->data = elem;
}

template<typename T>
void List<T>::print() {
    if (this->first == nullptr) {
        return;
//        throw "пустой список";
    }
    cout << this->first->data;
    cout << " ";
    auto current = this->first->next;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

template<typename T>
void List<T>::removeFront() {
    if (this->first != nullptr) {
        this->first = first->next;
        delete this->first->prev;
        this->first->prev = nullptr;
    }
}

template<typename T>
void List<T>::removeBack() {
    if (this->first != this->last) {
        this->last = last->prev;
        delete this->last->next;
        this->last->next = nullptr;
    } else {
        delete this->first;
        this->first == nullptr;
        this->last == nullptr;
    }
}

template<typename T>
bool List<T>::operator==(const List &list) {

    Elem *t1, *t2;

    t1 = this->first;
    t2 = list.first;

    while (t1 != nullptr && t2 != nullptr) {
        if (t1->data != t2->data)
            return false;
        t1 = t1->next;
        t2 = t2->next;
    }

    if (t2 != nullptr || t1 != nullptr) {
        return false;
    }

    return true;
}

template<typename T>
bool List<T>::operator!=(const List &list) {
    return !(*this == list);
}

