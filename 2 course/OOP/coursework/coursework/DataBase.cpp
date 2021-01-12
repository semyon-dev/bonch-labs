#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QFile>

#include "DataBase.h"


void DataBase::loadFromFile(const QString& path)
{
    clear();

    QString val;
    QFile file;
    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonArray arr = sett2.value(QString("TV")).toArray();

    for (size_t i = 0; i < arr.size(); i++)
    {
        auto obj = arr[i].toObject();
        TV tv;

        tv.name =		 obj.value(u8"name").toString();
        tv.firm =	     obj.value(u8"firm").toString();
        tv.price =       obj.value(u8"price").toInt();
        tv.resolution =  obj.value(u8"resolution").toString();
        tv.diagonal =	 obj.value(u8"diagonal").toInt();
        tv.smart =       obj.value(u8"smart").toBool();


        pushBack(tv);
    }
}

void DataBase::saveToFile(const QString& path)
{
    QJsonDocument json;
    QJsonArray arr;

    for (size_t i = 0; i < getSize(); i++)
    {
        QJsonObject obj;

        obj.insert("name",         operator[](i).name);
        obj.insert("firm",		   operator[](i).firm);
        obj.insert("price",        operator[](i).price);
        obj.insert("resolution",   operator[](i).resolution);
        obj.insert("diagonal",	   operator[](i).diagonal);
        obj.insert("smart",        operator[](i).smart);


        arr.push_back(obj);
    }
    QJsonObject obj;
    obj.insert("TV", arr);
    json.setObject(obj);


    QFile file;
    file.setFileName(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);


    file.write(json.toJson(QJsonDocument::Compact));


    file.close();
}

void DataBase::margeFromFile(const QString& path)
{
    QString val;
    QFile file;
    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonArray arr = sett2.value(QString("TV")).toArray();

    for (size_t i = 0; i < arr.size(); i++)
    {
        auto obj = arr[i].toObject();
        TV tv;

        tv.name =         obj.value(u8"name").toString();
        tv.firm =         obj.value(u8"firm").toString();
        tv.price =        obj.value(u8"price").toInt();
        tv.resolution   = obj.value(u8"resolution").toString();
        tv.diagonal =     obj.value(u8"diagonal").toInt();
        tv.smart =        obj.value(u8"smart").toBool();

        pushBack(tv);
    }
}
