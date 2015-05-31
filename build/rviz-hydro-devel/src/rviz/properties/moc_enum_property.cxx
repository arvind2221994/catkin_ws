/****************************************************************************
** Meta object code from reading C++ file 'enum_property.h'
**
** Created: Tue May 12 17:13:13 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/enum_property.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enum_property.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__EnumProperty[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      48,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      82,   78,   19,   19, 0x0a,
     101,   78,   19,   19, 0x0a,
     127,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rviz__EnumProperty[] = {
    "rviz::EnumProperty\0\0property_in_need_of_options\0"
    "requestOptions(EnumProperty*)\0str\0"
    "setString(QString)\0setStringStd(std::string)\0"
    "sortOptions()\0"
};

void rviz::EnumProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EnumProperty *_t = static_cast<EnumProperty *>(_o);
        switch (_id) {
        case 0: _t->requestOptions((*reinterpret_cast< EnumProperty*(*)>(_a[1]))); break;
        case 1: _t->setString((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setStringStd((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 3: _t->sortOptions(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::EnumProperty::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::EnumProperty::staticMetaObject = {
    { &StringProperty::staticMetaObject, qt_meta_stringdata_rviz__EnumProperty,
      qt_meta_data_rviz__EnumProperty, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::EnumProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::EnumProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::EnumProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__EnumProperty))
        return static_cast<void*>(const_cast< EnumProperty*>(this));
    return StringProperty::qt_metacast(_clname);
}

int rviz::EnumProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StringProperty::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void rviz::EnumProperty::requestOptions(EnumProperty * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
