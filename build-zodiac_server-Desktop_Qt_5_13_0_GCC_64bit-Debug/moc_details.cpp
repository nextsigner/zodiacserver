/****************************************************************************
** Meta object code from reading C++ file 'details.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../details/src/details.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'details.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Details_t {
    QByteArrayData data[8];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Details_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Details_t qt_meta_stringdata_Details = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Details"
QT_MOC_LITERAL(1, 8, 13), // "aspectClicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 35, 14), // "planetSelected"
QT_MOC_LITERAL(5, 50, 5), // "index"
QT_MOC_LITERAL(6, 56, 16), // "setCurrentPlanet"
QT_MOC_LITERAL(7, 73, 11) // "A::PlanetId"

    },
    "Details\0aspectClicked\0\0QModelIndex\0"
    "planetSelected\0index\0setCurrentPlanet\0"
    "A::PlanetId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Details[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    1,   32,    2, 0x08 /* Private */,
       6,    2,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    2,    2,

       0        // eod
};

void Details::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Details *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->aspectClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->planetSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setCurrentPlanet((*reinterpret_cast< A::PlanetId(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Details::staticMetaObject = { {
    &AstroFileHandler::staticMetaObject,
    qt_meta_stringdata_Details.data,
    qt_meta_data_Details,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Details::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Details::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Details.stringdata0))
        return static_cast<void*>(this);
    return AstroFileHandler::qt_metacast(_clname);
}

int Details::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AstroFileHandler::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
