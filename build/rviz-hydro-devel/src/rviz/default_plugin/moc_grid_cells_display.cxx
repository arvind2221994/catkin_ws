/****************************************************************************
** Meta object code from reading C++ file 'grid_cells_display.h'
**
** Created: Fri Feb 5 05:37:10 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/grid_cells_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grid_cells_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__GridCellsDisplay[] = {

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
      24,   23,   23,   23, 0x08,
      38,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__GridCellsDisplay[] = {
    "rviz::GridCellsDisplay\0\0updateAlpha()\0"
    "updateTopic()\0"
};

void rviz::GridCellsDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GridCellsDisplay *_t = static_cast<GridCellsDisplay *>(_o);
        switch (_id) {
        case 0: _t->updateAlpha(); break;
        case 1: _t->updateTopic(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::GridCellsDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::GridCellsDisplay::staticMetaObject = {
    { &Display::staticMetaObject, qt_meta_stringdata_rviz__GridCellsDisplay,
      qt_meta_data_rviz__GridCellsDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::GridCellsDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::GridCellsDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::GridCellsDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__GridCellsDisplay))
        return static_cast<void*>(const_cast< GridCellsDisplay*>(this));
    return Display::qt_metacast(_clname);
}

int rviz::GridCellsDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
