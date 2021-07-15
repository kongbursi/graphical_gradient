/****************************************************************************
** Meta object code from reading C++ file 'MainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MainWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[11];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "ShowShape"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "ShowPenWidth"
QT_MOC_LITERAL(4, 35, 12), // "ShowPenColor"
QT_MOC_LITERAL(5, 48, 12), // "ShowPenStyle"
QT_MOC_LITERAL(6, 61, 10), // "ShowPenCap"
QT_MOC_LITERAL(7, 72, 11), // "ShowPenJoin"
QT_MOC_LITERAL(8, 84, 8), // "ShowFill"
QT_MOC_LITERAL(9, 93, 14), // "ShowBrushColor"
QT_MOC_LITERAL(10, 108, 9) // "ShowBrush"

    },
    "MainWindow\0ShowShape\0\0ShowPenWidth\0"
    "ShowPenColor\0ShowPenStyle\0ShowPenCap\0"
    "ShowPenJoin\0ShowFill\0ShowBrushColor\0"
    "ShowBrush"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x09 /* Protected */,
       3,    1,   62,    2, 0x09 /* Protected */,
       4,    0,   65,    2, 0x09 /* Protected */,
       5,    1,   66,    2, 0x09 /* Protected */,
       6,    1,   69,    2, 0x09 /* Protected */,
       7,    1,   72,    2, 0x09 /* Protected */,
       8,    0,   75,    2, 0x09 /* Protected */,
       9,    0,   76,    2, 0x09 /* Protected */,
      10,    1,   77,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowShape((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ShowPenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ShowPenColor(); break;
        case 3: _t->ShowPenStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ShowPenCap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->ShowPenJoin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->ShowFill(); break;
        case 7: _t->ShowBrushColor(); break;
        case 8: _t->ShowBrush((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow.data,
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
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
