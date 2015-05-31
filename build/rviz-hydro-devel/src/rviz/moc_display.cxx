/****************************************************************************
** Meta object code from reading C++ file 'display.h'
**
** Created: Tue May 12 17:13:09 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__Display[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,   65,   14,   14, 0x0a,
      90,   14,   14,   14, 0x0a,
     109,  104,   14,   14, 0x0a,
     124,   14,   14,   14, 0x0a,
     158,  142,   14,   14, 0x08,
     202,  197,   14,   14, 0x08,
     232,   14,   14,   14, 0x08,
     264,  256,   14,   14, 0x08,
     302,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__Display[] = {
    "rviz::Display\0\0display,time\0"
    "timeSignal(rviz::Display*,ros::Time)\0"
    "enabled\0setEnabled(bool)\0queueRender()\0"
    "icon\0setIcon(QIcon)\0onEnableChanged()\0"
    "level,name,text\0setStatusInternal(int,QString,QString)\0"
    "name\0deleteStatusInternal(QString)\0"
    "clearStatusesInternal()\0visible\0"
    "associatedPanelVisibilityChange(bool)\0"
    "disable()\0"
};

void rviz::Display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Display *_t = static_cast<Display *>(_o);
        switch (_id) {
        case 0: _t->timeSignal((*reinterpret_cast< rviz::Display*(*)>(_a[1])),(*reinterpret_cast< ros::Time(*)>(_a[2]))); break;
        case 1: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->queueRender(); break;
        case 3: _t->setIcon((*reinterpret_cast< const QIcon(*)>(_a[1]))); break;
        case 4: _t->onEnableChanged(); break;
        case 5: _t->setStatusInternal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->deleteStatusInternal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->clearStatusesInternal(); break;
        case 8: _t->associatedPanelVisibilityChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->disable(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::Display::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::Display::staticMetaObject = {
    { &BoolProperty::staticMetaObject, qt_meta_stringdata_rviz__Display,
      qt_meta_data_rviz__Display, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::Display::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::Display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::Display::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__Display))
        return static_cast<void*>(const_cast< Display*>(this));
    return BoolProperty::qt_metacast(_clname);
}

int rviz::Display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BoolProperty::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void rviz::Display::timeSignal(rviz::Display * _t1, ros::Time _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
