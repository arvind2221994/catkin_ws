/****************************************************************************
** Meta object code from reading C++ file 'ros_topic_property.h'
**
** Created: Tue May 12 17:13:14 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/ros_topic_property.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ros_topic_property.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__RosTopicProperty[] = {

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
      24,   23,   23,   23, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__RosTopicProperty[] = {
    "rviz::RosTopicProperty\0\0fillTopicList()\0"
};

void rviz::RosTopicProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RosTopicProperty *_t = static_cast<RosTopicProperty *>(_o);
        switch (_id) {
        case 0: _t->fillTopicList(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::RosTopicProperty::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::RosTopicProperty::staticMetaObject = {
    { &EditableEnumProperty::staticMetaObject, qt_meta_stringdata_rviz__RosTopicProperty,
      qt_meta_data_rviz__RosTopicProperty, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::RosTopicProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::RosTopicProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::RosTopicProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__RosTopicProperty))
        return static_cast<void*>(const_cast< RosTopicProperty*>(this));
    return EditableEnumProperty::qt_metacast(_clname);
}

int rviz::RosTopicProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EditableEnumProperty::qt_metacall(_c, _id, _a);
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
