/****************************************************************************
** Meta object code from reading C++ file 'time_panel.h'
**
** Created: Tue May 12 17:13:16 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/time_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'time_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__TimePanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   17,   16,   16, 0x09,
      50,   44,   16,   16, 0x09,
      72,   44,   16,   16, 0x09,
      96,   17,   16,   16, 0x09,
     122,   16,   16,   16, 0x09,
     139,  131,   16,   16, 0x09,
     170,  131,   16,   16, 0x09,
     216,  203,   16,   16, 0x09,
     262,  255,   16,   16, 0x09,
     275,  255,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__TimePanel[] = {
    "rviz::TimePanel\0\0checked\0pauseToggled(bool)\0"
    "index\0syncModeSelected(int)\0"
    "syncSourceSelected(int)\0"
    "experimentalToggled(bool)\0update()\0"
    "display\0onDisplayAdded(rviz::Display*)\0"
    "onDisplayRemoved(rviz::Display*)\0"
    "display,time\0onTimeSignal(rviz::Display*,ros::Time)\0"
    "config\0load(Config)\0save(Config)\0"
};

void rviz::TimePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TimePanel *_t = static_cast<TimePanel *>(_o);
        switch (_id) {
        case 0: _t->pauseToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->syncModeSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->syncSourceSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->experimentalToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->update(); break;
        case 5: _t->onDisplayAdded((*reinterpret_cast< rviz::Display*(*)>(_a[1]))); break;
        case 6: _t->onDisplayRemoved((*reinterpret_cast< rviz::Display*(*)>(_a[1]))); break;
        case 7: _t->onTimeSignal((*reinterpret_cast< rviz::Display*(*)>(_a[1])),(*reinterpret_cast< ros::Time(*)>(_a[2]))); break;
        case 8: _t->load((*reinterpret_cast< const Config(*)>(_a[1]))); break;
        case 9: _t->save((*reinterpret_cast< Config(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::TimePanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::TimePanel::staticMetaObject = {
    { &Panel::staticMetaObject, qt_meta_stringdata_rviz__TimePanel,
      qt_meta_data_rviz__TimePanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::TimePanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::TimePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::TimePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__TimePanel))
        return static_cast<void*>(const_cast< TimePanel*>(this));
    return Panel::qt_metacast(_clname);
}

int rviz::TimePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Panel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
