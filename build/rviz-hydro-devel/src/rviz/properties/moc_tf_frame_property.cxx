/****************************************************************************
** Meta object code from reading C++ file 'tf_frame_property.h'
**
** Created: Fri Feb 5 05:35:36 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/tf_frame_property.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tf_frame_property.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__TfFrameProperty[] = {

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
      23,   22,   22,   22, 0x08,
      39,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__TfFrameProperty[] = {
    "rviz::TfFrameProperty\0\0fillFrameList()\0"
    "handleFixedFrameChange()\0"
};

void rviz::TfFrameProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TfFrameProperty *_t = static_cast<TfFrameProperty *>(_o);
        switch (_id) {
        case 0: _t->fillFrameList(); break;
        case 1: _t->handleFixedFrameChange(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::TfFrameProperty::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::TfFrameProperty::staticMetaObject = {
    { &EditableEnumProperty::staticMetaObject, qt_meta_stringdata_rviz__TfFrameProperty,
      qt_meta_data_rviz__TfFrameProperty, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::TfFrameProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::TfFrameProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::TfFrameProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__TfFrameProperty))
        return static_cast<void*>(const_cast< TfFrameProperty*>(this));
    return EditableEnumProperty::qt_metacast(_clname);
}

int rviz::TfFrameProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EditableEnumProperty::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
