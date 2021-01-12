#include "list.hpp"

using namespace std;

int main() {

    List<int> list;
    list.pushBack(1);
    List<int> list2(list);

    list.pushBack(12);
    list.pushBack(14);

    list2.pushBack(12);
    list2.pushBack(14);

    cout << "list 1 print: " << endl;
    list.print();
    cout << endl;
    cout << "list 2 print: " << endl;
    list2.print();
    cout << endl;

    if (list == list2) {
        cout << endl << "списки равны" << endl;
    }

    list.removeBack();
    cout << "list after removeBack(): " << endl;
    list.print();
    cout << endl;

    if (list != list2) {
        cout << endl << "теперь списки не равны" << endl;
    }

    return 0;
}