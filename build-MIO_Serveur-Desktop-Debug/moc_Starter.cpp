/****************************************************************************
** Meta object code from reading C++ file 'Starter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MIO_Server/mio/Starter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Starter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Starter_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Starter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Starter_t qt_meta_stringdata_Starter = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Starter"
QT_MOC_LITERAL(1, 8, 15), // "DataRetrieved_s"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 6), // "Frame*"
QT_MOC_LITERAL(4, 32, 18), // "ConnectionFailed_s"
QT_MOC_LITERAL(5, 51, 18), // "ConnectionSucces_s"
QT_MOC_LITERAL(6, 70, 8), // "finished"
QT_MOC_LITERAL(7, 79, 12), // "retrieveData"
QT_MOC_LITERAL(8, 92, 9) // "terminate"

    },
    "Starter\0DataRetrieved_s\0\0Frame*\0"
    "ConnectionFailed_s\0ConnectionSucces_s\0"
    "finished\0retrieveData\0terminate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Starter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,
       6,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Starter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Starter *_t = static_cast<Starter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DataRetrieved_s((*reinterpret_cast< Frame*(*)>(_a[1]))); break;
        case 1: _t->ConnectionFailed_s(); break;
        case 2: _t->ConnectionSucces_s(); break;
        case 3: _t->finished(); break;
        case 4: _t->retrieveData(); break;
        case 5: _t->terminate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Starter::*_t)(Frame * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Starter::DataRetrieved_s)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Starter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Starter::ConnectionFailed_s)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Starter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Starter::ConnectionSucces_s)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Starter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Starter::finished)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Starter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Starter.data,
      qt_meta_data_Starter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Starter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Starter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Starter.stringdata0))
        return static_cast<void*>(const_cast< Starter*>(this));
    return QObject::qt_metacast(_clname);
}

int Starter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Starter::DataRetrieved_s(Frame * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Starter::ConnectionFailed_s()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Starter::ConnectionSucces_s()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Starter::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
