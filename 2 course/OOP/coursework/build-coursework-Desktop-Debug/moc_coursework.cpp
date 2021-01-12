/****************************************************************************
** Meta object code from reading C++ file 'coursework.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../coursework/coursework.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coursework.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_coursework_t {
    QByteArrayData data[10];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_coursework_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_coursework_t qt_meta_stringdata_coursework = {
    {
QT_MOC_LITERAL(0, 0, 10), // "coursework"
QT_MOC_LITERAL(1, 11, 12), // "slot_sellect"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 37, 20), // "slot_load_bd_in_file"
QT_MOC_LITERAL(5, 58, 21), // "slot_write_bd_in_file"
QT_MOC_LITERAL(6, 80, 16), // "slot_add_bd_line"
QT_MOC_LITERAL(7, 97, 19), // "slot_delete_bd_line"
QT_MOC_LITERAL(8, 117, 13), // "slot_merge_bd"
QT_MOC_LITERAL(9, 131, 12) // "slot_bd_find"

    },
    "coursework\0slot_sellect\0\0QModelIndex\0"
    "slot_load_bd_in_file\0slot_write_bd_in_file\0"
    "slot_add_bd_line\0slot_delete_bd_line\0"
    "slot_merge_bd\0slot_bd_find"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_coursework[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08 /* Private */,
       4,    0,   54,    2, 0x08 /* Private */,
       5,    0,   55,    2, 0x08 /* Private */,
       6,    0,   56,    2, 0x08 /* Private */,
       7,    0,   57,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void coursework::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<coursework *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_sellect((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 1: _t->slot_load_bd_in_file(); break;
        case 2: _t->slot_write_bd_in_file(); break;
        case 3: _t->slot_add_bd_line(); break;
        case 4: _t->slot_delete_bd_line(); break;
        case 5: _t->slot_merge_bd(); break;
        case 6: _t->slot_bd_find(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject coursework::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_coursework.data,
    qt_meta_data_coursework,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *coursework::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *coursework::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_coursework.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int coursework::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
