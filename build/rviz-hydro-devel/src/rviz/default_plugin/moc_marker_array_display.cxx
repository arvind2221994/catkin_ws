/****************************************************************************
** Meta object code from reading C++ file 'marker_array_display.h'
**
** Created: Fri Feb 5 05:37:12 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/marker_array_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'marker_array_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__MarkerArrayDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_rviz__MarkerArrayDisplay[] = {
    "rviz::MarkerArrayDisplay\0"
};

void rviz::MarkerArrayDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::MarkerArrayDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::MarkerArrayDisplay::staticMetaObject = {
    { &MarkerDisplay::staticMetaObject, qt_meta_stringdata_rviz__MarkerArrayDisplay,
      qt_meta_data_rviz__MarkerArrayDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::MarkerArrayDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::MarkerArrayDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::MarkerArrayDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__MarkerArrayDisplay))
        return static_cast<void*>(const_cast< MarkerArrayDisplay*>(this));
    return MarkerDisplay::qt_metacast(_clname);
}

int rviz::MarkerArrayDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MarkerDisplay::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
