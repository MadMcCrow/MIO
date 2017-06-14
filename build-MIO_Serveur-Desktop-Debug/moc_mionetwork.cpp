/****************************************************************************
** Meta object code from reading C++ file 'mionetwork.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MIO_Server/mionetwork.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mionetwork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MIONetwork_t {
    QByteArrayData data[12];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MIONetwork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MIONetwork_t qt_meta_stringdata_MIONetwork = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MIONetwork"
QT_MOC_LITERAL(1, 11, 14), // "receivedData_s"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "QDataStream&"
QT_MOC_LITERAL(4, 40, 7), // "toLog_s"
QT_MOC_LITERAL(5, 48, 17), // "startNetworking_c"
QT_MOC_LITERAL(6, 66, 10), // "sendData_c"
QT_MOC_LITERAL(7, 77, 3), // "key"
QT_MOC_LITERAL(8, 81, 6), // "stream"
QT_MOC_LITERAL(9, 88, 15), // "newConnection_c"
QT_MOC_LITERAL(10, 104, 15), // "endConnection_c"
QT_MOC_LITERAL(11, 120, 14) // "qtcpReceived_c"

    },
    "MIONetwork\0receivedData_s\0\0QDataStream&\0"
    "toLog_s\0startNetworking_c\0sendData_c\0"
    "key\0stream\0newConnection_c\0endConnection_c\0"
    "qtcpReceived_c"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MIONetwork[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       4,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   59,    2, 0x0a /* Public */,
       6,    2,   60,    2, 0x0a /* Public */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 3,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MIONetwork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MIONetwork *_t = static_cast<MIONetwork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedData_s((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 1: _t->toLog_s((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->startNetworking_c(); break;
        case 3: _t->sendData_c((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 4: _t->newConnection_c(); break;
        case 5: _t->endConnection_c(); break;
        case 6: _t->qtcpReceived_c(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MIONetwork::*_t)(quint8 , QDataStream & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MIONetwork::receivedData_s)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MIONetwork::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MIONetwork::toLog_s)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MIONetwork::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MIONetwork.data,
      qt_meta_data_MIONetwork,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MIONetwork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MIONetwork::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MIONetwork.stringdata0))
        return static_cast<void*>(const_cast< MIONetwork*>(this));
    return QObject::qt_metacast(_clname);
}

int MIONetwork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void MIONetwork::receivedData_s(quint8 _t1, QDataStream & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MIONetwork::toLog_s(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
