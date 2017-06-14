/****************************************************************************
** Meta object code from reading C++ file 'miowindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MIO_Server/miowindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'miowindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MIOWindow_t {
    QByteArrayData data[17];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MIOWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MIOWindow_t qt_meta_stringdata_MIOWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MIOWindow"
QT_MOC_LITERAL(1, 10, 7), // "toLog_s"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "texte"
QT_MOC_LITERAL(4, 25, 8), // "priority"
QT_MOC_LITERAL(5, 34, 6), // "quit_s"
QT_MOC_LITERAL(6, 41, 18), // "updateGLSkeleton_s"
QT_MOC_LITERAL(7, 60, 10), // "GLSkeleton"
QT_MOC_LITERAL(8, 71, 2), // "sk"
QT_MOC_LITERAL(9, 74, 18), // "finishedGLUpdate_s"
QT_MOC_LITERAL(10, 93, 15), // "receiveGlData_c"
QT_MOC_LITERAL(11, 109, 6), // "Frame*"
QT_MOC_LITERAL(12, 116, 1), // "F"
QT_MOC_LITERAL(13, 118, 18), // "receivedGLnotify_c"
QT_MOC_LITERAL(14, 137, 14), // "ErrorOnOther_c"
QT_MOC_LITERAL(15, 152, 6), // "size_t"
QT_MOC_LITERAL(16, 159, 7) // "ErrCode"

    },
    "MIOWindow\0toLog_s\0\0texte\0priority\0"
    "quit_s\0updateGLSkeleton_s\0GLSkeleton\0"
    "sk\0finishedGLUpdate_s\0receiveGlData_c\0"
    "Frame*\0F\0receivedGLnotify_c\0ErrorOnOther_c\0"
    "size_t\0ErrCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MIOWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    0,   54,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,
       9,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   59,    2, 0x0a /* Public */,
      13,    0,   62,    2, 0x0a /* Public */,
      14,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void MIOWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MIOWindow *_t = static_cast<MIOWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toLog_s((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->quit_s(); break;
        case 2: _t->updateGLSkeleton_s((*reinterpret_cast< GLSkeleton(*)>(_a[1]))); break;
        case 3: _t->finishedGLUpdate_s(); break;
        case 4: _t->receiveGlData_c((*reinterpret_cast< Frame*(*)>(_a[1]))); break;
        case 5: _t->receivedGLnotify_c(); break;
        case 6: _t->ErrorOnOther_c((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MIOWindow::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MIOWindow::toLog_s)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MIOWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MIOWindow::quit_s)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MIOWindow::*_t)(GLSkeleton );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MIOWindow::updateGLSkeleton_s)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MIOWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MIOWindow::finishedGLUpdate_s)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MIOWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MIOWindow.data,
      qt_meta_data_MIOWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MIOWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MIOWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MIOWindow.stringdata0))
        return static_cast<void*>(const_cast< MIOWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MIOWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void MIOWindow::toLog_s(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MIOWindow::quit_s()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MIOWindow::updateGLSkeleton_s(GLSkeleton _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MIOWindow::finishedGLUpdate_s()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
