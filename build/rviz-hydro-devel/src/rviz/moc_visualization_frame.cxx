/****************************************************************************
** Meta object code from reading C++ file 'visualization_frame.h'
**
** Created: Fri Feb 5 05:35:37 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz-hydro-devel/src/rviz/visualization_frame.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualization_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz__VisualizationFrame[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   26,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   25,   25,   25, 0x0a,
      83,   26,   25,   25, 0x0a,
     102,   25,   25,   25, 0x09,
     111,   25,   25,   25, 0x09,
     120,   25,   25,   25, 0x09,
     131,   25,   25,   25, 0x09,
     145,   25,   25,   25, 0x09,
     170,   25,   25,   25, 0x09,
     183,   25,   25,   25, 0x09,
     204,   25,   25,   25, 0x09,
     224,   25,   25,   25, 0x09,
     264,  240,   25,   25, 0x09,
     301,  294,   25,   25, 0x09,
     341,  336,   25,   25, 0x09,
     356,  336,   25,   25, 0x09,
     374,  336,   25,   25, 0x09,
     403,   25,   25,   25, 0x09,
     418,   25,   25,   25, 0x09,
     434,   25,   25,   25, 0x09,
     462,  452,   25,   25, 0x09,
     493,   25,   25,   25, 0x09,
     501,   25,   25,   25, 0x09,
     524,  519,   25,   25, 0x09,
     543,  519,   25,   25, 0x09,
     571,  563,   25,   25, 0x09,
     605,   25,   25,   25, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_rviz__VisualizationFrame[] = {
    "rviz::VisualizationFrame\0\0message\0"
    "statusUpdate(QString)\0setDisplayConfigModified()\0"
    "setStatus(QString)\0onOpen()\0onSave()\0"
    "onSaveAs()\0onSaveImage()\0"
    "onRecentConfigSelected()\0onHelpWiki()\0"
    "openNewPanelDialog()\0openNewToolDialog()\0"
    "showHelpPanel()\0remove_tool_menu_action\0"
    "onToolbarRemoveTool(QAction*)\0action\0"
    "onToolbarActionTriggered(QAction*)\0"
    "tool\0addTool(Tool*)\0removeTool(Tool*)\0"
    "indicateToolIsCurrent(Tool*)\0"
    "changeMaster()\0onDeletePanel()\0"
    "markLoadingDone()\0directory\0"
    "setImageSaveDirectory(QString)\0reset()\0"
    "onHelpDestroyed()\0hide\0hideLeftDock(bool)\0"
    "hideRightDock(bool)\0visible\0"
    "onDockPanelVisibilityChange(bool)\0"
    "updateFps()\0"
};

void rviz::VisualizationFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VisualizationFrame *_t = static_cast<VisualizationFrame *>(_o);
        switch (_id) {
        case 0: _t->statusUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setDisplayConfigModified(); break;
        case 2: _t->setStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onOpen(); break;
        case 4: _t->onSave(); break;
        case 5: _t->onSaveAs(); break;
        case 6: _t->onSaveImage(); break;
        case 7: _t->onRecentConfigSelected(); break;
        case 8: _t->onHelpWiki(); break;
        case 9: _t->openNewPanelDialog(); break;
        case 10: _t->openNewToolDialog(); break;
        case 11: _t->showHelpPanel(); break;
        case 12: _t->onToolbarRemoveTool((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 13: _t->onToolbarActionTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 14: _t->addTool((*reinterpret_cast< Tool*(*)>(_a[1]))); break;
        case 15: _t->removeTool((*reinterpret_cast< Tool*(*)>(_a[1]))); break;
        case 16: _t->indicateToolIsCurrent((*reinterpret_cast< Tool*(*)>(_a[1]))); break;
        case 17: _t->changeMaster(); break;
        case 18: _t->onDeletePanel(); break;
        case 19: _t->markLoadingDone(); break;
        case 20: _t->setImageSaveDirectory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->reset(); break;
        case 22: _t->onHelpDestroyed(); break;
        case 23: _t->hideLeftDock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->hideRightDock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->onDockPanelVisibilityChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->updateFps(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rviz::VisualizationFrame::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz::VisualizationFrame::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_rviz__VisualizationFrame,
      qt_meta_data_rviz__VisualizationFrame, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz::VisualizationFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz::VisualizationFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz::VisualizationFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__VisualizationFrame))
        return static_cast<void*>(const_cast< VisualizationFrame*>(this));
    if (!strcmp(_clname, "WindowManagerInterface"))
        return static_cast< WindowManagerInterface*>(const_cast< VisualizationFrame*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int rviz::VisualizationFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void rviz::VisualizationFrame::statusUpdate(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
