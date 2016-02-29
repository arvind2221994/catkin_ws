/****************************************************************************
** Meta object code from reading C++ file 'integer_action.h'
**
** Created: Fri Feb 5 05:37:11 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/interactive_markers/integer_action.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'integer_action.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__IntegerAction[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   21,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__IntegerAction[] = {
    "rviz::IntegerAction\0\0id\0triggered(int)\0"
    "emitId()\0"
};

void rviz::IntegerAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IntegerAction *_t = static_cast<IntegerAction *>(_o);
        switch (_id) {
        case 0: _t->triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->emitId(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::IntegerAction::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::IntegerAction::staticMetaObject = {
    { &QAction::staticMetaObject, qt_meta_stringdata_rviz__IntegerAction,
      qt_meta_data_rviz__IntegerAction, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::IntegerAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::IntegerAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::IntegerAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__IntegerAction))
        return static_cast<void*>(const_cast< IntegerAction*>(this));
    return QAction::qt_metacast(_clname);
}

int rviz::IntegerAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void rviz::IntegerAction::triggered(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
