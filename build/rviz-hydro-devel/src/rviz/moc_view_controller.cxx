/****************************************************************************
** Meta object code from reading C++ file 'view_controller.h'
**
** Created: Fri Feb 5 05:35:37 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/view_controller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__ViewController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   21,   21,   21, 0x08,
      63,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__ViewController[] = {
    "rviz::ViewController\0\0configChanged()\0"
    "updateNearClipDistance()\0"
    "updateStereoProperties()\0"
};

void rviz::ViewController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewController *_t = static_cast<ViewController *>(_o);
        switch (_id) {
        case 0: _t->configChanged(); break;
        case 1: _t->updateNearClipDistance(); break;
        case 2: _t->updateStereoProperties(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::ViewController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::ViewController::staticMetaObject = {
    { &Property::staticMetaObject, qt_meta_stringdata_rviz__ViewController,
      qt_meta_data_rviz__ViewController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::ViewController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::ViewController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::ViewController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__ViewController))
        return static_cast<void*>(const_cast< ViewController*>(this));
    return Property::qt_metacast(_clname);
}

int rviz::ViewController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Property::qt_metacall(_c, _id, _a);
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
void rviz::ViewController::configChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
