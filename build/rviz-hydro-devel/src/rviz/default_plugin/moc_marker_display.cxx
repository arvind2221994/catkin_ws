/****************************************************************************
** Meta object code from reading C++ file 'marker_display.h'
**
** Created: Tue May 12 17:16:39 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/marker_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'marker_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__MarkerDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      39,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__MarkerDisplay[] = {
    "rviz::MarkerDisplay\0\0updateQueueSize()\0"
    "updateTopic()\0"
};

void rviz::MarkerDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MarkerDisplay *_t = static_cast<MarkerDisplay *>(_o);
        switch (_id) {
        case 0: _t->updateQueueSize(); break;
        case 1: _t->updateTopic(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::MarkerDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::MarkerDisplay::staticMetaObject = {
    { &Display::staticMetaObject, qt_meta_stringdata_rviz__MarkerDisplay,
      qt_meta_data_rviz__MarkerDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::MarkerDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::MarkerDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::MarkerDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__MarkerDisplay))
        return static_cast<void*>(const_cast< MarkerDisplay*>(this));
    return Display::qt_metacast(_clname);
}

int rviz::MarkerDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Display::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_rviz__MarkerNamespace[] = {

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
      23,   22,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rviz__MarkerNamespace[] = {
    "rviz::MarkerNamespace\0\0onEnableChanged()\0"
};

void rviz::MarkerNamespace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MarkerNamespace *_t = static_cast<MarkerNamespace *>(_o);
        switch (_id) {
        case 0: _t->onEnableChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::MarkerNamespace::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::MarkerNamespace::staticMetaObject = {
    { &BoolProperty::staticMetaObject, qt_meta_stringdata_rviz__MarkerNamespace,
      qt_meta_data_rviz__MarkerNamespace, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::MarkerNamespace::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::MarkerNamespace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::MarkerNamespace::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__MarkerNamespace))
        return static_cast<void*>(const_cast< MarkerNamespace*>(this));
    return BoolProperty::qt_metacast(_clname);
}

int rviz::MarkerNamespace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BoolProperty::qt_metacall(_c, _id, _a);
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
