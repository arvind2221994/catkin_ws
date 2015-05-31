/****************************************************************************
** Meta object code from reading C++ file 'depth_cloud_display.h'
**
** Created: Tue May 12 17:16:36 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/depth_cloud_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'depth_cloud_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__RosFilteredTopicProperty[] = {

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
      32,   31,   31,   31, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__RosFilteredTopicProperty[] = {
    "rviz::RosFilteredTopicProperty\0\0"
    "fillTopicList()\0"
};

void rviz::RosFilteredTopicProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RosFilteredTopicProperty *_t = static_cast<RosFilteredTopicProperty *>(_o);
        switch (_id) {
        case 0: _t->fillTopicList(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::RosFilteredTopicProperty::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::RosFilteredTopicProperty::staticMetaObject = {
    { &RosTopicProperty::staticMetaObject, qt_meta_stringdata_rviz__RosFilteredTopicProperty,
      qt_meta_data_rviz__RosFilteredTopicProperty, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::RosFilteredTopicProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::RosFilteredTopicProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::RosFilteredTopicProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__RosFilteredTopicProperty))
        return static_cast<void*>(const_cast< RosFilteredTopicProperty*>(this));
    return RosTopicProperty::qt_metacast(_clname);
}

int rviz::RosFilteredTopicProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RosTopicProperty::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_rviz__DepthCloudDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x09,
      52,   43,   24,   24, 0x09,
      91,   24,   24,   24, 0x09,
     105,   24,   24,   24, 0x09,
     125,   24,   24,   24, 0x09,
     145,   24,   24,   24, 0x09,
     168,   24,   24,   24, 0x09,
     201,   24,   24,   24, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__DepthCloudDisplay[] = {
    "rviz::DepthCloudDisplay\0\0updateQueueSize()\0"
    "property\0fillTransportOptionList(EnumProperty*)\0"
    "updateTopic()\0updateTopicFilter()\0"
    "updateUseAutoSize()\0updateAutoSizeFactor()\0"
    "updateUseOcclusionCompensation()\0"
    "updateOcclusionTimeOut()\0"
};

void rviz::DepthCloudDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DepthCloudDisplay *_t = static_cast<DepthCloudDisplay *>(_o);
        switch (_id) {
        case 0: _t->updateQueueSize(); break;
        case 1: _t->fillTransportOptionList((*reinterpret_cast< EnumProperty*(*)>(_a[1]))); break;
        case 2: _t->updateTopic(); break;
        case 3: _t->updateTopicFilter(); break;
        case 4: _t->updateUseAutoSize(); break;
        case 5: _t->updateAutoSizeFactor(); break;
        case 6: _t->updateUseOcclusionCompensation(); break;
        case 7: _t->updateOcclusionTimeOut(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::DepthCloudDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::DepthCloudDisplay::staticMetaObject = {
    { &rviz::Display::staticMetaObject, qt_meta_stringdata_rviz__DepthCloudDisplay,
      qt_meta_data_rviz__DepthCloudDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::DepthCloudDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::DepthCloudDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::DepthCloudDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__DepthCloudDisplay))
        return static_cast<void*>(const_cast< DepthCloudDisplay*>(this));
    typedef rviz::Display QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int rviz::DepthCloudDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef rviz::Display QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
