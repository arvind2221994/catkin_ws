/****************************************************************************
** Meta object code from reading C++ file 'color_editor.h'
**
** Created: Tue May 12 17:13:12 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/color_editor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'color_editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__ColorEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   19,   18,   18, 0x0a,
      42,   18,   18,   18, 0x0a,
      54,   18,   18,   18, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__ColorEditor[] = {
    "rviz::ColorEditor\0\0color\0setColor(QColor)\0"
    "parseText()\0onButtonClick()\0"
};

void rviz::ColorEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ColorEditor *_t = static_cast<ColorEditor *>(_o);
        switch (_id) {
        case 0: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->parseText(); break;
        case 2: _t->onButtonClick(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::ColorEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::ColorEditor::staticMetaObject = {
    { &LineEditWithButton::staticMetaObject, qt_meta_stringdata_rviz__ColorEditor,
      qt_meta_data_rviz__ColorEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::ColorEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::ColorEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::ColorEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__ColorEditor))
        return static_cast<void*>(const_cast< ColorEditor*>(this));
    return LineEditWithButton::qt_metacast(_clname);
}

int rviz::ColorEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LineEditWithButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
