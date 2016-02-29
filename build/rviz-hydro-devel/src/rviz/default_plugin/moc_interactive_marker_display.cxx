/****************************************************************************
** Meta object code from reading C++ file 'interactive_marker_display.h'
**
** Created: Fri Feb 5 05:37:11 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/default_plugin/interactive_marker_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interactive_marker_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__InteractiveMarkerDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   31,   31,   31, 0x09,
      46,   31,   31,   31, 0x09,
      71,   31,   31,   31, 0x09,
      88,   31,   31,   31, 0x09,
     111,   31,   31,   31, 0x09,
     147,  138,   31,   31, 0x09,
     227,  211,   31,   31, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__InteractiveMarkerDisplay[] = {
    "rviz::InteractiveMarkerDisplay\0\0"
    "updateTopic()\0updateShowDescriptions()\0"
    "updateShowAxes()\0updateShowVisualAids()\0"
    "updateEnableTransparency()\0feedback\0"
    "publishFeedback(visualization_msgs::InteractiveMarkerFeedback&)\0"
    "level,name,text\0"
    "onStatusUpdate(StatusProperty::Level,std::string,std::string)\0"
};

void rviz::InteractiveMarkerDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InteractiveMarkerDisplay *_t = static_cast<InteractiveMarkerDisplay *>(_o);
        switch (_id) {
        case 0: _t->updateTopic(); break;
        case 1: _t->updateShowDescriptions(); break;
        case 2: _t->updateShowAxes(); break;
        case 3: _t->updateShowVisualAids(); break;
        case 4: _t->updateEnableTransparency(); break;
        case 5: _t->publishFeedback((*reinterpret_cast< visualization_msgs::InteractiveMarkerFeedback(*)>(_a[1]))); break;
        case 6: _t->onStatusUpdate((*reinterpret_cast< StatusProperty::Level(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::InteractiveMarkerDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::InteractiveMarkerDisplay::staticMetaObject = {
    { &Display::staticMetaObject, qt_meta_stringdata_rviz__InteractiveMarkerDisplay,
      qt_meta_data_rviz__InteractiveMarkerDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::InteractiveMarkerDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::InteractiveMarkerDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::InteractiveMarkerDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__InteractiveMarkerDisplay))
        return static_cast<void*>(const_cast< InteractiveMarkerDisplay*>(this));
    return Display::qt_metacast(_clname);
}

int rviz::InteractiveMarkerDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Display::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
