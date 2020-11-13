#include "ComplexNumber.hpp"

// конструктор
template<typename RealNum, typename ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>::ComplexNum():
        real(), imaginary() {
}

// конструктор с параметрами
template<typename RealNum, typename ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>::ComplexNum(RealNum real, ImaginaryNum imaginary) :
        real(real), imaginary(imaginary) {
}

// конструктор копирования
template<typename RealNum, typename ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>::ComplexNum(const ComplexNum<RealNum, ImaginaryNum> &r) :
        real(r.real), imaginary(r.imaginary) {
}

// конструктор перемещения
template<typename RealNum, typename ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>::ComplexNum(const ComplexNum<RealNum, ImaginaryNum> &&r) noexcept :
        real(r.real), imaginary(r.imaginary) {
}

// деструктор
template<typename RealNum, typename ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>::~ComplexNum() = default;

// получить вещественную часть комплексного числа
template<typename RealNum, typename ImaginaryNum>
RealNum ComplexNum<RealNum, ImaginaryNum>::getReal() const {
    return real;
}

// получить мнимую часть комплексного числа
template<typename RealNum, typename ImaginaryNum>
ImaginaryNum ComplexNum<RealNum, ImaginaryNum>::getImaginary() const {
    return imaginary;
}

// оператор сложения
template<typename RealNum, typename ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>::operator+(const ComplexNum<RealNum, ImaginaryNum> &r) const {
    auto c = *this;
    c.real += r.real;
    c.imaginary += r.imaginary;
    return c;
}

// оператор вычитания
template<typename RealNum, typename ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>::operator-(const ComplexNum<RealNum, ImaginaryNum> &r) const {
    auto c = *this;
    c.real -= r.real;
    c.imaginary -= r.imaginary;
    return c;
}

// оператор умножения
template<typename RealNum, typename ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>::operator*(const ComplexNum<RealNum, ImaginaryNum> &r) const {
    auto c = *this;
    const RealNum temp = real * r.real - static_cast<RealNum>(imaginary * r.imaginary);
    c.imaginary = static_cast<ImaginaryNum>(real) * r.imaginary + imaginary * static_cast<ImaginaryNum>(r.real);
    c.real = temp;
    return c;
}

// оператор деления
template<typename RealNum, typename ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum>::operator/(const ComplexNum<RealNum, ImaginaryNum> &r) const {
    RealNum real_t = real * r.real + static_cast<RealNum>(imaginary * r.imaginary);
    ImaginaryNum imag_t = imaginary * static_cast<ImaginaryNum>(r.real) - static_cast<ImaginaryNum>(real) * r.imaginary;
    real_t /= r.real * r.real + static_cast<RealNum>(r.imaginary * r.imaginary);
    imag_t /= static_cast<ImaginaryNum>(r.real * r.real) + r.imaginary * r.imaginary;

    auto c = *this;
    c.real = real_t;
    c.imaginary = imag_t;
    return c;
}

// оператор присваивания
template<typename RealNum, typename ImaginaryNum>
ComplexNum<RealNum, ImaginaryNum> &
ComplexNum<RealNum, ImaginaryNum>::operator=(const ComplexNum<RealNum, ImaginaryNum> &r) {
    real = r.real;
    imaginary = r.imaginary;
    return *this;
}

// операторы сравнения
template<typename RealNum, typename ImaginaryNum>
bool ComplexNum<RealNum, ImaginaryNum>::operator==(const ComplexNum<RealNum, ImaginaryNum> &r) const {
    return (real == r.real) && (imaginary == r.imaginary);
}

template<typename RealNum, typename ImaginaryNum>
bool ComplexNum<RealNum, ImaginaryNum>::operator!=(const ComplexNum<RealNum, ImaginaryNum> &r) const {
    return (real != r.real) || (imaginary != r.imaginary);
}

template<typename RealNum, typename ImaginaryNum>
std::ostream &operator<<(std::ostream &out, const ComplexNum<RealNum, ImaginaryNum> &r) {
    out << "(" << r.real << ", " << r.imaginary << ")";
    return out;
}