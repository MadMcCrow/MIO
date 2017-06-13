/****************************************************************************
** Meta object code from reading C++ file 'miowindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MIO_Client/miowindow.h"
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
    QByteArrayData data[16];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MIOWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MIOWindow_t qt_meta_stringdata_MIOWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MIOWindow"
QT_MOC_LITERAL(1, 10, 6), // "quit_s"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 18), // "updateGLSkeleton_s"
QT_MOC_LITERAL(4, 37, 10), // "GLSkeleton"
QT_MOC_LITERAL(5, 48, 2), // "sk"
QT_MOC_LITERAL(6, 51, 18), // "finishedGLUpdate_s"
QT_MOC_LITERAL(7, 70, 14), // "showSettings_c"
QT_MOC_LITERAL(8, 85, 6), // "quit_c"
QT_MOC_LITERAL(9, 92, 15), // "receiveGlData_c"
QT_MOC_LITERAL(10, 108, 6), // "Frame*"
QT_MOC_LITERAL(11, 115, 1), // "F"
QT_MOC_LITERAL(12, 117, 18), // "receivedGLnotify_c"
QT_MOC_LITERAL(13, 136, 14), // "ErrorOnOther_c"
QT_MOC_LITERAL(14, 151, 6), // "size_t"
QT_MOC_LITERAL(15, 158, 7) // "ErrCode"

    },
    "MIOWindow\0quit_s\0\0updateGLSkeleton_s\0"
    "GLSkeleton\0sk\0finishedGLUpdate_s\0"
    "showSettings_c\0quit_c\0receiveGlData_c\0"
    "Frame*\0F\0receivedGLnotify_c\0ErrorOnOther_c\0"
    "size_t\0ErrCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MIOWindow[] = {

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
       3,    1,   55,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    1,   61,    2, 0x0a /* Public */,
      12,    0,   64,    2, 0x0a /* Public */,
      13,    1,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void MIOWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MIOWindow *_t = static_cast<MIOWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->quit_s(); break;
        case 1: _t->updateGLSkeleton_s((*reinterpret_cast< GLSkeleton(*)>(_a[1]))); break;
        case 2: _t->finishedGLUpdate_s(); break;
        case 3: _t->showSettings_c(); break;
        case 4: _t->quit_c(); break;
        case 5: _t->receiveGlData_c((*reinterpret_cast< Frame*(*)>(_a[1]))); break;
        case 6: _t->receivedGLnotify_c(); break;
        case 7: _t->ErrorOnOther_c((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MIOWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MIOWindow::quit_s)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MIOWindow::*_t)(GLSkeleton );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MIOWindow::updateGLSkeleton_s)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MIOWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MIOWindow::finishedGLUpdate_s)) {
                *result = 2;
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
void MIOWindow::quit_s()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MIOWindow::updateGLSkeleton_s(GLSkeleton _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MIOWindow::finishedGLUpdate_s()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
