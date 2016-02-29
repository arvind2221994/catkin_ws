/****************************************************************************
** Meta object code from reading C++ file 'visualization_manager.h'
**
** Created: Fri Feb 5 05:35:37 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/visualization_manager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualization_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__VisualizationManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x05,
      40,   27,   27,   27, 0x05,
      64,   56,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
      86,   27,   27,   27, 0x09,
      97,   27,   27,   27, 0x09,
     118,   27,   27,   27, 0x08,
     137,   27,   27,   27, 0x08,
     161,   27,   27,   27, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__VisualizationManager[] = {
    "rviz::VisualizationManager\0\0preUpdate()\0"
    "configChanged()\0message\0statusUpdate(QString)\0"
    "onUpdate()\0onToolChanged(Tool*)\0"
    "updateFixedFrame()\0updateBackgroundColor()\0"
    "updateFps()\0"
};

void rviz::VisualizationManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VisualizationManager *_t = static_cast<VisualizationManager *>(_o);
        switch (_id) {
        case 0: _t->preUpdate(); break;
        case 1: _t->configChanged(); break;
        case 2: _t->statusUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onUpdate(); break;
        case 4: _t->onToolChanged((*reinterpret_cast< Tool*(*)>(_a[1]))); break;
        case 5: _t->updateFixedFrame(); break;
        case 6: _t->updateBackgroundColor(); break;
        case 7: _t->updateFps(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::VisualizationManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::VisualizationManager::staticMetaObject = {
    { &DisplayContext::staticMetaObject, qt_meta_stringdata_rviz__VisualizationManager,
      qt_meta_data_rviz__VisualizationManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::VisualizationManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::VisualizationManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::VisualizationManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__VisualizationManager))
        return static_cast<void*>(const_cast< VisualizationManager*>(this));
    return DisplayContext::qt_metacast(_clname);
}

int rviz::VisualizationManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DisplayContext::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void rviz::VisualizationManager::preUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void rviz::VisualizationManager::configChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void rviz::VisualizationManager::statusUpdate(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
