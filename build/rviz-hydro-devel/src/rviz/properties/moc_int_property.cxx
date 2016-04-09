/****************************************************************************
** Meta object code from reading C++ file 'int_property.h'
**
** Created: Fri Feb 5 05:35:36 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/int_property.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'int_property.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__IntProperty[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      29,   19,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rviz__IntProperty[] = {
    "rviz::IntProperty\0\0new_value\0setInt(int)\0"
};

void rviz::IntProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IntProperty *_t = static_cast<IntProperty *>(_o);
        switch (_id) {
        case 0: _t->setInt((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::IntProperty::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::IntProperty::staticMetaObject = {
    { &Property::staticMetaObject, qt_meta_stringdata_rviz__IntProperty,
      qt_meta_data_rviz__IntProperty, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::IntProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::IntProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::IntProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__IntProperty))
        return static_cast<void*>(const_cast< IntProperty*>(this));
    return Property::qt_metacast(_clname);
}

int rviz::IntProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Property::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
