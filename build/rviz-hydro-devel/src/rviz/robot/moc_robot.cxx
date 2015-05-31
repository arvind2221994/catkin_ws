/****************************************************************************
** Meta object code from reading C++ file 'robot.h'
**
** Created: Tue May 12 17:13:15 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/robot/robot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__Robot[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      36,   12,   12,   12, 0x08,
      56,   12,   12,   12, 0x08,
      83,   12,   12,   12, 0x08,
     107,   12,   12,   12, 0x08,
     134,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__Robot[] = {
    "rviz::Robot\0\0changedLinkTreeStyle()\0"
    "changedExpandTree()\0changedHideSubProperties()\0"
    "changedEnableAllLinks()\0"
    "changedExpandLinkDetails()\0"
    "changedExpandJointDetails()\0"
};

void rviz::Robot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Robot *_t = static_cast<Robot *>(_o);
        switch (_id) {
        case 0: _t->changedLinkTreeStyle(); break;
        case 1: _t->changedExpandTree(); break;
        case 2: _t->changedHideSubProperties(); break;
        case 3: _t->changedEnableAllLinks(); break;
        case 4: _t->changedExpandLinkDetails(); break;
        case 5: _t->changedExpandJointDetails(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::Robot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::Robot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rviz__Robot,
      qt_meta_data_rviz__Robot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::Robot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::Robot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::Robot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__Robot))
        return static_cast<void*>(const_cast< Robot*>(this));
    return QObject::qt_metacast(_clname);
}

int rviz::Robot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
