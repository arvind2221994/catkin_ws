/****************************************************************************
** Meta object code from reading C++ file 'display_group.h'
**
** Created: Tue May 12 17:13:09 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/display_group.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display_group.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__DisplayGroup[] = {

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
      28,   20,   19,   19, 0x05,
      57,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      88,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rviz__DisplayGroup[] = {
    "rviz::DisplayGroup\0\0display\0"
    "displayAdded(rviz::Display*)\0"
    "displayRemoved(rviz::Display*)\0"
    "onEnableChanged()\0"
};

void rviz::DisplayGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DisplayGroup *_t = static_cast<DisplayGroup *>(_o);
        switch (_id) {
        case 0: _t->displayAdded((*reinterpret_cast< rviz::Display*(*)>(_a[1]))); break;
        case 1: _t->displayRemoved((*reinterpret_cast< rviz::Display*(*)>(_a[1]))); break;
        case 2: _t->onEnableChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::DisplayGroup::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::DisplayGroup::staticMetaObject = {
    { &Display::staticMetaObject, qt_meta_stringdata_rviz__DisplayGroup,
      qt_meta_data_rviz__DisplayGroup, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::DisplayGroup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::DisplayGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::DisplayGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__DisplayGroup))
        return static_cast<void*>(const_cast< DisplayGroup*>(this));
    return Display::qt_metacast(_clname);
}

int rviz::DisplayGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Display::qt_metacall(_c, _id, _a);
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
void rviz::DisplayGroup::displayAdded(rviz::Display * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rviz::DisplayGroup::displayRemoved(rviz::Display * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
