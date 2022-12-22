#include "vector.hpp"
//#include "vector.hpp"
#pragma once

namespace Novikov
{
    //---Iterator---//
    template<typename T>
    inline Vector<T>::Iterator::Iterator(): v(nullptr), i(0) {}
    template<typename T>
    inline Vector<T>::Iterator::Iterator(Vector& r) : v(&r), i(0) {}

    template<typename T>
    inline typename Vector<T>::Iterator& Vector<T>::Iterator::operator++()  //prefix
    {
        ++i;
        return *this;
    }
    template<typename T>
    typename Vector<T>::Iterator inline Vector<T>::Iterator::operator++(int)//postfix
    {
        auto t = *this;
        ++i;
        return t;
    }
    template<typename T>
    typename Vector<T>::Iterator Vector<T>::Iterator::operator+(size_t i)const
    {
        auto t = *this;
        t.i += i;
    }
    template<typename T>
    typename Vector<T>::Iterator Vector<T>::Iterator::operator-(size_t i)const
    {
        auto t = *this;
        t.i -= i;
    }
    template<typename T>
    bool Vector<T>::Iterator::operator==(const Iterator& r)
    {
        return v == r.v && i == r.i;
    }
    template<typename T>
    bool Vector<T>::Iterator::operator!=(const Iterator& r)
    {
        return v != r.v || i != r.i;
    }
    template<typename T>
    inline T& Vector<T>::Iterator::operator*() const
    {
        return v->operator[](i);
    }
    //---iterator---//


    //---ConstIterator---//
    template<typename T>
    inline Vector<T>::ConstIterator::ConstIterator() :v(nullptr), i(0) {}
    template<typename T>
    Vector<T>::ConstIterator::ConstIterator(const Vector& r) : v(&r), i(0) {}
    template<typename T>
    inline typename Vector<T>::ConstIterator& Vector<T>::ConstIterator::operator++()  //prefix
    {
        ++i;
        return *this;
    }
    template<typename T>
    typename Vector<T>::ConstIterator inline Vector<T>::ConstIterator::operator++(int)//postfix
    {
        auto t = *this;
        ++i;
        return t;
    }
    template<typename T>
    inline typename Vector<T>::ConstIterator Vector<T>::ConstIterator::operator+(size_t i)const
    {
        auto t = *this;
        t.i += i;
    }
    template<typename T>
    inline typename Vector<T>::ConstIterator Vector<T>::ConstIterator::operator-(size_t i)const
    {
        auto t = *this;
        t.i -= i;
    }
    template<typename T>
    bool Vector<T>::ConstIterator::operator==(const ConstIterator& r)
    {
        return v == r.v && i == r.i;
    }
    template<typename T>
    bool Vector<T>::ConstIterator::operator!=(const ConstIterator& r)
    {
        return v != r.v || i != r.i;
    }
    template<typename T>
    inline const T& Vector<T>::ConstIterator::operator*() const
    {
        return v->operator[](i);
    }
    //---iterator---//


    //---vector---//
    template<typename T>
    inline Vector<T>::Vector():
        data(static_cast<T*>(operator new[](10 * sizeof(T)))), size(0), capasity(10)
    {}
    template<typename T>
    inline Vector<T>::Vector(const Vector& r):
        data(static_cast<T*>(operator new[](r.size * sizeof(T)))), size(r.size), capasity(r.size)
    {
        for (size_t i = 0; i < size; i++)
            new (data + i) T(r.data[i]);
    }
    template<typename T>
    inline Vector<T>::Vector(Vector&& r) noexcept:
        data(r.data), size(r.size), capasity(r.capasity)
    {
        r.data = nullptr;
    }
    template<typename T>
    inline Vector<T>::~Vector()
    {
        if (data == nullptr)
            return;

        for (size_t i = 0; i < size; i++)
            data[i].~T();

        operator delete[](data);
    }

    template<typename T>
    void inline Vector<T>::pushBack(const T& el)
    {
        if (size == capasity)
            reserve(size * 2);

        new (data + size) T(el);

        size++;
    }
    template<typename T>
    template<typename ...Args>
    void inline Vector<T>::emplaceBack(Args&&... args)
    {
        if (size == capasity)
            reserve(size * 2);

        new (data + size) T(std::move(args ...));

        size++;
    }
    template<typename T>
    void inline Vector<T>::reserve(size_t new_capasity)
    {
        if (this->capasity >= new_capasity)
            return;

        T* temp_data = static_cast<T*>(operator new[](new_capasity * sizeof(T)));

        for (size_t i = 0; i < size; i++)
            new (temp_data + i) T(std::move(data[i]));

        for (size_t i = 0; i < size; i++)
            data[i].~T();

        operator delete[](data);

        data = temp_data;
        capasity = new_capasity;
    }
    template<typename T>
    void inline Vector<T>::erase(size_t begin, size_t end)
    {
        for (size_t i = begin; i != end; i++)
        {
            data[i].~T();

        }

        size -= end - begin;
        for (size_t i = begin; i < size; i++)
        {
            new (data + i) T(std::move(data[i + end - begin]));
            data[i + end - begin].~T();
        }
    }
    template<typename T>
    void inline Vector<T>::clear()
    {
        for (size_t i = 0; i < size; i++)
            data[i].~T();
        size = 0;
    }
    template<typename T>
    inline size_t Vector<T>::getSize() const
    {
        return size;
    }

    template<typename T>
    Vector<T>& Vector<T>::operator=(const Vector& r)
    {
        for (size_t i = 0; i < size; i++)
            data[i].~T();

        if (capasity < r.size)
        {
            operator delete[](data);
            data = static_cast<T*>(operator new[](r.size * sizeof(T)));
            capasity = r.size;
        }

        size = r.size;
        for (size_t i = 0; i < size; i++)
            new (data + i) T(r.data[i]);

        return *this;
    }

    template<typename T>
    typename Vector<T>::Iterator inline Vector<T>::begin(){ return Iterator(*this); }
    template<typename T>
    typename Vector<T>::Iterator inline Vector<T>::end(){Iterator i; i.i = size; i.v = this; return i;};

    template<typename T>
    typename Vector<T>::ConstIterator inline Vector<T>::begin()const { return ConstIterator(*this); };
    template<typename T>
    typename Vector<T>::ConstIterator inline Vector<T>::end()const { ConstIterator i; i.i = size; i.v = this; return i; };

    template<typename T>
    typename Vector<T>::ConstIterator inline Vector<T>::cbegin()const { return ConstIterator(*this); };
    template<typename T>
    typename Vector<T>::ConstIterator inline Vector<T>::cend()const { ConstIterator i; i.i = size; i.v = this; return i; };

    template<typename T>
    T& Vector<T>::operator[](size_t i)
    {
        return data[i];
    }
    template<typename T>
    const T& Vector<T>::operator[](size_t i) const
    {
        return data[i];
    }
    //---vector---//
}
