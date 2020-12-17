#include <iostream>
#include "CTwo.hpp"
#include "COne.hpp"
#include "CThree.hpp"
#include "CFour.hpp"

using std::cout;
using std::endl;

void printAll(CTwo **ctwo, size_t n) {
    for (int i = 0; i < n; i++) {
        ctwo[i]->print();
    }
}

int main() {

    COne cone(1.1, "f");
    CTwo ctwo(2.2, &cone);
    CThree cThree(3, ctwo);
    CFour cFour(4, cThree);

    cThree.setInt(10);

    CTwo *ctwos[3] = {&ctwo, &cThree, &cFour};
    printAll(ctwos, 3);
    return 0;
}