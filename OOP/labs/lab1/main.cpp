#include <iostream>
#include <complex> // для проверки
#include "String/MyString.hpp"
#include "ComplexNumber/ComplexNumber.hpp"

using namespace std;

namespace TString {
    // length copy print
    void Test1() {
        cout << "=========== Test1 (length copy print) =============" << endl;
        MyString str;
        str.copy("Hello");
        str.print();
        cout << endl;
        cout << "Length: " << str.length() << endl;

        MyString str2;
        str2.copy(str);
        cout << str2 << endl;

        cout << "========================" << endl;
    }

    // substr remove insert
    void Test2() {
        cout << "=========== Test2 (substr remove insert)" << endl;

        MyString str;
        str.copy("0123456789abcdef");
        cout << str.subStr(5, 5) << endl;
        str.remove(5, 5);
        cout << str << endl;
        str.insert("56789", 5);
        cout << str << endl;

        cout << "========================" << endl;
    }

    // trim
    void Test3() {
        cout << "=========== Test3 (trim)" << endl;

        MyString str;
        str.copy("    123    ");
        str.trim();
        cout << "->" << str << "<-" << endl;

        cout << "========================" << endl;
    }

    //read
    void TestRead() {
        cout << "=========== TestRead =============" << endl;
        MyString str;
        str.read();
        str.print();
        cout << endl;
        cout << "========================" << endl;
    }
}
namespace TComplex {
    void TestPrint() {
        cout << "=========== TestPrint ============" << endl;
        ComplexNumD c(1.3, 2.5);
        cout << c << endl;
        cout << "============================" << endl;
    }

    void TestArithmetic() {
        cout << "=========== TestArithmetic ============" << endl;

        ComplexNumD a1(9.8, 7.6), b1(5.4, 3.2), c1;
        complex<double> a2(9.8, 7.6), b2(5.4, 3.2), c2;

        c1 = a1 + b1;
        c2 = a2 + b2;
        cout << "a + b = c" << endl;
        cout << "my " << c1 << endl;
        cout << "standart " << c2 << endl;

        cout << endl;

        c1 = a1 - b1;
        c2 = a2 - b2;
        cout << "a - b = c" << endl;
        cout << "my " << c1 << endl;
        cout << "standart " << c2 << endl;

        cout << endl;

        c1 = a1 * b1;
        c2 = a2 * b2;
        cout << "a * b = c" << endl;
        cout << "my " << c1 << endl;
        cout << "standart " << c2 << endl;

        cout << endl;

        c1 = a1 / b1;
        c2 = a2 / b2;
        cout << "a / b = c" << endl;
        cout << "my " << c1 << endl;
        cout << "standart " << c2 << endl;


        cout << "============================" << endl;
    }
}

void TestString() {
    using namespace TString;
    Test1();
    cout << endl;
    Test2();
    cout << endl;
    Test3();
    cout << endl;
    TestRead();
}

void TestComplex() {
    using namespace TComplex;
    TestPrint();
    TestArithmetic();
}

int main() {
    setbuf(stdout, nullptr);
    cout << "1 - MyString (строка)" << endl;
    cout << "2 - ComplexNum (комплексное число)" << endl;
    cout << "Введите режим: ";
    int mode;
    cin >> mode;
    if (mode == 1)
        TestString();
    if (mode == 2)
        TestComplex();
    return 0;
}