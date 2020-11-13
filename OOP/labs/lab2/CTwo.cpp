#include <iostream>

using std::cout;
using std::endl;

#include "CTwo.hpp"
#include "COne.hpp"

CTwo::CTwo() :
        d(0.0), p(new COne) {
}

CTwo::CTwo(const double &d, const COne *p) :
        d(d), p(new COne(*p)) {
}

CTwo::CTwo(const CTwo &ctwo) :
        d(ctwo.d), p(new COne(*(ctwo.p))) {
}

CTwo::~CTwo() {
    delete p;
}

CTwo &CTwo::operator=(const CTwo &ctwo) {
    if (this == &ctwo) {
        return *this;
    }
    d = ctwo.d;
    *p = *(ctwo.p);
    return *this;
}

const double &CTwo::getDouble() const {
    return d;
}

const COne *CTwo::getCOne() const {
    return p;
}

void CTwo::print() const {
    cout << "d:" << d << " p:(";
    p->print();
    cout << ")";
}