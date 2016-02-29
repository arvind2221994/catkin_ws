/****************************************************************************
** Meta object code from reading C++ file 'render_panel.h'
**
** Created: Fri Feb 5 05:35:37 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/render_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'render_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__RenderPanel[] = {

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
      19,   18,   18,   18, 0x08,
      40,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__RenderPanel[] = {
    "rviz::RenderPanel\0\0sendMouseMoveEvent()\0"
    "onContextMenuHide()\0"
};

void rviz::RenderPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RenderPanel *_t = static_cast<RenderPanel *>(_o);
        switch (_id) {
        case 0: _t->sendMouseMoveEvent(); break;
        case 1: _t->onContextMenuHide(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::RenderPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::RenderPanel::staticMetaObject = {
    { &QtOgreRenderWindow::staticMetaObject, qt_meta_stringdata_rviz__RenderPanel,
      qt_meta_data_rviz__RenderPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::RenderPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::RenderPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::RenderPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__RenderPanel))
        return static_cast<void*>(const_cast< RenderPanel*>(this));
    if (!strcmp(_clname, "Ogre::SceneManager::Listener"))
        return static_cast< Ogre::SceneManager::Listener*>(const_cast< RenderPanel*>(this));
    return QtOgreRenderWindow::qt_metacast(_clname);
}

int rviz::RenderPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtOgreRenderWindow::qt_metacall(_c, _id, _a);
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
