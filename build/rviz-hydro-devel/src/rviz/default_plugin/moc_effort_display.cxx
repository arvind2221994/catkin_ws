/****************************************************************************
** Meta object code from reading C++ file 'effort_display.h'
**
** Created: Tue May 12 17:16:37 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/effort_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'effort_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__JointInfo[] = {

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
      17,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rviz__JointInfo[] = {
    "rviz::JointInfo\0\0updateVisibility()\0"
};

void rviz::JointInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        JointInfo *_t = static_cast<JointInfo *>(_o);
        switch (_id) {
        case 0: _t->updateVisibility(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::JointInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::JointInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rviz__JointInfo,
      qt_meta_data_rviz__JointInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::JointInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::JointInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::JointInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__JointInfo))
        return static_cast<void*>(const_cast< JointInfo*>(this));
    return QObject::qt_metacast(_clname);
}

int rviz::JointInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_rviz__EffortDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      43,   20,   20,   20, 0x08,
      65,   20,   20,   20, 0x08,
     107,  101,   90,   20, 0x08,
     133,  101,   90,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__EffortDisplay[] = {
    "rviz::EffortDisplay\0\0updateColorAndAlpha()\0"
    "updateHistoryLength()\0updateRobotDescription()\0"
    "JointInfo*\0joint\0getJointInfo(std::string)\0"
    "createJoint(std::string)\0"
};

void rviz::EffortDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EffortDisplay *_t = static_cast<EffortDisplay *>(_o);
        switch (_id) {
        case 0: _t->updateColorAndAlpha(); break;
        case 1: _t->updateHistoryLength(); break;
        case 2: _t->updateRobotDescription(); break;
        case 3: { JointInfo* _r = _t->getJointInfo((*reinterpret_cast< const std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< JointInfo**>(_a[0]) = _r; }  break;
        case 4: { JointInfo* _r = _t->createJoint((*reinterpret_cast< const std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< JointInfo**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::EffortDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::EffortDisplay::staticMetaObject = {
    { &rviz::MessageFilterJointStateDisplay::staticMetaObject, qt_meta_stringdata_rviz__EffortDisplay,
      qt_meta_data_rviz__EffortDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::EffortDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::EffortDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::EffortDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__EffortDisplay))
        return static_cast<void*>(const_cast< EffortDisplay*>(this));
    typedef rviz::MessageFilterJointStateDisplay QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int rviz::EffortDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef rviz::MessageFilterJointStateDisplay QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
