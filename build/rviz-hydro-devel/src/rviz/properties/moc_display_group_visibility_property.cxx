/****************************************************************************
** Meta object code from reading C++ file 'display_group_visibility_property.h'
**
** Created: Fri Feb 5 05:35:36 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/display_group_visibility_property.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display_group_visibility_property.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__DisplayGroupVisibilityProperty[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      46,   38,   37,   37, 0x0a,
      77,   38,   37,   37, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rviz__DisplayGroupVisibilityProperty[] = {
    "rviz::DisplayGroupVisibilityProperty\0"
    "\0display\0onDisplayAdded(rviz::Display*)\0"
    "onDisplayRemoved(rviz::Display*)\0"
};

void rviz::DisplayGroupVisibilityProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DisplayGroupVisibilityProperty *_t = static_cast<DisplayGroupVisibilityProperty *>(_o);
        switch (_id) {
        case 0: _t->onDisplayAdded((*reinterpret_cast< rviz::Display*(*)>(_a[1]))); break;
        case 1: _t->onDisplayRemoved((*reinterpret_cast< rviz::Display*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::DisplayGroupVisibilityProperty::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::DisplayGroupVisibilityProperty::staticMetaObject = {
    { &DisplayVisibilityProperty::staticMetaObject, qt_meta_stringdata_rviz__DisplayGroupVisibilityProperty,
      qt_meta_data_rviz__DisplayGroupVisibilityProperty, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::DisplayGroupVisibilityProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::DisplayGroupVisibilityProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::DisplayGroupVisibilityProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__DisplayGroupVisibilityProperty))
        return static_cast<void*>(const_cast< DisplayGroupVisibilityProperty*>(this));
    return DisplayVisibilityProperty::qt_metacast(_clname);
}

int rviz::DisplayGroupVisibilityProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DisplayVisibilityProperty::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
