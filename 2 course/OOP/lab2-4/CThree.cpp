#include <iostream>

using std::cout;
using std::endl;

#include "CTwo.hpp"
#include "CThree.hpp"

CThree::CThree() :
        i(0), CTwo() {
}

CThree::CThree(const int i, const CTwo &p) :
        i(i), CTwo(p) {
}

CThree::CThree(const CThree &cThree) :
        i(cThree.i), CTwo(cThree) {
}

CThree::~CThree() {

}

int CThree::getInt() const {
    return i;
}

void CThree::setInt(int i) {
    this->i = i;
}

void CThree::print() const {
    cout << "i:" << i << " CTwo: (";
    CTwo::print();
    cout << ") ";
}

