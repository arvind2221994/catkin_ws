/****************************************************************************
** Meta object code from reading C++ file 'interactive_marker.h'
**
** Created: Fri Feb 5 05:37:11 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/interactive_markers/interactive_marker.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interactive_marker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__InteractiveMarker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   25,   24,   24, 0x05,
     111,   95,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     184,  171,   24,   24, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__InteractiveMarker[] = {
    "rviz::InteractiveMarker\0\0feedback\0"
    "userFeedback(visualization_msgs::InteractiveMarkerFeedback&)\0"
    "level,name,text\0"
    "statusUpdate(StatusProperty::Level,std::string,std::string)\0"
    "menu_item_id\0handleMenuSelect(int)\0"
};

void rviz::InteractiveMarker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InteractiveMarker *_t = static_cast<InteractiveMarker *>(_o);
        switch (_id) {
        case 0: _t->userFeedback((*reinterpret_cast< visualization_msgs::InteractiveMarkerFeedback(*)>(_a[1]))); break;
        case 1: _t->statusUpdate((*reinterpret_cast< StatusProperty::Level(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3]))); break;
        case 2: _t->handleMenuSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::InteractiveMarker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::InteractiveMarker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rviz__InteractiveMarker,
      qt_meta_data_rviz__InteractiveMarker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::InteractiveMarker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::InteractiveMarker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::InteractiveMarker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__InteractiveMarker))
        return static_cast<void*>(const_cast< InteractiveMarker*>(this));
    return QObject::qt_metacast(_clname);
}

int rviz::InteractiveMarker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void rviz::InteractiveMarker::userFeedback(visualization_msgs::InteractiveMarkerFeedback & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rviz::InteractiveMarker::statusUpdate(StatusProperty::Level _t1, const std::string & _t2, const std::string & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
