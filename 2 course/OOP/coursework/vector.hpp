#pragma once
#include <utility>
#include <iostream>

namespace Novikov
{
        template <typename T>
        class Vector
        {
        public:
                class Iterator
                {
                public:
                        Iterator();
                        Iterator(Vector& r);
                        Iterator(const Iterator& r) = default;

                        Iterator& operator=(const Iterator& r) = default;
                        Iterator& operator++();  //prefix
                        Iterator operator++(int);//postfix
                        Iterator operator+(size_t i)const;
                        Iterator operator-(size_t i)const;
                        bool operator==(const Iterator& r);
                        bool operator!=(const Iterator& r);
                        T& operator*()const;

                private:
                        Vector* v;
                        size_t i;
                };

                class ConstIterator
                {
                public:
                        ConstIterator();
                        ConstIterator(const Vector& r);
                        ConstIterator(const ConstIterator& r) = default;

                        ConstIterator& operator=(const ConstIterator& r) = default;
                        ConstIterator& operator++();  //prefix
                        ConstIterator operator++(int);//postfix
                        ConstIterator operator+(size_t i)const;
                        ConstIterator operator-(size_t i)const;
                        bool operator==(const ConstIterator& r);
                        bool operator!=(const ConstIterator& r);
                        const T& operator*()const;

                        friend Vector;
                private:
                        const Vector* v;
                        size_t i;
                };

                Vector();
                Vector(const Vector& r);
                Vector(Vector&& r) noexcept;
                ~Vector();

                void pushBack(const T& el);
                template <typename ...Args>
                void emplaceBack(Args&&... args); // создаем объект сразу в векторе
                void reserve(size_t new_capasity);
                void erase(size_t begin, size_t end); // удаляем от и до
                void clear();
                size_t getSize() const;

                Vector& operator=(const Vector& r);

                Iterator begin();
                Iterator end();

                ConstIterator begin()const;
                ConstIterator end()const;

                ConstIterator cbegin()const;
                ConstIterator cend()const;

                T& operator[](size_t i);
                const T& operator[](size_t i) const;

        private:
                T* data;
                size_t size;
                size_t capasity;
        };
}

#include "vector.inl"
