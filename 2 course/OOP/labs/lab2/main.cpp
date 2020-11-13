#include <iostream>
#include "CTwo.hpp"
#include "COne.hpp"

using std::cout;
using std::endl;

int main() {
    COne conce(10.0, "test str");

    CTwo ctwo1;
    CTwo ctwo2(2.0, &conce);
    CTwo ctwo3(ctwo2);

    cout << "ctwo1:" << endl;
    ctwo1.print();
    cout << endl;
    cout << "ctwo2:" << endl;
    ctwo2.print();
    cout << endl;
    cout << "ctwo3:" << endl;
    ctwo3.print();
    cout << endl;

    ctwo1 = ctwo2;
    cout << "ctwo2 new:" << endl;
    ctwo2.print();
    cout << endl;

    return 0;
}