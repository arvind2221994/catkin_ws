/****************************************************************************
** Meta object code from reading C++ file 'point_cloud2_display.h'
**
** Created: Tue May 12 17:16:42 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/point_cloud2_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'point_cloud2_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__PointCloud2Display[] = {

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
      26,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__PointCloud2Display[] = {
    "rviz::PointCloud2Display\0\0updateQueueSize()\0"
};

void rviz::PointCloud2Display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PointCloud2Display *_t = static_cast<PointCloud2Display *>(_o);
        switch (_id) {
        case 0: _t->updateQueueSize(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::PointCloud2Display::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::PointCloud2Display::staticMetaObject = {
    { &MessageFilterDisplay<sensor_msgs::PointCloud2>::staticMetaObject, qt_meta_stringdata_rviz__PointCloud2Display,
      qt_meta_data_rviz__PointCloud2Display, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::PointCloud2Display::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::PointCloud2Display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::PointCloud2Display::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__PointCloud2Display))
        return static_cast<void*>(const_cast< PointCloud2Display*>(this));
    typedef MessageFilterDisplay<sensor_msgs::PointCloud2> QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int rviz::PointCloud2Display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef MessageFilterDisplay<sensor_msgs::PointCloud2> QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
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
