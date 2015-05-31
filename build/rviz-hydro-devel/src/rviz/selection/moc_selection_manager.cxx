/****************************************************************************
** Meta object code from reading C++ file 'selection_manager.h'
**
** Created: Tue May 12 17:13:16 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/selection/selection_manager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selection_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__SelectionManager[] = {

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
      24,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__SelectionManager[] = {
    "rviz::SelectionManager\0\0updateProperties()\0"
};

void rviz::SelectionManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SelectionManager *_t = static_cast<SelectionManager *>(_o);
        switch (_id) {
        case 0: _t->updateProperties(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::SelectionManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::SelectionManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rviz__SelectionManager,
      qt_meta_data_rviz__SelectionManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::SelectionManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::SelectionManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::SelectionManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__SelectionManager))
        return static_cast<void*>(const_cast< SelectionManager*>(this));
    if (!strcmp(_clname, "Ogre::MaterialManager::Listener"))
        return static_cast< Ogre::MaterialManager::Listener*>(const_cast< SelectionManager*>(this));
    if (!strcmp(_clname, "Ogre::RenderQueueListener"))
        return static_cast< Ogre::RenderQueueListener*>(const_cast< SelectionManager*>(this));
    return QObject::qt_metacast(_clname);
}

int rviz::SelectionManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
