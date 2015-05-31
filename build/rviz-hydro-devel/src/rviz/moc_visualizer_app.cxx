/****************************************************************************
** Meta object code from reading C++ file 'visualizer_app.h'
**
** Created: Tue May 12 17:13:17 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/visualizer_app.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualizer_app.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__VisualizerApp[] = {

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
      21,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz__VisualizerApp[] = {
    "rviz::VisualizerApp\0\0checkContinue()\0"
};

void rviz::VisualizerApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VisualizerApp *_t = static_cast<VisualizerApp *>(_o);
        switch (_id) {
        case 0: _t->checkContinue(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::VisualizerApp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::VisualizerApp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rviz__VisualizerApp,
      qt_meta_data_rviz__VisualizerApp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::VisualizerApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::VisualizerApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::VisualizerApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__VisualizerApp))
        return static_cast<void*>(const_cast< VisualizerApp*>(this));
    return QObject::qt_metacast(_clname);
}

int rviz::VisualizerApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
