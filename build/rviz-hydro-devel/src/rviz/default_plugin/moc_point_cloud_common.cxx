/****************************************************************************
** Meta object code from reading C++ file 'point_cloud_common.h'
**
** Created: Tue May 12 17:16:40 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/point_cloud_common.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'point_cloud_common.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__PointCloudCommon[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x0a,
      43,   23,   23,   23, 0x08,
      62,   23,   23,   23, 0x08,
      76,   23,   23,   23, 0x08,
      98,   23,   23,   23, 0x08,
     112,   23,   23,   23, 0x08,
     135,   23,   23,   23, 0x08,
     165,  160,   23,   23, 0x08,
     205,  160,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__PointCloudCommon[] = {
    "rviz::PointCloudCommon\0\0causeRetransform()\0"
    "updateSelectable()\0updateStyle()\0"
    "updateBillboardSize()\0updateAlpha()\0"
    "updateXyzTransformer()\0updateColorTransformer()\0"
    "prop\0setXyzTransformerOptions(EnumProperty*)\0"
    "setColorTransformerOptions(EnumProperty*)\0"
};

void rviz::PointCloudCommon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PointCloudCommon *_t = static_cast<PointCloudCommon *>(_o);
        switch (_id) {
        case 0: _t->causeRetransform(); break;
        case 1: _t->updateSelectable(); break;
        case 2: _t->updateStyle(); break;
        case 3: _t->updateBillboardSize(); break;
        case 4: _t->updateAlpha(); break;
        case 5: _t->updateXyzTransformer(); break;
        case 6: _t->updateColorTransformer(); break;
        case 7: _t->setXyzTransformerOptions((*reinterpret_cast< EnumProperty*(*)>(_a[1]))); break;
        case 8: _t->setColorTransformerOptions((*reinterpret_cast< EnumProperty*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::PointCloudCommon::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::PointCloudCommon::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rviz__PointCloudCommon,
      qt_meta_data_rviz__PointCloudCommon, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::PointCloudCommon::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::PointCloudCommon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::PointCloudCommon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__PointCloudCommon))
        return static_cast<void*>(const_cast< PointCloudCommon*>(this));
    return QObject::qt_metacast(_clname);
}

int rviz::PointCloudCommon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
