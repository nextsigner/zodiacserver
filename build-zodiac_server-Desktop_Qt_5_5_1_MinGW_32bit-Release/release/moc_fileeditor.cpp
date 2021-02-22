/****************************************************************************
** Meta object code from reading C++ file 'fileeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../fileeditor/src/fileeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AstroFileEditor_t {
    QByteArrayData data[10];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AstroFileEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AstroFileEditor_t qt_meta_stringdata_AstroFileEditor = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AstroFileEditor"
QT_MOC_LITERAL(1, 16, 12), // "windowClosed"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "appendFile"
QT_MOC_LITERAL(4, 41, 9), // "swapFiles"
QT_MOC_LITERAL(5, 51, 13), // "swapFilesSlot"
QT_MOC_LITERAL(6, 65, 17), // "currentTabChanged"
QT_MOC_LITERAL(7, 83, 9), // "removeTab"
QT_MOC_LITERAL(8, 93, 11), // "applyToFile"
QT_MOC_LITERAL(9, 105, 15) // "timezoneChanged"

    },
    "AstroFileEditor\0windowClosed\0\0appendFile\0"
    "swapFiles\0swapFilesSlot\0currentTabChanged\0"
    "removeTab\0applyToFile\0timezoneChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AstroFileEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    2,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   61,    2, 0x08 /* Private */,
       6,    1,   66,    2, 0x08 /* Private */,
       7,    1,   69,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AstroFileEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AstroFileEditor *_t = static_cast<AstroFileEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->windowClosed(); break;
        case 1: _t->appendFile(); break;
        case 2: _t->swapFiles((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->swapFilesSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->currentTabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->removeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->applyToFile(); break;
        case 7: _t->timezoneChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AstroFileEditor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroFileEditor::windowClosed)) {
                *result = 0;
            }
        }
        {
            typedef void (AstroFileEditor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroFileEditor::appendFile)) {
                *result = 1;
            }
        }
        {
            typedef void (AstroFileEditor::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroFileEditor::swapFiles)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject AstroFileEditor::staticMetaObject = {
    { &AstroFileHandler::staticMetaObject, qt_meta_stringdata_AstroFileEditor.data,
      qt_meta_data_AstroFileEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AstroFileEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AstroFileEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AstroFileEditor.stringdata0))
        return static_cast<void*>(const_cast< AstroFileEditor*>(this));
    return AstroFileHandler::qt_metacast(_clname);
}

int AstroFileEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AstroFileHandler::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AstroFileEditor::windowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AstroFileEditor::appendFile()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void AstroFileEditor::swapFiles(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
