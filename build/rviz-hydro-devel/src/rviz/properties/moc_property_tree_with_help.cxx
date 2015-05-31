/****************************************************************************
** Meta object code from reading C++ file 'property_tree_with_help.h'
**
** Created: Tue May 12 17:13:13 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/property_tree_with_help.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'property_tree_with_help.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__PropertyTreeWithHelp[] = {

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
      37,   28,   27,   27, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__PropertyTreeWithHelp[] = {
    "rviz::PropertyTreeWithHelp\0\0property\0"
    "showHelpForProperty(const Property*)\0"
};

void rviz::PropertyTreeWithHelp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PropertyTreeWithHelp *_t = static_cast<PropertyTreeWithHelp *>(_o);
        switch (_id) {
        case 0: _t->showHelpForProperty((*reinterpret_cast< const Property*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::PropertyTreeWithHelp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::PropertyTreeWithHelp::staticMetaObject = {
    { &QSplitter::staticMetaObject, qt_meta_stringdata_rviz__PropertyTreeWithHelp,
      qt_meta_data_rviz__PropertyTreeWithHelp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::PropertyTreeWithHelp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::PropertyTreeWithHelp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::PropertyTreeWithHelp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__PropertyTreeWithHelp))
        return static_cast<void*>(const_cast< PropertyTreeWithHelp*>(this));
    return QSplitter::qt_metacast(_clname);
}

int rviz::PropertyTreeWithHelp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSplitter::qt_metacall(_c, _id, _a);
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
