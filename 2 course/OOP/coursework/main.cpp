#include "coursework.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    coursework w;
    w.show();
    return a.exec();
}
