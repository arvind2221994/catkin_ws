/****************************************************************************
** Meta object code from reading C++ file 'camera_display.h'
**
** Created: Tue May 12 17:16:36 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/camera_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__CameraDisplay[] = {

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
      21,   20,   20,   20, 0x08,
      35,   20,   20,   20, 0x08,
      49,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__CameraDisplay[] = {
    "rviz::CameraDisplay\0\0forceRender()\0"
    "updateAlpha()\0updateQueueSize()\0"
};

void rviz::CameraDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CameraDisplay *_t = static_cast<CameraDisplay *>(_o);
        switch (_id) {
        case 0: _t->forceRender(); break;
        case 1: _t->updateAlpha(); break;
        case 2: _t->updateQueueSize(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::CameraDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::CameraDisplay::staticMetaObject = {
    { &ImageDisplayBase::staticMetaObject, qt_meta_stringdata_rviz__CameraDisplay,
      qt_meta_data_rviz__CameraDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::CameraDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::CameraDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::CameraDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__CameraDisplay))
        return static_cast<void*>(const_cast< CameraDisplay*>(this));
    if (!strcmp(_clname, "Ogre::RenderTargetListener"))
        return static_cast< Ogre::RenderTargetListener*>(const_cast< CameraDisplay*>(this));
    return ImageDisplayBase::qt_metacast(_clname);
}

int rviz::CameraDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ImageDisplayBase::qt_metacall(_c, _id, _a);
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
