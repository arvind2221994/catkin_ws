/****************************************************************************
** Meta object code from reading C++ file 'screenshot_dialog.h'
**
** Created: Fri Feb 5 05:35:37 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/screenshot_dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screenshot_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__ScreenshotDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   24,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   23,   23,   23, 0x09,
      77,   23,   23,   23, 0x09,
      89,   23,   23,   23, 0x09,
     109,   23,   23,   23, 0x09,
     124,  116,   23,   23, 0x09,
     175,  158,   23,   23, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__ScreenshotDialog[] = {
    "rviz::ScreenshotDialog\0\0directory\0"
    "savedInDirectory(QString)\0takeScreenshot()\0"
    "onTimeout()\0takeScreenshotNow()\0save()\0"
    "clicked\0onButtonClicked(QAbstractButton*)\0"
    "save_full_window\0setSaveFullWindow(bool)\0"
};

void rviz::ScreenshotDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ScreenshotDialog *_t = static_cast<ScreenshotDialog *>(_o);
        switch (_id) {
        case 0: _t->savedInDirectory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->takeScreenshot(); break;
        case 2: _t->onTimeout(); break;
        case 3: _t->takeScreenshotNow(); break;
        case 4: _t->save(); break;
        case 5: _t->onButtonClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 6: _t->setSaveFullWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::ScreenshotDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::ScreenshotDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_rviz__ScreenshotDialog,
      qt_meta_data_rviz__ScreenshotDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::ScreenshotDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::ScreenshotDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::ScreenshotDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__ScreenshotDialog))
        return static_cast<void*>(const_cast< ScreenshotDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int rviz::ScreenshotDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void rviz::ScreenshotDialog::savedInDirectory(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
