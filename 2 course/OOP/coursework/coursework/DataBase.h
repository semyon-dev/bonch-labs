#pragma once
#include "vector.hpp"
#include <qstring.h>

struct TV
{
    QString name;       // название
    QString firm;       // фирма-производитель
    int price;          // цена
    QString resolution; // разрешения
    int diagonal;       // диагональ
    bool smart;         // умный телевизор
};

class DataBase: public Novikov::Vector<TV>
{
public:

    void loadFromFile(const QString& path);
    void saveToFile(const QString& path);
    void margeFromFile(const QString& path);

private:
};
