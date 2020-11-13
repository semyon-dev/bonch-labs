#pragma once

#include <iostream>

template<typename RealNum, typename ImaginaryNum>
class ComplexNum {
public:
    ComplexNum();

    ComplexNum(RealNum real, ImaginaryNum imaginary);

    ComplexNum(const ComplexNum<RealNum, ImaginaryNum> &r);

    ComplexNum(const ComplexNum<RealNum, ImaginaryNum> &&r) noexcept;

    ~ComplexNum();

    RealNum getReal() const;

    ImaginaryNum getImaginary() const;

    // сложение комплексных чисел
    ComplexNum operator+(const ComplexNum &r) const;

    // вычитание комплексных чисел
    ComplexNum operator-(const ComplexNum &r) const;

    // умножение комплексных чисел
    ComplexNum operator*(const ComplexNum &r) const;

    // деление комплексных чисел
    ComplexNum operator/(const ComplexNum &r) const;

    // оператор присваивания
    ComplexNum &operator=(const ComplexNum &r);

    // операторы сравнения
    bool operator==(const ComplexNum<RealNum, ImaginaryNum> &r) const;

    bool operator!=(const ComplexNum<RealNum, ImaginaryNum> &r) const;

    RealNum real;
    ImaginaryNum imaginary;
};

template<typename RealNum, typename ImaginaryNum>
std::ostream &operator<<(std::ostream &out, const ComplexNum<RealNum, ImaginaryNum> &r);

typedef ComplexNum<float, float> ComplexNumF;
typedef ComplexNum<double, double> ComplexNumD;

#include "ComplexNumber.inl"