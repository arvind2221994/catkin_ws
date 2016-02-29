/****************************************************************************
** Meta object code from reading C++ file 'map_display.h'
**
** Created: Fri Feb 5 05:37:12 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/map_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__MapDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   17,   17,   17, 0x09,
      45,   17,   17,   17, 0x09,
      59,   17,   17,   17, 0x09,
      77,   17,   17,   17, 0x09,
      93,   17,   17,   17, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__MapDisplay[] = {
    "rviz::MapDisplay\0\0mapUpdated()\0"
    "updateAlpha()\0updateTopic()\0"
    "updateDrawUnder()\0updatePalette()\0"
    "showMap()\0"
};

void rviz::MapDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MapDisplay *_t = static_cast<MapDisplay *>(_o);
        switch (_id) {
        case 0: _t->mapUpdated(); break;
        case 1: _t->updateAlpha(); break;
        case 2: _t->updateTopic(); break;
        case 3: _t->updateDrawUnder(); break;
        case 4: _t->updatePalette(); break;
        case 5: _t->showMap(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::MapDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::MapDisplay::staticMetaObject = {
    { &Display::staticMetaObject, qt_meta_stringdata_rviz__MapDisplay,
      qt_meta_data_rviz__MapDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::MapDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::MapDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::MapDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__MapDisplay))
        return static_cast<void*>(const_cast< MapDisplay*>(this));
    return Display::qt_metacast(_clname);
}

int rviz::MapDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Display::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void rviz::MapDisplay::mapUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
