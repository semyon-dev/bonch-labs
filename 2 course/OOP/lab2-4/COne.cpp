#include <iostream>

using std::cout;
using std::endl;

#include <cstring>
#include "COne.hpp"
#include  <memory>

COne::COne() :
        f(0.0), ps(new char[1]) {
    ps[0] = 0;
}

COne::COne(float f, const char *str) :
        f(f) {
    const auto len = strlen(str) + 1;
    ps = new char[len];
    memcpy(ps, str, len);
}

COne::COne(const COne &cone) :
        f(cone.f) {
    const auto len = strlen(cone.ps) + 1;
    ps = new char[len];
    memcpy(ps, cone.ps, len);
}

COne::~COne() {
    delete[] ps;
}

COne &COne::operator=(const COne &r) {
    if (this == &r) {
        return *this;
    }
    delete[] ps;
    const auto len = strlen(r.ps) + 1;
    ps = new char[len];
    memcpy(ps, r.ps, len);
    f = r.f;
    return *this;
}

float COne::getF() const {
    return f;
}

char *COne::getChar() const {
    return ps;
}

void COne::print() const {
    cout << "f:" << f << " ps:" << ps;
}