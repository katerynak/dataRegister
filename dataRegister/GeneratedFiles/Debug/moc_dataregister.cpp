/****************************************************************************
** Meta object code from reading C++ file 'dataregister.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dataregister.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataregister.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dataRegister_t {
    QByteArrayData data[9];
    char stringdata[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dataRegister_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dataRegister_t qt_meta_stringdata_dataRegister = {
    {
QT_MOC_LITERAL(0, 0, 12), // "dataRegister"
QT_MOC_LITERAL(1, 13, 7), // "Process"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "startRecording"
QT_MOC_LITERAL(4, 37, 13), // "stopRecording"
QT_MOC_LITERAL(5, 51, 13), // "saveRecording"
QT_MOC_LITERAL(6, 65, 15), // "openPreferences"
QT_MOC_LITERAL(7, 81, 16), // "closePreferences"
QT_MOC_LITERAL(8, 98, 6) // "resume"

    },
    "dataRegister\0Process\0\0startRecording\0"
    "stopRecording\0saveRecording\0openPreferences\0"
    "closePreferences\0resume"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dataRegister[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dataRegister::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dataRegister *_t = static_cast<dataRegister *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->Process();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->startRecording(); break;
        case 2: _t->stopRecording(); break;
        case 3: _t->saveRecording(); break;
        case 4: _t->openPreferences(); break;
        case 5: _t->closePreferences(); break;
        case 6: _t->resume(); break;
        default: ;
        }
    }
}

const QMetaObject dataRegister::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_dataRegister.data,
      qt_meta_data_dataRegister,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dataRegister::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dataRegister::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dataRegister.stringdata))
        return static_cast<void*>(const_cast< dataRegister*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int dataRegister::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
