/****************************************************************************
** Meta object code from reading C++ file 'property.h'
**
** Created: Tue May 12 17:13:13 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/property.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'property.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__Property[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      32,   15,   15,   15, 0x05,
      56,   42,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_rviz__Property[] = {
    "rviz::Property\0\0aboutToChange()\0"
    "changed()\0this_property\0"
    "childListChanged(Property*)\0"
};

void rviz::Property::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Property *_t = static_cast<Property *>(_o);
        switch (_id) {
        case 0: _t->aboutToChange(); break;
        case 1: _t->changed(); break;
        case 2: _t->childListChanged((*reinterpret_cast< Property*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::Property::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::Property::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rviz__Property,
      qt_meta_data_rviz__Property, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::Property::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::Property::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::Property::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__Property))
        return static_cast<void*>(const_cast< Property*>(this));
    return QObject::qt_metacast(_clname);
}

int rviz::Property::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void rviz::Property::aboutToChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void rviz::Property::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void rviz::Property::childListChanged(Property * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
