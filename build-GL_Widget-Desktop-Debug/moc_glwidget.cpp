/****************************************************************************
** Meta object code from reading C++ file 'glwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GL_widget/glwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GLWidget_t {
    QByteArrayData data[20];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GLWidget_t qt_meta_stringdata_GLWidget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GLWidget"
QT_MOC_LITERAL(1, 9, 21), // "xWorldRotationChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "angle"
QT_MOC_LITERAL(4, 38, 21), // "yWorldRotationChanged"
QT_MOC_LITERAL(5, 60, 21), // "zWorldRotationChanged"
QT_MOC_LITERAL(6, 82, 13), // "rColorChanged"
QT_MOC_LITERAL(7, 96, 5), // "color"
QT_MOC_LITERAL(8, 102, 13), // "gColorChanged"
QT_MOC_LITERAL(9, 116, 13), // "bColorChanged"
QT_MOC_LITERAL(10, 130, 17), // "setXWorldRotation"
QT_MOC_LITERAL(11, 148, 17), // "setYWorldRotation"
QT_MOC_LITERAL(12, 166, 17), // "setZWorldRotation"
QT_MOC_LITERAL(13, 184, 7), // "cleanup"
QT_MOC_LITERAL(14, 192, 9), // "setRColor"
QT_MOC_LITERAL(15, 202, 1), // "r"
QT_MOC_LITERAL(16, 204, 9), // "setGColor"
QT_MOC_LITERAL(17, 214, 1), // "g"
QT_MOC_LITERAL(18, 216, 9), // "setBColor"
QT_MOC_LITERAL(19, 226, 1) // "b"

    },
    "GLWidget\0xWorldRotationChanged\0\0angle\0"
    "yWorldRotationChanged\0zWorldRotationChanged\0"
    "rColorChanged\0color\0gColorChanged\0"
    "bColorChanged\0setXWorldRotation\0"
    "setYWorldRotation\0setZWorldRotation\0"
    "cleanup\0setRColor\0r\0setGColor\0g\0"
    "setBColor\0b"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    1,   85,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,
       8,    1,   91,    2, 0x06 /* Public */,
       9,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   97,    2, 0x0a /* Public */,
      11,    1,  100,    2, 0x0a /* Public */,
      12,    1,  103,    2, 0x0a /* Public */,
      13,    0,  106,    2, 0x0a /* Public */,
      14,    1,  107,    2, 0x0a /* Public */,
      16,    1,  110,    2, 0x0a /* Public */,
      18,    1,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Float,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   15,
    QMetaType::Void, QMetaType::Float,   17,
    QMetaType::Void, QMetaType::Float,   19,

       0        // eod
};

void GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GLWidget *_t = static_cast<GLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xWorldRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yWorldRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zWorldRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->rColorChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->gColorChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->bColorChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->setXWorldRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setYWorldRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setZWorldRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->cleanup(); break;
        case 10: _t->setRColor((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->setGColor((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: _t->setBColor((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLWidget::xWorldRotationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLWidget::yWorldRotationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLWidget::zWorldRotationChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GLWidget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLWidget::rColorChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GLWidget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLWidget::gColorChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (GLWidget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLWidget::bColorChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject GLWidget::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_GLWidget.data,
      qt_meta_data_GLWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget.stringdata0))
        return static_cast<void*>(const_cast< GLWidget*>(this));
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(const_cast< GLWidget*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void GLWidget::xWorldRotationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GLWidget::yWorldRotationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GLWidget::zWorldRotationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GLWidget::rColorChanged(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GLWidget::gColorChanged(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GLWidget::bColorChanged(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
