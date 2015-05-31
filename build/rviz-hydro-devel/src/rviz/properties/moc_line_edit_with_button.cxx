/****************************************************************************
** Meta object code from reading C++ file 'line_edit_with_button.h'
**
** Created: Tue May 12 17:13:13 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rviz-hydro-devel/src/rviz/properties/line_edit_with_button.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'line_edit_with_button.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__LineEditWithButton[] = {

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
      26,   25,   25,   25, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__LineEditWithButton[] = {
    "rviz::LineEditWithButton\0\0onButtonClick()\0"
};

void rviz::LineEditWithButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LineEditWithButton *_t = static_cast<LineEditWithButton *>(_o);
        switch (_id) {
        case 0: _t->onButtonClick(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz::LineEditWithButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::LineEditWithButton::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_rviz__LineEditWithButton,
      qt_meta_data_rviz__LineEditWithButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::LineEditWithButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::LineEditWithButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::LineEditWithButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__LineEditWithButton))
        return static_cast<void*>(const_cast< LineEditWithButton*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int rviz::LineEditWithButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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
