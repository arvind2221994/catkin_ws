/****************************************************************************
** Meta object code from reading C++ file 'range_display.h'
**
** Created: Fri Feb 5 05:37:15 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/range_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'range_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__RangeDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      41,   19,   19,   19, 0x08,
      63,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__RangeDisplay[] = {
    "rviz::RangeDisplay\0\0updateBufferLength()\0"
    "updateColorAndAlpha()\0updateQueueSize()\0"
};

void rviz::RangeDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RangeDisplay *_t = static_cast<RangeDisplay *>(_o);
        switch (_id) {
        case 0: _t->updateBufferLength(); break;
        case 1: _t->updateColorAndAlpha(); break;
        case 2: _t->updateQueueSize(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::RangeDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::RangeDisplay::staticMetaObject = {
    { &MessageFilterDisplay<sensor_msgs::Range>::staticMetaObject, qt_meta_stringdata_rviz__RangeDisplay,
      qt_meta_data_rviz__RangeDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::RangeDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::RangeDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::RangeDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__RangeDisplay))
        return static_cast<void*>(const_cast< RangeDisplay*>(this));
    typedef MessageFilterDisplay<sensor_msgs::Range> QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int rviz::RangeDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef MessageFilterDisplay<sensor_msgs::Range> QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
