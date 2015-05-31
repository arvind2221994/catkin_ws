/****************************************************************************
** Meta object code from reading C++ file 'robot_model_display.h'
**
** Created: Tue May 12 17:16:43 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/robot_model_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robot_model_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__RobotModelDisplay[] = {

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
      25,   24,   24,   24, 0x08,
      47,   24,   24,   24, 0x08,
      72,   24,   24,   24, 0x08,
      89,   24,   24,   24, 0x08,
     103,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__RobotModelDisplay[] = {
    "rviz::RobotModelDisplay\0\0updateVisualVisible()\0"
    "updateCollisionVisible()\0updateTfPrefix()\0"
    "updateAlpha()\0updateRobotDescription()\0"
};

void rviz::RobotModelDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RobotModelDisplay *_t = static_cast<RobotModelDisplay *>(_o);
        switch (_id) {
        case 0: _t->updateVisualVisible(); break;
        case 1: _t->updateCollisionVisible(); break;
        case 2: _t->updateTfPrefix(); break;
        case 3: _t->updateAlpha(); break;
        case 4: _t->updateRobotDescription(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::RobotModelDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::RobotModelDisplay::staticMetaObject = {
    { &Display::staticMetaObject, qt_meta_stringdata_rviz__RobotModelDisplay,
      qt_meta_data_rviz__RobotModelDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::RobotModelDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::RobotModelDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::RobotModelDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__RobotModelDisplay))
        return static_cast<void*>(const_cast< RobotModelDisplay*>(this));
    return Display::qt_metacast(_clname);
}

int rviz::RobotModelDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Display::qt_metacall(_c, _id, _a);
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
