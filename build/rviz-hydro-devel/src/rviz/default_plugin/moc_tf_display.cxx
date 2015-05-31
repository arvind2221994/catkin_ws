/****************************************************************************
** Meta object code from reading C++ file 'tf_display.h'
**
** Created: Tue May 12 17:16:44 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/tf_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tf_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__TFDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      34,   16,   16,   16, 0x08,
      53,   16,   16,   16, 0x08,
      71,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__TFDisplay[] = {
    "rviz::TFDisplay\0\0updateShowAxes()\0"
    "updateShowArrows()\0updateShowNames()\0"
    "allEnabledChanged()\0"
};

void rviz::TFDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TFDisplay *_t = static_cast<TFDisplay *>(_o);
        switch (_id) {
        case 0: _t->updateShowAxes(); break;
        case 1: _t->updateShowArrows(); break;
        case 2: _t->updateShowNames(); break;
        case 3: _t->allEnabledChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::TFDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::TFDisplay::staticMetaObject = {
    { &Display::staticMetaObject, qt_meta_stringdata_rviz__TFDisplay,
      qt_meta_data_rviz__TFDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::TFDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::TFDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::TFDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__TFDisplay))
        return static_cast<void*>(const_cast< TFDisplay*>(this));
    return Display::qt_metacast(_clname);
}

int rviz::TFDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Display::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_rviz__FrameInfo[] = {

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
      17,   16,   16,   16, 0x0a,
      45,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rviz__FrameInfo[] = {
    "rviz::FrameInfo\0\0updateVisibilityFromFrame()\0"
    "updateVisibilityFromSelection()\0"
};

void rviz::FrameInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FrameInfo *_t = static_cast<FrameInfo *>(_o);
        switch (_id) {
        case 0: _t->updateVisibilityFromFrame(); break;
        case 1: _t->updateVisibilityFromSelection(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::FrameInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::FrameInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rviz__FrameInfo,
      qt_meta_data_rviz__FrameInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::FrameInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::FrameInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::FrameInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__FrameInfo))
        return static_cast<void*>(const_cast< FrameInfo*>(this));
    return QObject::qt_metacast(_clname);
}

int rviz::FrameInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
