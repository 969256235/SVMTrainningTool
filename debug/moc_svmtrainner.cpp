/****************************************************************************
** Meta object code from reading C++ file 'svmtrainner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../svmtrainner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'svmtrainner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SVMTrainner_t {
    QByteArrayData data[11];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SVMTrainner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SVMTrainner_t qt_meta_stringdata_SVMTrainner = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SVMTrainner"
QT_MOC_LITERAL(1, 12, 30), // "on_platePropertyButton_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 27), // "on_plateTrainButton_clicked"
QT_MOC_LITERAL(4, 72, 29), // "on_loadPlateSetButton_clicked"
QT_MOC_LITERAL(5, 102, 30), // "on_plateSampleTree_itemClicked"
QT_MOC_LITERAL(6, 133, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(7, 150, 4), // "item"
QT_MOC_LITERAL(8, 155, 6), // "column"
QT_MOC_LITERAL(9, 162, 34), // "on_plateSampleChangeButton_cl..."
QT_MOC_LITERAL(10, 197, 34) // "on_plateSampleDeleteButton_cl..."

    },
    "SVMTrainner\0on_platePropertyButton_clicked\0"
    "\0on_plateTrainButton_clicked\0"
    "on_loadPlateSetButton_clicked\0"
    "on_plateSampleTree_itemClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_plateSampleChangeButton_clicked\0"
    "on_plateSampleDeleteButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SVMTrainner[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    2,   47,    2, 0x08 /* Private */,
       9,    0,   52,    2, 0x08 /* Private */,
      10,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SVMTrainner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SVMTrainner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_platePropertyButton_clicked(); break;
        case 1: _t->on_plateTrainButton_clicked(); break;
        case 2: _t->on_loadPlateSetButton_clicked(); break;
        case 3: _t->on_plateSampleTree_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_plateSampleChangeButton_clicked(); break;
        case 5: _t->on_plateSampleDeleteButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SVMTrainner::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_SVMTrainner.data,
    qt_meta_data_SVMTrainner,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SVMTrainner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SVMTrainner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SVMTrainner.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SVMTrainner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
