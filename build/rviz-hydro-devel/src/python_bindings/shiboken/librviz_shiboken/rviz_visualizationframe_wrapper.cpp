
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include <set>
#include "librviz_shiboken_python.h"

#include "rviz_visualizationframe_wrapper.h"

// Extra includes
#include <QList>
#include <config.h>
#include <panel_dock_widget.h>
#include <qaction.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qdockwidget.h>
#include <qevent.h>
#include <qfont.h>
#include <qfontinfo.h>
#include <qfontmetrics.h>
#include <qgraphicsproxywidget.h>
#include <qicon.h>
#include <qinputcontext.h>
#include <qkeysequence.h>
#include <qlayout.h>
#include <qlocale.h>
#include <qmainwindow.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qobject.h>
#include <qpaintdevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qpoint.h>
#include <qrect.h>
#include <qregion.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstatusbar.h>
#include <qstyle.h>
#include <qtoolbar.h>
#include <qwidget.h>
#include <tool.h>
#include <visualization_manager.h>

using namespace rviz;

// Native ---------------------------------------------------------

VisualizationFrameWrapper::VisualizationFrameWrapper(QWidget * parent) : rviz::VisualizationFrame(parent) {
    // ... middle
}

void VisualizationFrameWrapper::actionEvent(QActionEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "actionEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::actionEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTIONEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

rviz::PanelDockWidget * VisualizationFrameWrapper::addPane(const QString & name, QWidget * panel, Qt::DockWidgetArea area, bool floating)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::PanelDockWidget*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "addPane"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationFrame::addPane(name, panel, area, floating);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], panel),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), &area),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &floating)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::PanelDockWidget*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PANELDOCKWIDGET_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.addPane", Shiboken::SbkType< rviz::PanelDockWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::PanelDockWidget*)0);
    }
    ::rviz::PanelDockWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationFrameWrapper::changeEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::changeEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::childEvent(QChildEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::childEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VisualizationFrameWrapper::closeEvent(QCloseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "closeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationFrame::closeEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCLOSEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::connectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "connectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VisualizationFrameWrapper::contextMenuEvent(QContextMenuEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMainWindow::contextMenuEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QMenu * VisualizationFrameWrapper::createPopupMenu()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QMenu*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createPopupMenu"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMainWindow::createPopupMenu();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QMenu*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.createPopupMenu", Shiboken::SbkType< QMenu >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QMenu*)0);
    }
    ::QMenu* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationFrameWrapper::customEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "customEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::customEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int VisualizationFrameWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "devType"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::devType();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationFrameWrapper::disconnectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "disconnectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VisualizationFrameWrapper::dragEnterEvent(QDragEnterEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragEnterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dragEnterEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::dragLeaveEvent(QDragLeaveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragLeaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dragLeaveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::dragMoveEvent(QDragMoveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dragMoveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::dropEvent(QDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dropEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::enterEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "enterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::enterEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool VisualizationFrameWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMainWindow::event(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool VisualizationFrameWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__2)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationFrameWrapper::focusInEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::focusInEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool VisualizationFrameWrapper::focusNextPrevChild(bool next)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusNextPrevChild"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::focusNextPrevChild(next);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &next)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationFrameWrapper::focusOutEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::focusOutEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QWidget * VisualizationFrameWrapper::getParentWindow()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QWidget*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getParentWindow"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationFrame::getParentWindow();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QWidget*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.getParentWindow", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int VisualizationFrameWrapper::heightForWidth(int arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "heightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::heightForWidth(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationFrameWrapper::hideEvent(QHideEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hideEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::hideEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QHIDEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::inputMethodEvent(QInputMethodEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::inputMethodEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QVariant VisualizationFrameWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::inputMethodQuery(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX]), &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationFrameWrapper::keyPressEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::keyPressEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::keyReleaseEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::keyReleaseEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::languageChange()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "languageChange"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::languageChange();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VisualizationFrameWrapper::leaveEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "leaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationFrame::leaveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::load(const rviz::Config & config)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "load"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationFrame::load(config);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], &config)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int VisualizationFrameWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::metric(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize VisualizationFrameWrapper::minimumSizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumSizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::minimumSizeHint();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSize();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationFrameWrapper::mouseDoubleClickEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseDoubleClickEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mouseDoubleClickEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::mouseMoveEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mouseMoveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::mousePressEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mousePressEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::mouseReleaseEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mouseReleaseEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::moveEvent(QMoveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "moveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::moveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOVEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::onDockPanelVisibilityChange(bool visible)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onDockPanelVisibilityChange"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationFrame::onDockPanelVisibilityChange(visible);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &visible)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QPaintEngine * VisualizationFrameWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::paintEngine();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QPaintEngine*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationFrameWrapper::paintEvent(QPaintEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::paintEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::resizeEvent(QResizeEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "resizeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::resizeEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::save(rviz::Config config)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "save"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationFrame::save(config);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], &config)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VisualizationFrameWrapper::setStatus(const QString & message)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setStatus"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationFrame::setStatus(message);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &message)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VisualizationFrameWrapper::setVisible(bool visible)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setVisible"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::setVisible(visible);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &visible)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VisualizationFrameWrapper::showEvent(QShowEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "showEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::showEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSHOWEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QSize VisualizationFrameWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::sizeHint();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSize();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationFrame.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationFrameWrapper::tabletEvent(QTabletEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "tabletEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::tabletEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void VisualizationFrameWrapper::timerEvent(QTimerEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::timerEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VisualizationFrameWrapper::wheelEvent(QWheelEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::wheelEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

VisualizationFrameWrapper::~VisualizationFrameWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_rviz_VisualizationFrame_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX]);
    if (type != myType) {
        Shiboken::ObjectType::copyMultimpleheritance(type, myType);
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::rviz::VisualizationFrame >()))
        return -1;

    ::VisualizationFrameWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:VisualizationFrame", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: VisualizationFrame(QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // VisualizationFrame(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 0; // VisualizationFrame(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrame_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_rviz_VisualizationFrame_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // VisualizationFrame(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::VisualizationFrameWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::rviz::VisualizationFrame >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_rviz_VisualizationFrame_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_rviz_VisualizationFrame_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.VisualizationFrame", overloads);
        return -1;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_addPane(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame.addPane(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame.addPane(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:addPane", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: addPane(QString,QWidget*,Qt::DockWidgetArea,bool)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // addPane(QString,QWidget*,Qt::DockWidgetArea,bool)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // addPane(QString,QWidget*,Qt::DockWidgetArea,bool)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3])))) {
                overloadId = 0; // addPane(QString,QWidget*,Qt::DockWidgetArea,bool)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_addPane_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "area");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame.addPane(): got multiple values for keyword argument 'area'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), (pyArgs[2]))))
                    goto Sbk_rviz_VisualizationFrameFunc_addPane_TypeError;
            }
            value = PyDict_GetItemString(kwds, "floating");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame.addPane(): got multiple values for keyword argument 'floating'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3]))))
                    goto Sbk_rviz_VisualizationFrameFunc_addPane_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QWidget* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::Qt::DockWidgetArea cppArg2 = Qt::LeftDockWidgetArea;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        bool cppArg3 = true;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // addPane(QString,QWidget*,Qt::DockWidgetArea,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::PanelDockWidget * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::VisualizationFrame::addPane(cppArg0, cppArg1, cppArg2, cppArg3) : cppSelf->addPane(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PANELDOCKWIDGET_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_VisualizationFrameFunc_addPane_TypeError:
        const char* overloads[] = {"unicode, PySide.QtGui.QWidget, PySide.QtCore.Qt.DockWidgetArea = Qt.LeftDockWidgetArea, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.VisualizationFrame.addPane", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_addPanelByName(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame.addPanelByName(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame.addPanelByName(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:addPanelByName", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: addPanelByName(QString,QString,Qt::DockWidgetArea,bool)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // addPanelByName(QString,QString,Qt::DockWidgetArea,bool)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // addPanelByName(QString,QString,Qt::DockWidgetArea,bool)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3])))) {
                overloadId = 0; // addPanelByName(QString,QString,Qt::DockWidgetArea,bool)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_addPanelByName_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "area");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame.addPanelByName(): got multiple values for keyword argument 'area'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), (pyArgs[2]))))
                    goto Sbk_rviz_VisualizationFrameFunc_addPanelByName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "floating");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame.addPanelByName(): got multiple values for keyword argument 'floating'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3]))))
                    goto Sbk_rviz_VisualizationFrameFunc_addPanelByName_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::Qt::DockWidgetArea cppArg2 = Qt::LeftDockWidgetArea;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        bool cppArg3 = true;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // addPanelByName(QString,QString,Qt::DockWidgetArea,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDockWidget * cppResult = cppSelf->addPanelByName(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_VisualizationFrameFunc_addPanelByName_TypeError:
        const char* overloads[] = {"unicode, unicode, PySide.QtCore.Qt.DockWidgetArea = Qt.LeftDockWidgetArea, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.VisualizationFrame.addPanelByName", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_addTool(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addTool(rviz::Tool*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (pyArg)))) {
        overloadId = 0; // addTool(rviz::Tool*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_addTool_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Tool* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addTool(rviz::Tool*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addTool(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_addTool_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Tool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.addTool", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_changeMaster(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // changeMaster()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->changeMaster();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_closeEvent(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: closeEvent(QCloseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCLOSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // closeEvent(QCloseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_closeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QCloseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // closeEvent(QCloseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::VisualizationFrame::closeEvent(cppArg0) : cppSelf->closeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_closeEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCloseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.closeEvent", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_getErrorMessage(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getErrorMessage()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::rviz::VisualizationFrame*>(cppSelf)->getErrorMessage();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_getManager(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getManager()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::VisualizationManager * cppResult = cppSelf->getManager();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_getParentWindow(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getParentWindow()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::VisualizationFrame::getParentWindow() : cppSelf->getParentWindow();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_hideDockImpl(PyObject* self, PyObject* args)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "hideDockImpl", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: hideDockImpl(Qt::DockWidgetArea,bool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // hideDockImpl(Qt::DockWidgetArea,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_hideDockImpl_TypeError;

    // Call function/method
    {
        ::Qt::DockWidgetArea cppArg0 = ((::Qt::DockWidgetArea)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // hideDockImpl(Qt::DockWidgetArea,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->hideDockImpl(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_hideDockImpl_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DockWidgetArea, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.VisualizationFrame.hideDockImpl", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_hideLeftDock(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hideLeftDock(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // hideLeftDock(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_hideLeftDock_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hideLeftDock(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->hideLeftDock(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_hideLeftDock_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.hideLeftDock", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_hideRightDock(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hideRightDock(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // hideRightDock(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_hideRightDock_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hideRightDock(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->hideRightDock(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_hideRightDock_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.hideRightDock", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_indicateToolIsCurrent(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indicateToolIsCurrent(rviz::Tool*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (pyArg)))) {
        overloadId = 0; // indicateToolIsCurrent(rviz::Tool*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_indicateToolIsCurrent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Tool* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indicateToolIsCurrent(rviz::Tool*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->indicateToolIsCurrent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_indicateToolIsCurrent_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Tool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.indicateToolIsCurrent", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_initConfigs(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // initConfigs()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->initConfigs();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_initMenus(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // initMenus()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->initMenus();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_initToolbars(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // initToolbars()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->initToolbars();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_initialize(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame.initialize(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:initialize", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: initialize(QString)
    if (numArgs == 0) {
        overloadId = 0; // initialize(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // initialize(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_initialize_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "display_config_file");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.VisualizationFrame.initialize(): got multiple values for keyword argument 'display_config_file'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_rviz_VisualizationFrameFunc_initialize_TypeError;
            }
        }
        ::QString cppArg0 = "";
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // initialize(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->initialize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_initialize_TypeError:
        const char* overloads[] = {"unicode = \"\"", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.VisualizationFrame.initialize", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_leaveEvent(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: leaveEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // leaveEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_leaveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // leaveEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::VisualizationFrame::leaveEvent(cppArg0) : cppSelf->leaveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_leaveEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.leaveEvent", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_load(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: load(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // load(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_load_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // load(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::VisualizationFrame::load(*cppArg0) : cppSelf->load(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_load_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.load", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_loadDisplayConfig(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: loadDisplayConfig(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // loadDisplayConfig(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_loadDisplayConfig_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // loadDisplayConfig(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->loadDisplayConfig(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_loadDisplayConfig_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.loadDisplayConfig", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_loadPanels(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: loadPanels(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // loadPanels(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_loadPanels_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // loadPanels(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->loadPanels(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_loadPanels_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.loadPanels", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_loadPersistentSettings(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // loadPersistentSettings()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->loadPersistentSettings();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_loadWindowGeometry(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: loadWindowGeometry(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // loadWindowGeometry(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_loadWindowGeometry_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // loadWindowGeometry(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->loadWindowGeometry(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_loadWindowGeometry_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.loadWindowGeometry", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_markLoadingDone(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // markLoadingDone()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->markLoadingDone();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onDeletePanel(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onDeletePanel()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onDeletePanel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onDockPanelVisibilityChange(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: onDockPanelVisibilityChange(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // onDockPanelVisibilityChange(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_onDockPanelVisibilityChange_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // onDockPanelVisibilityChange(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::VisualizationFrame::onDockPanelVisibilityChange(cppArg0) : cppSelf->onDockPanelVisibilityChange(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_onDockPanelVisibilityChange_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.onDockPanelVisibilityChange", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onHelpDestroyed(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onHelpDestroyed()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onHelpDestroyed();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onHelpWiki(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onHelpWiki()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onHelpWiki();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onOpen(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onOpen()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onOpen();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onRecentConfigSelected(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onRecentConfigSelected()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onRecentConfigSelected();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onSave(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onSave()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onSave();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onSaveAs(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onSaveAs()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onSaveAs();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onSaveImage(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onSaveImage()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onSaveImage();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onToolbarActionTriggered(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: onToolbarActionTriggered(QAction*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (pyArg)))) {
        overloadId = 0; // onToolbarActionTriggered(QAction*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_onToolbarActionTriggered_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAction* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // onToolbarActionTriggered(QAction*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onToolbarActionTriggered(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_onToolbarActionTriggered_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.onToolbarActionTriggered", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_onToolbarRemoveTool(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: onToolbarRemoveTool(QAction*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (pyArg)))) {
        overloadId = 0; // onToolbarRemoveTool(QAction*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_onToolbarRemoveTool_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAction* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // onToolbarRemoveTool(QAction*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onToolbarRemoveTool(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_onToolbarRemoveTool_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.onToolbarRemoveTool", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_openNewPanelDialog(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // openNewPanelDialog()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->openNewPanelDialog();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_openNewToolDialog(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // openNewToolDialog()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->openNewToolDialog();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_prepareToExit(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prepareToExit()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->prepareToExit();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_removeTool(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeTool(rviz::Tool*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (pyArg)))) {
        overloadId = 0; // removeTool(rviz::Tool*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_removeTool_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Tool* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeTool(rviz::Tool*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeTool(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_removeTool_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Tool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.removeTool", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_reset(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->reset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_save(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: save(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // save(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_save_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // save(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::VisualizationFrame::save(*cppArg0) : cppSelf->save(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_save_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.save", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_saveDisplayConfig(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: saveDisplayConfig(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // saveDisplayConfig(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_saveDisplayConfig_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // saveDisplayConfig(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->saveDisplayConfig(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_VisualizationFrameFunc_saveDisplayConfig_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.saveDisplayConfig", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_savePanels(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: savePanels(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // savePanels(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_savePanels_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // savePanels(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->savePanels(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_savePanels_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.savePanels", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_savePersistentSettings(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // savePersistentSettings()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->savePersistentSettings();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_saveWindowGeometry(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: saveWindowGeometry(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // saveWindowGeometry(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_saveWindowGeometry_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // saveWindowGeometry(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->saveWindowGeometry(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_saveWindowGeometry_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.saveWindowGeometry", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_setDisplayConfigModified(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setDisplayConfigModified()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDisplayConfigModified();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_setHelpPath(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHelpPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setHelpPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_setHelpPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHelpPath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHelpPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_setHelpPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.setHelpPath", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_setHideButtonVisibility(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHideButtonVisibility(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setHideButtonVisibility(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_setHideButtonVisibility_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHideButtonVisibility(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHideButtonVisibility(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_setHideButtonVisibility_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.setHideButtonVisibility", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_setImageSaveDirectory(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setImageSaveDirectory(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setImageSaveDirectory(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_setImageSaveDirectory_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setImageSaveDirectory(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setImageSaveDirectory(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_setImageSaveDirectory_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.setImageSaveDirectory", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_setShowChooseNewMaster(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setShowChooseNewMaster(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setShowChooseNewMaster(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_setShowChooseNewMaster_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setShowChooseNewMaster(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setShowChooseNewMaster(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_setShowChooseNewMaster_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.setShowChooseNewMaster", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_setSplashPath(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSplashPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setSplashPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_setSplashPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSplashPath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSplashPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_setSplashPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.setSplashPath", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_setStatus(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStatus(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setStatus(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationFrameFunc_setStatus_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStatus(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::VisualizationFrame::setStatus(cppArg0) : cppSelf->setStatus(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationFrameFunc_setStatus_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationFrame.setStatus", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_showHelpPanel(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // showHelpPanel()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->showHelpPanel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_updateFps(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateFps()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateFps();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationFrameFunc_updateRecentConfigMenu(PyObject* self)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateRecentConfigMenu()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateRecentConfigMenu();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_rviz_VisualizationFrame_methods[] = {
    {"addPane", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_addPane, METH_VARARGS|METH_KEYWORDS},
    {"addPanelByName", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_addPanelByName, METH_VARARGS|METH_KEYWORDS},
    {"addTool", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_addTool, METH_O},
    {"changeMaster", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_changeMaster, METH_NOARGS},
    {"closeEvent", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_closeEvent, METH_O},
    {"getErrorMessage", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_getErrorMessage, METH_NOARGS},
    {"getManager", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_getManager, METH_NOARGS},
    {"getParentWindow", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_getParentWindow, METH_NOARGS},
    {"hideDockImpl", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_hideDockImpl, METH_VARARGS},
    {"hideLeftDock", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_hideLeftDock, METH_O},
    {"hideRightDock", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_hideRightDock, METH_O},
    {"indicateToolIsCurrent", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_indicateToolIsCurrent, METH_O},
    {"initConfigs", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_initConfigs, METH_NOARGS},
    {"initMenus", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_initMenus, METH_NOARGS},
    {"initToolbars", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_initToolbars, METH_NOARGS},
    {"initialize", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_initialize, METH_VARARGS|METH_KEYWORDS},
    {"leaveEvent", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_leaveEvent, METH_O},
    {"load", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_load, METH_O},
    {"loadDisplayConfig", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_loadDisplayConfig, METH_O},
    {"loadPanels", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_loadPanels, METH_O},
    {"loadPersistentSettings", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_loadPersistentSettings, METH_NOARGS},
    {"loadWindowGeometry", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_loadWindowGeometry, METH_O},
    {"markLoadingDone", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_markLoadingDone, METH_NOARGS},
    {"onDeletePanel", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onDeletePanel, METH_NOARGS},
    {"onDockPanelVisibilityChange", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onDockPanelVisibilityChange, METH_O},
    {"onHelpDestroyed", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onHelpDestroyed, METH_NOARGS},
    {"onHelpWiki", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onHelpWiki, METH_NOARGS},
    {"onOpen", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onOpen, METH_NOARGS},
    {"onRecentConfigSelected", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onRecentConfigSelected, METH_NOARGS},
    {"onSave", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onSave, METH_NOARGS},
    {"onSaveAs", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onSaveAs, METH_NOARGS},
    {"onSaveImage", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onSaveImage, METH_NOARGS},
    {"onToolbarActionTriggered", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onToolbarActionTriggered, METH_O},
    {"onToolbarRemoveTool", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_onToolbarRemoveTool, METH_O},
    {"openNewPanelDialog", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_openNewPanelDialog, METH_NOARGS},
    {"openNewToolDialog", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_openNewToolDialog, METH_NOARGS},
    {"prepareToExit", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_prepareToExit, METH_NOARGS},
    {"removeTool", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_removeTool, METH_O},
    {"reset", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_reset, METH_NOARGS},
    {"save", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_save, METH_O},
    {"saveDisplayConfig", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_saveDisplayConfig, METH_O},
    {"savePanels", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_savePanels, METH_O},
    {"savePersistentSettings", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_savePersistentSettings, METH_NOARGS},
    {"saveWindowGeometry", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_saveWindowGeometry, METH_O},
    {"setDisplayConfigModified", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_setDisplayConfigModified, METH_NOARGS},
    {"setHelpPath", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_setHelpPath, METH_O},
    {"setHideButtonVisibility", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_setHideButtonVisibility, METH_O},
    {"setImageSaveDirectory", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_setImageSaveDirectory, METH_O},
    {"setShowChooseNewMaster", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_setShowChooseNewMaster, METH_O},
    {"setSplashPath", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_setSplashPath, METH_O},
    {"setStatus", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_setStatus, METH_O},
    {"showHelpPanel", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_showHelpPanel, METH_NOARGS},
    {"updateFps", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_updateFps, METH_NOARGS},
    {"updateRecentConfigMenu", (PyCFunction)Sbk_rviz_VisualizationFrameFunc_updateRecentConfigMenu, METH_NOARGS},

    {0} // Sentinel
};

static PyObject* Sbk_rviz_VisualizationFrame_get_manager_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], cppSelf->manager_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_manager_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'manager_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'manager_', 'VisualizationManager' or convertible type expected");
        return -1;
    }

    ::rviz::VisualizationManager*& cppOut_ptr = cppSelf->manager_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "manager_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_hide_left_dock_button_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBUTTON_IDX], cppSelf->hide_left_dock_button_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_hide_left_dock_button_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'hide_left_dock_button_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBUTTON_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'hide_left_dock_button_', 'QToolButton' or convertible type expected");
        return -1;
    }

    ::QToolButton*& cppOut_ptr = cppSelf->hide_left_dock_button_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "hide_left_dock_button_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_remove_tool_menu_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], cppSelf->remove_tool_menu_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_remove_tool_menu_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'remove_tool_menu_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'remove_tool_menu_', 'QMenu' or convertible type expected");
        return -1;
    }

    ::QMenu*& cppOut_ptr = cppSelf->remove_tool_menu_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "remove_tool_menu_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_toolbar_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], cppSelf->toolbar_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_toolbar_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'toolbar_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'toolbar_', 'QToolBar' or convertible type expected");
        return -1;
    }

    ::QToolBar*& cppOut_ptr = cppSelf->toolbar_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "toolbar_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_recent_configs_menu_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], cppSelf->recent_configs_menu_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_recent_configs_menu_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'recent_configs_menu_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'recent_configs_menu_', 'QMenu' or convertible type expected");
        return -1;
    }

    ::QMenu*& cppOut_ptr = cppSelf->recent_configs_menu_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "recent_configs_menu_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_toolbar_actions_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTIONGROUP_IDX], cppSelf->toolbar_actions_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_toolbar_actions_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'toolbar_actions_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTIONGROUP_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'toolbar_actions_', 'QActionGroup' or convertible type expected");
        return -1;
    }

    ::QActionGroup*& cppOut_ptr = cppSelf->toolbar_actions_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "toolbar_actions_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_loading_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->loading_;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_loading_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'loading_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'loading_', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->loading_;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->loading_ = cppOut_local;

    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_delete_view_menu_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], cppSelf->delete_view_menu_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_delete_view_menu_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'delete_view_menu_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'delete_view_menu_', 'QMenu' or convertible type expected");
        return -1;
    }

    ::QMenu*& cppOut_ptr = cppSelf->delete_view_menu_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "delete_view_menu_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_hide_right_dock_button_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBUTTON_IDX], cppSelf->hide_right_dock_button_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_hide_right_dock_button_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'hide_right_dock_button_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBUTTON_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'hide_right_dock_button_', 'QToolButton' or convertible type expected");
        return -1;
    }

    ::QToolButton*& cppOut_ptr = cppSelf->hide_right_dock_button_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "hide_right_dock_button_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_view_menu_actions_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Sbklibrviz_shibokenTypeConverters[SBK_LIBRVIZ_SHIBOKEN_QLIST_QACTIONPTR_IDX], &cppSelf->view_menu_actions_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_view_menu_actions_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'view_menu_actions_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Sbklibrviz_shibokenTypeConverters[SBK_LIBRVIZ_SHIBOKEN_QLIST_QACTIONPTR_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'view_menu_actions_', 'QList' or convertible type expected");
        return -1;
    }

    ::QList<QAction * >& cppOut_ptr = cppSelf->view_menu_actions_;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_show_choose_new_master_option_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->show_choose_new_master_option_;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_show_choose_new_master_option_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'show_choose_new_master_option_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'show_choose_new_master_option_', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->show_choose_new_master_option_;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->show_choose_new_master_option_ = cppOut_local;

    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_help_path_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->help_path_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_help_path_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'help_path_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'help_path_', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->help_path_;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_initialized_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->initialized_;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_initialized_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'initialized_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'initialized_', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->initialized_;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->initialized_ = cppOut_local;

    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_view_menu_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], cppSelf->view_menu_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_view_menu_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'view_menu_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'view_menu_', 'QMenu' or convertible type expected");
        return -1;
    }

    ::QMenu*& cppOut_ptr = cppSelf->view_menu_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "view_menu_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_error_message_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->error_message_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_error_message_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'error_message_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'error_message_', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->error_message_;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_plugins_menu_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], cppSelf->plugins_menu_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_plugins_menu_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'plugins_menu_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'plugins_menu_', 'QMenu' or convertible type expected");
        return -1;
    }

    ::QMenu*& cppOut_ptr = cppSelf->plugins_menu_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "plugins_menu_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_post_load_timer_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMER_IDX], cppSelf->post_load_timer_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_post_load_timer_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'post_load_timer_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMER_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'post_load_timer_', 'QTimer' or convertible type expected");
        return -1;
    }

    ::QTimer*& cppOut_ptr = cppSelf->post_load_timer_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "post_load_timer_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_fps_label_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLABEL_IDX], cppSelf->fps_label_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_fps_label_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'fps_label_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLABEL_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'fps_label_', 'QLabel' or convertible type expected");
        return -1;
    }

    ::QLabel*& cppOut_ptr = cppSelf->fps_label_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "fps_label_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_add_tool_action_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], cppSelf->add_tool_action_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_add_tool_action_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'add_tool_action_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'add_tool_action_', 'QAction' or convertible type expected");
        return -1;
    }

    ::QAction*& cppOut_ptr = cppSelf->add_tool_action_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "add_tool_action_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_splash_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSPLASHSCREEN_IDX], cppSelf->splash_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_splash_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'splash_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSPLASHSCREEN_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'splash_', 'QSplashScreen' or convertible type expected");
        return -1;
    }

    ::QSplashScreen*& cppOut_ptr = cppSelf->splash_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "splash_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_show_help_action_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], cppSelf->show_help_action_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_show_help_action_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'show_help_action_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'show_help_action_', 'QAction' or convertible type expected");
        return -1;
    }

    ::QAction*& cppOut_ptr = cppSelf->show_help_action_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "show_help_action_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_splash_path_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->splash_path_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_splash_path_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'splash_path_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'splash_path_', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->splash_path_;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_file_menu_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], cppSelf->file_menu_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_file_menu_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'file_menu_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'file_menu_', 'QMenu' or convertible type expected");
        return -1;
    }

    ::QMenu*& cppOut_ptr = cppSelf->file_menu_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "file_menu_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_frame_count_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->frame_count_;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_frame_count_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'frame_count_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'frame_count_', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->frame_count_;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->frame_count_ = cppOut_local;

    return 0;
}

static PyObject* Sbk_rviz_VisualizationFrame_get_status_label_(PyObject* self, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLABEL_IDX], cppSelf->status_label_);
    return pyOut;
}
static int Sbk_rviz_VisualizationFrame_set_status_label_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationFrame*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'status_label_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLABEL_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'status_label_', 'QLabel' or convertible type expected");
        return -1;
    }

    ::QLabel*& cppOut_ptr = cppSelf->status_label_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "status_label_", pyIn);
    return 0;
}

// Getters and Setters for VisualizationFrame
static PyGetSetDef Sbk_rviz_VisualizationFrame_getsetlist[] = {
    {const_cast<char*>("manager_"), Sbk_rviz_VisualizationFrame_get_manager_, Sbk_rviz_VisualizationFrame_set_manager_},
    {const_cast<char*>("hide_left_dock_button_"), Sbk_rviz_VisualizationFrame_get_hide_left_dock_button_, Sbk_rviz_VisualizationFrame_set_hide_left_dock_button_},
    {const_cast<char*>("remove_tool_menu_"), Sbk_rviz_VisualizationFrame_get_remove_tool_menu_, Sbk_rviz_VisualizationFrame_set_remove_tool_menu_},
    {const_cast<char*>("toolbar_"), Sbk_rviz_VisualizationFrame_get_toolbar_, Sbk_rviz_VisualizationFrame_set_toolbar_},
    {const_cast<char*>("recent_configs_menu_"), Sbk_rviz_VisualizationFrame_get_recent_configs_menu_, Sbk_rviz_VisualizationFrame_set_recent_configs_menu_},
    {const_cast<char*>("toolbar_actions_"), Sbk_rviz_VisualizationFrame_get_toolbar_actions_, Sbk_rviz_VisualizationFrame_set_toolbar_actions_},
    {const_cast<char*>("loading_"), Sbk_rviz_VisualizationFrame_get_loading_, Sbk_rviz_VisualizationFrame_set_loading_},
    {const_cast<char*>("delete_view_menu_"), Sbk_rviz_VisualizationFrame_get_delete_view_menu_, Sbk_rviz_VisualizationFrame_set_delete_view_menu_},
    {const_cast<char*>("hide_right_dock_button_"), Sbk_rviz_VisualizationFrame_get_hide_right_dock_button_, Sbk_rviz_VisualizationFrame_set_hide_right_dock_button_},
    {const_cast<char*>("view_menu_actions_"), Sbk_rviz_VisualizationFrame_get_view_menu_actions_, Sbk_rviz_VisualizationFrame_set_view_menu_actions_},
    {const_cast<char*>("show_choose_new_master_option_"), Sbk_rviz_VisualizationFrame_get_show_choose_new_master_option_, Sbk_rviz_VisualizationFrame_set_show_choose_new_master_option_},
    {const_cast<char*>("help_path_"), Sbk_rviz_VisualizationFrame_get_help_path_, Sbk_rviz_VisualizationFrame_set_help_path_},
    {const_cast<char*>("initialized_"), Sbk_rviz_VisualizationFrame_get_initialized_, Sbk_rviz_VisualizationFrame_set_initialized_},
    {const_cast<char*>("view_menu_"), Sbk_rviz_VisualizationFrame_get_view_menu_, Sbk_rviz_VisualizationFrame_set_view_menu_},
    {const_cast<char*>("error_message_"), Sbk_rviz_VisualizationFrame_get_error_message_, Sbk_rviz_VisualizationFrame_set_error_message_},
    {const_cast<char*>("plugins_menu_"), Sbk_rviz_VisualizationFrame_get_plugins_menu_, Sbk_rviz_VisualizationFrame_set_plugins_menu_},
    {const_cast<char*>("post_load_timer_"), Sbk_rviz_VisualizationFrame_get_post_load_timer_, Sbk_rviz_VisualizationFrame_set_post_load_timer_},
    {const_cast<char*>("fps_label_"), Sbk_rviz_VisualizationFrame_get_fps_label_, Sbk_rviz_VisualizationFrame_set_fps_label_},
    {const_cast<char*>("add_tool_action_"), Sbk_rviz_VisualizationFrame_get_add_tool_action_, Sbk_rviz_VisualizationFrame_set_add_tool_action_},
    {const_cast<char*>("splash_"), Sbk_rviz_VisualizationFrame_get_splash_, Sbk_rviz_VisualizationFrame_set_splash_},
    {const_cast<char*>("show_help_action_"), Sbk_rviz_VisualizationFrame_get_show_help_action_, Sbk_rviz_VisualizationFrame_set_show_help_action_},
    {const_cast<char*>("splash_path_"), Sbk_rviz_VisualizationFrame_get_splash_path_, Sbk_rviz_VisualizationFrame_set_splash_path_},
    {const_cast<char*>("file_menu_"), Sbk_rviz_VisualizationFrame_get_file_menu_, Sbk_rviz_VisualizationFrame_set_file_menu_},
    {const_cast<char*>("frame_count_"), Sbk_rviz_VisualizationFrame_get_frame_count_, Sbk_rviz_VisualizationFrame_set_frame_count_},
    {const_cast<char*>("status_label_"), Sbk_rviz_VisualizationFrame_get_status_label_, Sbk_rviz_VisualizationFrame_set_status_label_},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_rviz_VisualizationFrame_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_VisualizationFrame_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static int mi_offsets[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int*
Sbk_rviz_VisualizationFrame_mi_init(const void* cptr)
{
    if (mi_offsets[0] == -1) {
        std::set<int> offsets;
        std::set<int>::iterator it;
        const rviz::VisualizationFrame* class_ptr = reinterpret_cast<const rviz::VisualizationFrame*>(cptr);
        size_t base = (size_t) class_ptr;
        offsets.insert(((size_t) static_cast<const QMainWindow*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QMainWindow*>((rviz::VisualizationFrame*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const QWidget*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QWidget*>((QMainWindow*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const QObject*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QObject*>((QWidget*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const QPaintDevice*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QPaintDevice*>((QWidget*)((void*)class_ptr))) - base);

        offsets.erase(0);

        int i = 0;
        for (it = offsets.begin(); it != offsets.end(); it++) {
            mi_offsets[i] = *it;
            i++;
        }
    }
    return mi_offsets;
}
static void* Sbk_rviz_VisualizationFrameSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    rviz::VisualizationFrame* me = reinterpret_cast< ::rviz::VisualizationFrame*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX]))
        return static_cast< ::QMainWindow*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]))
        return static_cast< ::QWidget*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast< ::QObject*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX]))
        return static_cast< ::QPaintDevice*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_VisualizationFrame_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.VisualizationFrame",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             0,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             0,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_rviz_VisualizationFrame_traverse,
    /*tp_clear*/            Sbk_rviz_VisualizationFrame_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_VisualizationFrame_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_rviz_VisualizationFrame_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_rviz_VisualizationFrame_Init,
    /*tp_alloc*/            0,
    /*tp_new*/              SbkObjectTpNew,
    /*tp_free*/             0,
    /*tp_is_gc*/            0,
    /*tp_bases*/            0,
    /*tp_mro*/              0,
    /*tp_cache*/            0,
    /*tp_subclasses*/       0,
    /*tp_weaklist*/         0
}, },
    /*priv_data*/           0
};
} //extern

static void* Sbk_rviz_VisualizationFrame_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::rviz::VisualizationFrame*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::rviz::VisualizationFrame*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void VisualizationFrame_PythonToCpp_VisualizationFrame_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_VisualizationFrame_Type, pyIn, cppOut);
}
static PythonToCppFunc is_VisualizationFrame_PythonToCpp_VisualizationFrame_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_VisualizationFrame_Type))
        return VisualizationFrame_PythonToCpp_VisualizationFrame_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* VisualizationFrame_PTR_CppToPython_VisualizationFrame(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::VisualizationFrame*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_VisualizationFrame_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_VisualizationFrame(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_VisualizationFrame_Type);

    PyObject* Sbk_rviz_VisualizationFrame_Type_bases = PyTuple_Pack(1,
        (PyObject*)SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX]);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "VisualizationFrame", "rviz::VisualizationFrame*",
        &Sbk_rviz_VisualizationFrame_Type, &Shiboken::callCppDestructor< ::rviz::VisualizationFrame >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], Sbk_rviz_VisualizationFrame_Type_bases, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_VisualizationFrame_Type,
        VisualizationFrame_PythonToCpp_VisualizationFrame_PTR,
        is_VisualizationFrame_PythonToCpp_VisualizationFrame_PTR_Convertible,
        VisualizationFrame_PTR_CppToPython_VisualizationFrame);

    Shiboken::Conversions::registerConverterName(converter, "rviz::VisualizationFrame");
    Shiboken::Conversions::registerConverterName(converter, "rviz::VisualizationFrame*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::VisualizationFrame&");
    Shiboken::Conversions::registerConverterName(converter, "VisualizationFrame");
    Shiboken::Conversions::registerConverterName(converter, "VisualizationFrame*");
    Shiboken::Conversions::registerConverterName(converter, "VisualizationFrame&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::VisualizationFrame).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::VisualizationFrameWrapper).name());


    MultipleInheritanceInitFunction func = Sbk_rviz_VisualizationFrame_mi_init;
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_rviz_VisualizationFrame_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_rviz_VisualizationFrame_Type, &Sbk_rviz_VisualizationFrameSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_rviz_VisualizationFrame_Type, &Sbk_rviz_VisualizationFrame_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_rviz_VisualizationFrame_Type, &::rviz::VisualizationFrame::staticMetaObject);

}
