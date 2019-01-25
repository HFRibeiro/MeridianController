/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "openSerialPort"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "port_name"
QT_MOC_LITERAL(4, 37, 8), // "baudrate"
QT_MOC_LITERAL(5, 46, 15), // "closeSerialPort"
QT_MOC_LITERAL(6, 62, 8), // "readData"
QT_MOC_LITERAL(7, 71, 11), // "handleError"
QT_MOC_LITERAL(8, 83, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(9, 112, 5), // "error"
QT_MOC_LITERAL(10, 118, 9), // "writeData"
QT_MOC_LITERAL(11, 128, 4), // "data"
QT_MOC_LITERAL(12, 133, 16), // "acceptConnection"
QT_MOC_LITERAL(13, 150, 9), // "startRead"
QT_MOC_LITERAL(14, 160, 9), // "work_data"
QT_MOC_LITERAL(15, 170, 18), // "on_bt_open_clicked"
QT_MOC_LITERAL(16, 189, 19), // "on_bt_close_clicked"
QT_MOC_LITERAL(17, 209, 18), // "on_bt_send_clicked"
QT_MOC_LITERAL(18, 228, 12), // "disconnected"
QT_MOC_LITERAL(19, 241, 17), // "on_bt_DTR_clicked"
QT_MOC_LITERAL(20, 259, 17), // "on_rb_Sul_clicked"
QT_MOC_LITERAL(21, 277, 7), // "checked"
QT_MOC_LITERAL(22, 285, 19) // "on_rB_norte_clicked"

    },
    "MainWindow\0openSerialPort\0\0port_name\0"
    "baudrate\0closeSerialPort\0readData\0"
    "handleError\0QSerialPort::SerialPortError\0"
    "error\0writeData\0data\0acceptConnection\0"
    "startRead\0work_data\0on_bt_open_clicked\0"
    "on_bt_close_clicked\0on_bt_send_clicked\0"
    "disconnected\0on_bt_DTR_clicked\0"
    "on_rb_Sul_clicked\0checked\0on_rB_norte_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x08 /* Private */,
       5,    0,   94,    2, 0x08 /* Private */,
       6,    0,   95,    2, 0x08 /* Private */,
       7,    1,   96,    2, 0x08 /* Private */,
      10,    1,   99,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    1,  104,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,
      18,    0,  110,    2, 0x08 /* Private */,
      19,    0,  111,    2, 0x08 /* Private */,
      20,    1,  112,    2, 0x08 /* Private */,
      22,    1,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openSerialPort((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->closeSerialPort(); break;
        case 2: _t->readData(); break;
        case 3: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 4: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->acceptConnection(); break;
        case 6: _t->startRead(); break;
        case 7: _t->work_data((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->on_bt_open_clicked(); break;
        case 9: _t->on_bt_close_clicked(); break;
        case 10: _t->on_bt_send_clicked(); break;
        case 11: _t->disconnected(); break;
        case 12: _t->on_bt_DTR_clicked(); break;
        case 13: _t->on_rb_Sul_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_rB_norte_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
