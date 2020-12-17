#include <iostream>

using std::cout;
using std::endl;

#include "CThree.hpp"
#include "CFour.hpp"

CFour::CFour() :
        i(0), CThree() {
}

CFour::CFour(const int i, const CThree &p) :
        i(i), CThree(p) {
}

CFour::CFour(const CFour &cFour) :
        i(cFour.i), CThree(cFour) {
}

CFour::~CFour() {

}

int CFour::getInt() const {
    return i;
}

void CFour::setInt(int i) {
    this->i = i;
}

void CFour::print() const {
    cout << "i:" << i << " CTwo: (";
    CThree::print();
    cout << ") ";
}
