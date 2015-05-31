/****************************************************************************
** Meta object code from reading C++ file 'bool_property.h'
**
** Created: Tue May 12 17:13:12 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/bool_property.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bool_property.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__BoolProperty[] = {

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
      31,   25,   20,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rviz__BoolProperty[] = {
    "rviz::BoolProperty\0\0bool\0value\0"
    "setBool(bool)\0"
};

void rviz::BoolProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BoolProperty *_t = static_cast<BoolProperty *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->setBool((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::BoolProperty::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::BoolProperty::staticMetaObject = {
    { &Property::staticMetaObject, qt_meta_stringdata_rviz__BoolProperty,
      qt_meta_data_rviz__BoolProperty, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::BoolProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::BoolProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::BoolProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__BoolProperty))
        return static_cast<void*>(const_cast< BoolProperty*>(this));
    return Property::qt_metacast(_clname);
}

int rviz::BoolProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
