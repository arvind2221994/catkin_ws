/****************************************************************************
** Meta object code from reading C++ file 'vector_property.h'
**
** Created: Fri Feb 5 05:35:37 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/vector_property.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vector_property.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__VectorProperty[] = {

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
      22,   21,   21,   21, 0x08,
      43,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__VectorProperty[] = {
    "rviz::VectorProperty\0\0updateFromChildren()\0"
    "emitAboutToChange()\0"
};

void rviz::VectorProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VectorProperty *_t = static_cast<VectorProperty *>(_o);
        switch (_id) {
        case 0: _t->updateFromChildren(); break;
        case 1: _t->emitAboutToChange(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::VectorProperty::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::VectorProperty::staticMetaObject = {
    { &Property::staticMetaObject, qt_meta_stringdata_rviz__VectorProperty,
      qt_meta_data_rviz__VectorProperty, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::VectorProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::VectorProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::VectorProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__VectorProperty))
        return static_cast<void*>(const_cast< VectorProperty*>(this));
    return Property::qt_metacast(_clname);
}

int rviz::VectorProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Property::qt_metacall(_c, _id, _a);
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
