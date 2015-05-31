/****************************************************************************
** Meta object code from reading C++ file 'point_cloud_transformers.h'
**
** Created: Tue May 12 17:16:41 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/point_cloud_transformers.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'point_cloud_transformers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__IntensityPCTransformer[] = {

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
      30,   29,   29,   29, 0x08,
      49,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__IntensityPCTransformer[] = {
    "rviz::IntensityPCTransformer\0\0"
    "updateUseRainbow()\0"
    "updateAutoComputeIntensityBounds()\0"
};

void rviz::IntensityPCTransformer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IntensityPCTransformer *_t = static_cast<IntensityPCTransformer *>(_o);
        switch (_id) {
        case 0: _t->updateUseRainbow(); break;
        case 1: _t->updateAutoComputeIntensityBounds(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::IntensityPCTransformer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::IntensityPCTransformer::staticMetaObject = {
    { &PointCloudTransformer::staticMetaObject, qt_meta_stringdata_rviz__IntensityPCTransformer,
      qt_meta_data_rviz__IntensityPCTransformer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::IntensityPCTransformer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::IntensityPCTransformer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::IntensityPCTransformer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__IntensityPCTransformer))
        return static_cast<void*>(const_cast< IntensityPCTransformer*>(this));
    return PointCloudTransformer::qt_metacast(_clname);
}

int rviz::IntensityPCTransformer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PointCloudTransformer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_rviz__XYZPCTransformer[] = {

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

static const char qt_meta_stringdata_rviz__XYZPCTransformer[] = {
    "rviz::XYZPCTransformer\0"
};

void rviz::XYZPCTransformer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::XYZPCTransformer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::XYZPCTransformer::staticMetaObject = {
    { &PointCloudTransformer::staticMetaObject, qt_meta_stringdata_rviz__XYZPCTransformer,
      qt_meta_data_rviz__XYZPCTransformer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::XYZPCTransformer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::XYZPCTransformer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::XYZPCTransformer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__XYZPCTransformer))
        return static_cast<void*>(const_cast< XYZPCTransformer*>(this));
    return PointCloudTransformer::qt_metacast(_clname);
}

int rviz::XYZPCTransformer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PointCloudTransformer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_rviz__RGB8PCTransformer[] = {

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

static const char qt_meta_stringdata_rviz__RGB8PCTransformer[] = {
    "rviz::RGB8PCTransformer\0"
};

void rviz::RGB8PCTransformer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::RGB8PCTransformer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::RGB8PCTransformer::staticMetaObject = {
    { &PointCloudTransformer::staticMetaObject, qt_meta_stringdata_rviz__RGB8PCTransformer,
      qt_meta_data_rviz__RGB8PCTransformer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::RGB8PCTransformer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::RGB8PCTransformer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::RGB8PCTransformer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__RGB8PCTransformer))
        return static_cast<void*>(const_cast< RGB8PCTransformer*>(this));
    return PointCloudTransformer::qt_metacast(_clname);
}

int rviz::RGB8PCTransformer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PointCloudTransformer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_rviz__RGBF32PCTransformer[] = {

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

static const char qt_meta_stringdata_rviz__RGBF32PCTransformer[] = {
    "rviz::RGBF32PCTransformer\0"
};

void rviz::RGBF32PCTransformer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::RGBF32PCTransformer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::RGBF32PCTransformer::staticMetaObject = {
    { &PointCloudTransformer::staticMetaObject, qt_meta_stringdata_rviz__RGBF32PCTransformer,
      qt_meta_data_rviz__RGBF32PCTransformer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::RGBF32PCTransformer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::RGBF32PCTransformer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::RGBF32PCTransformer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__RGBF32PCTransformer))
        return static_cast<void*>(const_cast< RGBF32PCTransformer*>(this));
    return PointCloudTransformer::qt_metacast(_clname);
}

int rviz::RGBF32PCTransformer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PointCloudTransformer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_rviz__FlatColorPCTransformer[] = {

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

static const char qt_meta_stringdata_rviz__FlatColorPCTransformer[] = {
    "rviz::FlatColorPCTransformer\0"
};

void rviz::FlatColorPCTransformer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::FlatColorPCTransformer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::FlatColorPCTransformer::staticMetaObject = {
    { &PointCloudTransformer::staticMetaObject, qt_meta_stringdata_rviz__FlatColorPCTransformer,
      qt_meta_data_rviz__FlatColorPCTransformer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::FlatColorPCTransformer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::FlatColorPCTransformer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::FlatColorPCTransformer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__FlatColorPCTransformer))
        return static_cast<void*>(const_cast< FlatColorPCTransformer*>(this));
    return PointCloudTransformer::qt_metacast(_clname);
}

int rviz::FlatColorPCTransformer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PointCloudTransformer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_rviz__AxisColorPCTransformer[] = {

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
      30,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__AxisColorPCTransformer[] = {
    "rviz::AxisColorPCTransformer\0\0"
    "updateAutoComputeBounds()\0"
};

void rviz::AxisColorPCTransformer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AxisColorPCTransformer *_t = static_cast<AxisColorPCTransformer *>(_o);
        switch (_id) {
        case 0: _t->updateAutoComputeBounds(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::AxisColorPCTransformer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::AxisColorPCTransformer::staticMetaObject = {
    { &PointCloudTransformer::staticMetaObject, qt_meta_stringdata_rviz__AxisColorPCTransformer,
      qt_meta_data_rviz__AxisColorPCTransformer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::AxisColorPCTransformer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::AxisColorPCTransformer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::AxisColorPCTransformer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__AxisColorPCTransformer))
        return static_cast<void*>(const_cast< AxisColorPCTransformer*>(this));
    return PointCloudTransformer::qt_metacast(_clname);
}

int rviz::AxisColorPCTransformer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PointCloudTransformer::qt_metacall(_c, _id, _a);
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
