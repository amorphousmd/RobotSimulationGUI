/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Display3DModel/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[402];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 35), // "on_verticalSlider_Roll_valueC..."
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 5), // "value"
QT_MOC_LITERAL(4, 54, 36), // "on_verticalSlider_Pitch_value..."
QT_MOC_LITERAL(5, 91, 34), // "on_verticalSlider_Yaw_valueCh..."
QT_MOC_LITERAL(6, 126, 37), // "on_verticalSlider_transX_valu..."
QT_MOC_LITERAL(7, 164, 37), // "on_verticalSlider_transY_valu..."
QT_MOC_LITERAL(8, 202, 37), // "on_verticalSlider_transZ_valu..."
QT_MOC_LITERAL(9, 240, 21), // "on_pushButton_pressed"
QT_MOC_LITERAL(10, 262, 34), // "on_horizontalSliderJ1_valueCh..."
QT_MOC_LITERAL(11, 297, 34), // "on_horizontalSliderJ2_valueCh..."
QT_MOC_LITERAL(12, 332, 34), // "on_horizontalSliderJ3_valueCh..."
QT_MOC_LITERAL(13, 367, 34) // "on_horizontalSliderJ4_valueCh..."

    },
    "MainWindow\0on_verticalSlider_Roll_valueChanged\0"
    "\0value\0on_verticalSlider_Pitch_valueChanged\0"
    "on_verticalSlider_Yaw_valueChanged\0"
    "on_verticalSlider_transX_valueChanged\0"
    "on_verticalSlider_transY_valueChanged\0"
    "on_verticalSlider_transZ_valueChanged\0"
    "on_pushButton_pressed\0"
    "on_horizontalSliderJ1_valueChanged\0"
    "on_horizontalSliderJ2_valueChanged\0"
    "on_horizontalSliderJ3_valueChanged\0"
    "on_horizontalSliderJ4_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    1,   72,    2, 0x08 /* Private */,
       5,    1,   75,    2, 0x08 /* Private */,
       6,    1,   78,    2, 0x08 /* Private */,
       7,    1,   81,    2, 0x08 /* Private */,
       8,    1,   84,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      11,    1,   91,    2, 0x08 /* Private */,
      12,    1,   94,    2, 0x08 /* Private */,
      13,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_verticalSlider_Roll_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_verticalSlider_Pitch_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_verticalSlider_Yaw_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_verticalSlider_transX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_verticalSlider_transY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_verticalSlider_transZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_pressed(); break;
        case 7: _t->on_horizontalSliderJ1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_horizontalSliderJ2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_horizontalSliderJ3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_horizontalSliderJ4_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
