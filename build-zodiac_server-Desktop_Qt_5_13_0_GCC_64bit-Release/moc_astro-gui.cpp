/****************************************************************************
** Meta object code from reading C++ file 'astro-gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../astroprocessor/src/astro-gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'astro-gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AstroFile_t {
    QByteArrayData data[6];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AstroFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AstroFile_t qt_meta_stringdata_AstroFile = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AstroFile"
QT_MOC_LITERAL(1, 10, 7), // "changed"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 18), // "AstroFile::Members"
QT_MOC_LITERAL(4, 38, 16), // "destroyRequested"
QT_MOC_LITERAL(5, 55, 7) // "destroy"

    },
    "AstroFile\0changed\0\0AstroFile::Members\0"
    "destroyRequested\0destroy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AstroFile[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void AstroFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AstroFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changed((*reinterpret_cast< AstroFile::Members(*)>(_a[1]))); break;
        case 1: _t->destroyRequested(); break;
        case 2: _t->destroy(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AstroFile::*)(AstroFile::Members );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AstroFile::changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AstroFile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AstroFile::destroyRequested)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AstroFile::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AstroFile.data,
    qt_meta_data_AstroFile,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AstroFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AstroFile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AstroFile.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AstroFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void AstroFile::changed(AstroFile::Members _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AstroFile::destroyRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_AstroFileHandler_t {
    QByteArrayData data[7];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AstroFileHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AstroFileHandler_t qt_meta_stringdata_AstroFileHandler = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AstroFileHandler"
QT_MOC_LITERAL(1, 17, 11), // "requestHelp"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "tag"
QT_MOC_LITERAL(4, 34, 15), // "fileUpdatedSlot"
QT_MOC_LITERAL(5, 50, 18), // "AstroFile::Members"
QT_MOC_LITERAL(6, 69, 17) // "fileDestroyedSlot"

    },
    "AstroFileHandler\0requestHelp\0\0tag\0"
    "fileUpdatedSlot\0AstroFile::Members\0"
    "fileDestroyedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AstroFileHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x08 /* Private */,
       6,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

       0        // eod
};

void AstroFileHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AstroFileHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestHelp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->fileUpdatedSlot((*reinterpret_cast< AstroFile::Members(*)>(_a[1]))); break;
        case 2: _t->fileDestroyedSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AstroFileHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AstroFileHandler::requestHelp)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AstroFileHandler::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_AstroFileHandler.data,
    qt_meta_data_AstroFileHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AstroFileHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AstroFileHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AstroFileHandler.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Customizable"))
        return static_cast< Customizable*>(this);
    return QWidget::qt_metacast(_clname);
}

int AstroFileHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void AstroFileHandler::requestHelp(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
