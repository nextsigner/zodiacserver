/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../zodiacserver/src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AstroFileInfo_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AstroFileInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AstroFileInfo_t qt_meta_stringdata_AstroFileInfo = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AstroFileInfo"
QT_MOC_LITERAL(1, 14, 7), // "clicked"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "AstroFileInfo\0clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AstroFileInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void AstroFileInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AstroFileInfo *_t = static_cast<AstroFileInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AstroFileInfo::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroFileInfo::clicked)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AstroFileInfo::staticMetaObject = {
    { &AstroFileHandler::staticMetaObject, qt_meta_stringdata_AstroFileInfo.data,
      qt_meta_data_AstroFileInfo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AstroFileInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AstroFileInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AstroFileInfo.stringdata0))
        return static_cast<void*>(const_cast< AstroFileInfo*>(this));
    return AstroFileHandler::qt_metacast(_clname);
}

int AstroFileInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AstroFileHandler::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void AstroFileInfo::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_AstroWidget_t {
    QByteArrayData data[14];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AstroWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AstroWidget_t qt_meta_stringdata_AstroWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AstroWidget"
QT_MOC_LITERAL(1, 12, 13), // "helpRequested"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "tag"
QT_MOC_LITERAL(4, 31, 19), // "appendFileRequested"
QT_MOC_LITERAL(5, 51, 18), // "swapFilesRequested"
QT_MOC_LITERAL(6, 70, 16), // "applyGeoSettings"
QT_MOC_LITERAL(7, 87, 12), // "AppSettings&"
QT_MOC_LITERAL(8, 100, 20), // "toolBarActionClicked"
QT_MOC_LITERAL(9, 121, 19), // "currentSlideChanged"
QT_MOC_LITERAL(10, 141, 23), // "horoscopeControlChanged"
QT_MOC_LITERAL(11, 165, 14), // "destroyingFile"
QT_MOC_LITERAL(12, 180, 13), // "destroyEditor"
QT_MOC_LITERAL(13, 194, 10) // "openEditor"

    },
    "AstroWidget\0helpRequested\0\0tag\0"
    "appendFileRequested\0swapFilesRequested\0"
    "applyGeoSettings\0AppSettings&\0"
    "toolBarActionClicked\0currentSlideChanged\0"
    "horoscopeControlChanged\0destroyingFile\0"
    "destroyEditor\0openEditor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AstroWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,
       5,    2,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   73,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AstroWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AstroWidget *_t = static_cast<AstroWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->helpRequested((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->appendFileRequested(); break;
        case 2: _t->swapFilesRequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->applyGeoSettings((*reinterpret_cast< AppSettings(*)>(_a[1]))); break;
        case 4: _t->toolBarActionClicked(); break;
        case 5: _t->currentSlideChanged(); break;
        case 6: _t->horoscopeControlChanged(); break;
        case 7: _t->destroyingFile(); break;
        case 8: _t->destroyEditor(); break;
        case 9: _t->openEditor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AstroWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroWidget::helpRequested)) {
                *result = 0;
            }
        }
        {
            typedef void (AstroWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroWidget::appendFileRequested)) {
                *result = 1;
            }
        }
        {
            typedef void (AstroWidget::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroWidget::swapFilesRequested)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject AstroWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AstroWidget.data,
      qt_meta_data_AstroWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AstroWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AstroWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AstroWidget.stringdata0))
        return static_cast<void*>(const_cast< AstroWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AstroWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void AstroWidget::helpRequested(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AstroWidget::appendFileRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void AstroWidget::swapFilesRequested(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_AstroDatabase_t {
    QByteArrayData data[13];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AstroDatabase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AstroDatabase_t qt_meta_stringdata_AstroDatabase = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AstroDatabase"
QT_MOC_LITERAL(1, 14, 11), // "fileRemoved"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "openFile"
QT_MOC_LITERAL(4, 36, 16), // "openFileInNewTab"
QT_MOC_LITERAL(5, 53, 16), // "openFileAsSecond"
QT_MOC_LITERAL(6, 70, 15), // "showContextMenu"
QT_MOC_LITERAL(7, 86, 12), // "openSelected"
QT_MOC_LITERAL(8, 99, 20), // "openSelectedInNewTab"
QT_MOC_LITERAL(9, 120, 20), // "openSelectedAsSecond"
QT_MOC_LITERAL(10, 141, 14), // "deleteSelected"
QT_MOC_LITERAL(11, 156, 12), // "searchFilter"
QT_MOC_LITERAL(12, 169, 10) // "updateList"

    },
    "AstroDatabase\0fileRemoved\0\0openFile\0"
    "openFileInNewTab\0openFileAsSecond\0"
    "showContextMenu\0openSelected\0"
    "openSelectedInNewTab\0openSelectedAsSecond\0"
    "deleteSelected\0searchFilter\0updateList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AstroDatabase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    1,   75,    2, 0x06 /* Public */,
       5,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   81,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    1,   88,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void AstroDatabase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AstroDatabase *_t = static_cast<AstroDatabase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileRemoved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->openFileInNewTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->openFileAsSecond((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->showContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->openSelected(); break;
        case 6: _t->openSelectedInNewTab(); break;
        case 7: _t->openSelectedAsSecond(); break;
        case 8: _t->deleteSelected(); break;
        case 9: _t->searchFilter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->updateList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AstroDatabase::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroDatabase::fileRemoved)) {
                *result = 0;
            }
        }
        {
            typedef void (AstroDatabase::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroDatabase::openFile)) {
                *result = 1;
            }
        }
        {
            typedef void (AstroDatabase::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroDatabase::openFileInNewTab)) {
                *result = 2;
            }
        }
        {
            typedef void (AstroDatabase::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AstroDatabase::openFileAsSecond)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject AstroDatabase::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_AstroDatabase.data,
      qt_meta_data_AstroDatabase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AstroDatabase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AstroDatabase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AstroDatabase.stringdata0))
        return static_cast<void*>(const_cast< AstroDatabase*>(this));
    return QFrame::qt_metacast(_clname);
}

int AstroDatabase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void AstroDatabase::fileRemoved(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AstroDatabase::openFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AstroDatabase::openFileInNewTab(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AstroDatabase::openFileAsSecond(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_FilesBar_t {
    QByteArrayData data[14];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilesBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilesBar_t qt_meta_stringdata_FilesBar = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FilesBar"
QT_MOC_LITERAL(1, 9, 8), // "swapTabs"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "fileUpdated"
QT_MOC_LITERAL(4, 31, 18), // "AstroFile::Members"
QT_MOC_LITERAL(5, 50, 13), // "fileDestroyed"
QT_MOC_LITERAL(6, 64, 10), // "addNewFile"
QT_MOC_LITERAL(7, 75, 16), // "swapCurrentFiles"
QT_MOC_LITERAL(8, 92, 8), // "openFile"
QT_MOC_LITERAL(9, 101, 4), // "name"
QT_MOC_LITERAL(10, 106, 16), // "openFileInNewTab"
QT_MOC_LITERAL(11, 123, 16), // "openFileAsSecond"
QT_MOC_LITERAL(12, 140, 7), // "nextTab"
QT_MOC_LITERAL(13, 148, 8) // "closeTab"

    },
    "FilesBar\0swapTabs\0\0fileUpdated\0"
    "AstroFile::Members\0fileDestroyed\0"
    "addNewFile\0swapCurrentFiles\0openFile\0"
    "name\0openFileInNewTab\0openFileAsSecond\0"
    "nextTab\0closeTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilesBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x08 /* Private */,
       3,    1,   74,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    2,   79,    2, 0x0a /* Public */,
       8,    1,   84,    2, 0x0a /* Public */,
      10,    1,   87,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x2a /* Public | MethodCloned */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    1,   95,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int,    2,

       0        // eod
};

void FilesBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilesBar *_t = static_cast<FilesBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->swapTabs((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->fileUpdated((*reinterpret_cast< AstroFile::Members(*)>(_a[1]))); break;
        case 2: _t->fileDestroyed(); break;
        case 3: _t->addNewFile(); break;
        case 4: _t->swapCurrentFiles((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->openFileInNewTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->openFileAsSecond((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->openFileAsSecond(); break;
        case 9: _t->nextTab(); break;
        case 10: { bool _r = _t->closeTab((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject FilesBar::staticMetaObject = {
    { &QTabBar::staticMetaObject, qt_meta_stringdata_FilesBar.data,
      qt_meta_data_FilesBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FilesBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilesBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FilesBar.stringdata0))
        return static_cast<void*>(const_cast< FilesBar*>(this));
    return QTabBar::qt_metacast(_clname);
}

int FilesBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[10];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "saveFile"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 17), // "currentTabChanged"
QT_MOC_LITERAL(4, 39, 18), // "showSettingsEditor"
QT_MOC_LITERAL(5, 58, 9), // "showAbout"
QT_MOC_LITERAL(6, 68, 7), // "gotoUrl"
QT_MOC_LITERAL(7, 76, 3), // "url"
QT_MOC_LITERAL(8, 80, 11), // "contextMenu"
QT_MOC_LITERAL(9, 92, 7) // "capture"

    },
    "MainWindow\0saveFile\0\0currentTabChanged\0"
    "showSettingsEditor\0showAbout\0gotoUrl\0"
    "url\0contextMenu\0capture"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x28 /* Private | MethodCloned */,
       8,    1,   62,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveFile(); break;
        case 1: _t->currentTabChanged(); break;
        case 2: _t->showSettingsEditor(); break;
        case 3: _t->showAbout(); break;
        case 4: _t->gotoUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->gotoUrl(); break;
        case 6: _t->contextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->capture(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "Customizable"))
        return static_cast< Customizable*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
