/****************************************************************************
** Meta object code from reading C++ file 'grid_display.h'
**
** Created: Fri Feb 5 05:37:10 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/grid_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grid_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__GridDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      37,   18,   18,   18, 0x08,
      54,   18,   18,   18, 0x08,
      68,   18,   18,   18, 0x08,
      83,   18,   18,   18, 0x08,
     101,   18,   18,   18, 0x08,
     116,   18,   18,   18, 0x08,
     130,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__GridDisplay[] = {
    "rviz::GridDisplay\0\0updateCellCount()\0"
    "updateCellSize()\0updateColor()\0"
    "updateHeight()\0updateLineWidth()\0"
    "updateOffset()\0updatePlane()\0updateStyle()\0"
};

void rviz::GridDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GridDisplay *_t = static_cast<GridDisplay *>(_o);
        switch (_id) {
        case 0: _t->updateCellCount(); break;
        case 1: _t->updateCellSize(); break;
        case 2: _t->updateColor(); break;
        case 3: _t->updateHeight(); break;
        case 4: _t->updateLineWidth(); break;
        case 5: _t->updateOffset(); break;
        case 6: _t->updatePlane(); break;
        case 7: _t->updateStyle(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::GridDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::GridDisplay::staticMetaObject = {
    { &Display::staticMetaObject, qt_meta_stringdata_rviz__GridDisplay,
      qt_meta_data_rviz__GridDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::GridDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::GridDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::GridDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__GridDisplay))
        return static_cast<void*>(const_cast< GridDisplay*>(this));
    return Display::qt_metacast(_clname);
}

int rviz::GridDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Display::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
