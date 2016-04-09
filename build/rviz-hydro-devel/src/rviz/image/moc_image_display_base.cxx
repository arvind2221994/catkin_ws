/****************************************************************************
** Meta object code from reading C++ file 'image_display_base.h'
**
** Created: Fri Feb 5 05:35:35 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/image/image_display_base.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'image_display_base.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__ImageDisplayBase[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x09,
      38,   23,   23,   23, 0x09,
      65,   56,   23,   23, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__ImageDisplayBase[] = {
    "rviz::ImageDisplayBase\0\0updateTopic()\0"
    "updateQueueSize()\0property\0"
    "fillTransportOptionList(EnumProperty*)\0"
};

void rviz::ImageDisplayBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageDisplayBase *_t = static_cast<ImageDisplayBase *>(_o);
        switch (_id) {
        case 0: _t->updateTopic(); break;
        case 1: _t->updateQueueSize(); break;
        case 2: _t->fillTransportOptionList((*reinterpret_cast< EnumProperty*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::ImageDisplayBase::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::ImageDisplayBase::staticMetaObject = {
    { &Display::staticMetaObject, qt_meta_stringdata_rviz__ImageDisplayBase,
      qt_meta_data_rviz__ImageDisplayBase, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::ImageDisplayBase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::ImageDisplayBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::ImageDisplayBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__ImageDisplayBase))
        return static_cast<void*>(const_cast< ImageDisplayBase*>(this));
    return Display::qt_metacast(_clname);
}

int rviz::ImageDisplayBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
