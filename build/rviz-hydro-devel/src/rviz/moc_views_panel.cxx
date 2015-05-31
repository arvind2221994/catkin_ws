/****************************************************************************
** Meta object code from reading C++ file 'views_panel.h'
**
** Created: Tue May 12 17:13:17 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/views_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'views_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__ViewsPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      33,   18,   17,   17, 0x08,
      60,   17,   17,   17, 0x08,
      78,   17,   17,   17, 0x08,
      95,   17,   17,   17, 0x08,
     111,   17,   17,   17, 0x08,
     136,  130,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__ViewsPanel[] = {
    "rviz::ViewsPanel\0\0selected_index\0"
    "onTypeSelectorChanged(int)\0onDeleteClicked()\0"
    "renameSelected()\0onZeroClicked()\0"
    "onCurrentChanged()\0index\0"
    "setCurrentViewFromIndex(QModelIndex)\0"
};

void rviz::ViewsPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewsPanel *_t = static_cast<ViewsPanel *>(_o);
        switch (_id) {
        case 0: _t->onTypeSelectorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onDeleteClicked(); break;
        case 2: _t->renameSelected(); break;
        case 3: _t->onZeroClicked(); break;
        case 4: _t->onCurrentChanged(); break;
        case 5: _t->setCurrentViewFromIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::ViewsPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::ViewsPanel::staticMetaObject = {
    { &Panel::staticMetaObject, qt_meta_stringdata_rviz__ViewsPanel,
      qt_meta_data_rviz__ViewsPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::ViewsPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::ViewsPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::ViewsPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__ViewsPanel))
        return static_cast<void*>(const_cast< ViewsPanel*>(this));
    return Panel::qt_metacast(_clname);
}

int rviz::ViewsPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Panel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
