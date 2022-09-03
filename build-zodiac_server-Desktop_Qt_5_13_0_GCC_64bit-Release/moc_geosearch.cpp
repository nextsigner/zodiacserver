/****************************************************************************
** Meta object code from reading C++ file 'geosearch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../fileeditor/src/geosearch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'geosearch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeoSuggestCompletion_t {
    QByteArrayData data[8];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeoSuggestCompletion_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeoSuggestCompletion_t qt_meta_stringdata_GeoSuggestCompletion = {
    {
QT_MOC_LITERAL(0, 0, 20), // "GeoSuggestCompletion"
QT_MOC_LITERAL(1, 21, 14), // "doneCompletion"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 14), // "preventSuggest"
QT_MOC_LITERAL(4, 52, 11), // "autoSuggest"
QT_MOC_LITERAL(5, 64, 17), // "handleNetworkData"
QT_MOC_LITERAL(6, 82, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 97, 12) // "networkReply"

    },
    "GeoSuggestCompletion\0doneCompletion\0"
    "\0preventSuggest\0autoSuggest\0"
    "handleNetworkData\0QNetworkReply*\0"
    "networkReply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeoSuggestCompletion[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void GeoSuggestCompletion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeoSuggestCompletion *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doneCompletion(); break;
        case 1: _t->preventSuggest(); break;
        case 2: _t->autoSuggest(); break;
        case 3: _t->handleNetworkData((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GeoSuggestCompletion::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_GeoSuggestCompletion.data,
    qt_meta_data_GeoSuggestCompletion,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GeoSuggestCompletion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeoSuggestCompletion::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeoSuggestCompletion.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GeoSuggestCompletion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_GeoSearchBox_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeoSearchBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeoSearchBox_t qt_meta_stringdata_GeoSearchBox = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GeoSearchBox"
QT_MOC_LITERAL(1, 13, 8), // "doSearch"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "GeoSearchBox\0doSearch\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeoSearchBox[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void GeoSearchBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeoSearchBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doSearch(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GeoSearchBox::staticMetaObject = { {
    &QLineEdit::staticMetaObject,
    qt_meta_stringdata_GeoSearchBox.data,
    qt_meta_data_GeoSearchBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GeoSearchBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeoSearchBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeoSearchBox.stringdata0))
        return static_cast<void*>(this);
    return QLineEdit::qt_metacast(_clname);
}

int GeoSearchBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_GeoSearchWidget_t {
    QByteArrayData data[7];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeoSearchWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeoSearchWidget_t qt_meta_stringdata_GeoSearchWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GeoSearchWidget"
QT_MOC_LITERAL(1, 16, 15), // "locationChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "turnGoogleSearch"
QT_MOC_LITERAL(4, 50, 16), // "turnYandexSearch"
QT_MOC_LITERAL(5, 67, 12), // "turnGeoInput"
QT_MOC_LITERAL(6, 80, 16) // "proofCoordinates"

    },
    "GeoSearchWidget\0locationChanged\0\0"
    "turnGoogleSearch\0turnYandexSearch\0"
    "turnGeoInput\0proofCoordinates"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeoSearchWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GeoSearchWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeoSearchWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->locationChanged(); break;
        case 1: _t->turnGoogleSearch(); break;
        case 2: _t->turnYandexSearch(); break;
        case 3: _t->turnGeoInput(); break;
        case 4: _t->proofCoordinates(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GeoSearchWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeoSearchWidget::locationChanged)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GeoSearchWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_GeoSearchWidget.data,
    qt_meta_data_GeoSearchWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GeoSearchWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeoSearchWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeoSearchWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GeoSearchWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void GeoSearchWidget::locationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
