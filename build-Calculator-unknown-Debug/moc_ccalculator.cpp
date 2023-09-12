/****************************************************************************
** Meta object code from reading C++ file 'ccalculator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Calculator/ccalculator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccalculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CCalculator_t {
    QByteArrayData data[12];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CCalculator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CCalculator_t qt_meta_stringdata_CCalculator = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CCalculator"
QT_MOC_LITERAL(1, 12, 8), // "ClearAll"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "Back"
QT_MOC_LITERAL(4, 27, 10), // "ShowResult"
QT_MOC_LITERAL(5, 38, 16), // "EnterAnotherPage"
QT_MOC_LITERAL(6, 55, 15), // "EnterTrangleLnv"
QT_MOC_LITERAL(7, 71, 15), // "EnterTrangleHyp"
QT_MOC_LITERAL(8, 87, 9), // "GetResult"
QT_MOC_LITERAL(9, 97, 11), // "OtherButton"
QT_MOC_LITERAL(10, 109, 20), // "ClickButtonOfTrangle"
QT_MOC_LITERAL(11, 130, 21) // "ClickButtonOfFunction"

    },
    "CCalculator\0ClearAll\0\0Back\0ShowResult\0"
    "EnterAnotherPage\0EnterTrangleLnv\0"
    "EnterTrangleHyp\0GetResult\0OtherButton\0"
    "ClickButtonOfTrangle\0ClickButtonOfFunction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CCalculator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CCalculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CCalculator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClearAll(); break;
        case 1: _t->Back(); break;
        case 2: _t->ShowResult(); break;
        case 3: _t->EnterAnotherPage(); break;
        case 4: _t->EnterTrangleLnv(); break;
        case 5: _t->EnterTrangleHyp(); break;
        case 6: _t->GetResult(); break;
        case 7: _t->OtherButton(); break;
        case 8: _t->ClickButtonOfTrangle(); break;
        case 9: _t->ClickButtonOfFunction(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CCalculator::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CCalculator.data,
    qt_meta_data_CCalculator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CCalculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CCalculator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CCalculator.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CCalculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
