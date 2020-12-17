#include "list.hpp"

using namespace std;

int main() {

    List<int> list;

    //list.pushFront(100);
    // list.pushFront(200);

    try {
        List<int> list2(list);
        list2.print();
    } catch (char const *exception) {
        cout << exception << endl;
    }


//    list.pushBack(12);
//    list.pushBack(14);
//
//    list2.pushBack(12);
//    list2.pushBack(14);
//
//    // list.print();
//    cout << endl;
//    //list2.print();
//
//    if (list == list2) {
//        cout << endl << "списки равны" << endl;
//    }
//
//    list.removeBack();
//    list.print();
//
//    if (list != list2) {
//        cout << endl << "списки не равны" << endl;
//    }

    return 0;
}