/****************************************************************************
** Meta object code from reading C++ file 'panel_dock_widget.h'
**
** Created: Fri Feb 5 05:35:35 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/panel_dock_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panel_dock_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__PanelDockWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   32,   22,   22, 0x0a,
      62,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__PanelDockWidget[] = {
    "rviz::PanelDockWidget\0\0closed()\0title\0"
    "setWindowTitle(QString)\0"
    "onChildDestroyed(QObject*)\0"
};

void rviz::PanelDockWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PanelDockWidget *_t = static_cast<PanelDockWidget *>(_o);
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->setWindowTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onChildDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::PanelDockWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::PanelDockWidget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_rviz__PanelDockWidget,
      qt_meta_data_rviz__PanelDockWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::PanelDockWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::PanelDockWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::PanelDockWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__PanelDockWidget))
        return static_cast<void*>(const_cast< PanelDockWidget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int rviz::PanelDockWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void rviz::PanelDockWidget::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
