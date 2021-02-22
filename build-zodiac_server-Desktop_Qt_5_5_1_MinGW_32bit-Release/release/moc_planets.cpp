/****************************************************************************
** Meta object code from reading C++ file 'planets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../planets/src/planets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'planets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AstroQmlView_t {
    QByteArrayData data[6];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AstroQmlView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AstroQmlView_t qt_meta_stringdata_AstroQmlView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AstroQmlView"
QT_MOC_LITERAL(1, 13, 13), // "objectClicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "name"
QT_MOC_LITERAL(4, 33, 11), // "requestHelp"
QT_MOC_LITERAL(5, 45, 3) // "tag"

    },
    "AstroQmlView\0objectClicked\0\0name\0"
    "requestHelp\0tag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AstroQmlView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void AstroQmlView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AstroQmlView *_t = static_cast<AstroQmlView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->objectClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->requestHelp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AstroQmlView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroQmlView::objectClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (AstroQmlView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroQmlView::requestHelp)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject AstroQmlView::staticMetaObject = {
    { &QDeclarativeView::staticMetaObject, qt_meta_stringdata_AstroQmlView.data,
      qt_meta_data_AstroQmlView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AstroQmlView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AstroQmlView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AstroQmlView.stringdata0))
        return static_cast<void*>(const_cast< AstroQmlView*>(this));
    return QDeclarativeView::qt_metacast(_clname);
}

int AstroQmlView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void AstroQmlView::objectClicked(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AstroQmlView::requestHelp(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_Planets_t {
    QByteArrayData data[8];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Planets_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Planets_t qt_meta_stringdata_Planets = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Planets"
QT_MOC_LITERAL(1, 8, 14), // "planetSelected"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "A::PlanetId"
QT_MOC_LITERAL(4, 36, 9), // "fileIndex"
QT_MOC_LITERAL(5, 46, 12), // "orderChanged"
QT_MOC_LITERAL(6, 59, 13), // "objectClicked"
QT_MOC_LITERAL(7, 73, 4) // "name"

    },
    "Planets\0planetSelected\0\0A::PlanetId\0"
    "fileIndex\0orderChanged\0objectClicked\0"
    "name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Planets[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   34,    2, 0x08 /* Private */,
       6,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void Planets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Planets *_t = static_cast<Planets *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->planetSelected((*reinterpret_cast< A::PlanetId(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->orderChanged(); break;
        case 2: _t->objectClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Planets::*_t)(A::PlanetId , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Planets::planetSelected)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Planets::staticMetaObject = {
    { &AstroFileHandler::staticMetaObject, qt_meta_stringdata_Planets.data,
      qt_meta_data_Planets,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Planets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Planets::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Planets.stringdata0))
        return static_cast<void*>(const_cast< Planets*>(this));
    return AstroFileHandler::qt_metacast(_clname);
}

int Planets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Planets::planetSelected(A::PlanetId _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
