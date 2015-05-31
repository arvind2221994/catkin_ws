
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_displaygroup_wrapper.h"

// Extra includes
#include <QList>
#include <config.h>
#include <display.h>
#include <display_group.h>
#include <panel_dock_widget.h>
#include <property.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qicon.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qpainter.h>
#include <qstyleoption.h>
#include <qthread.h>
#include <qwidget.h>

using namespace rviz;

// Native ---------------------------------------------------------

DisplayGroupWrapper::DisplayGroupWrapper() : rviz::DisplayGroup() {
    // ... middle
}

void DisplayGroupWrapper::addChild(rviz::Property * child, int index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "addChild"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::addChild(child, index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], child),
        index
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::addDisplay(rviz::Display * child)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "addDisplay"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::addDisplay(child);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], child)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::addDisplayWithoutSignallingModel(rviz::Display * child)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "addDisplayWithoutSignallingModel"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::addDisplayWithoutSignallingModel(child);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], child)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

rviz::Property * DisplayGroupWrapper::childAtUnchecked(int index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::Property*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childAtUnchecked"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::childAtUnchecked(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        index
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::Property*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.childAtUnchecked", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayGroupWrapper::childEvent(QChildEvent * arg__1)
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

void DisplayGroupWrapper::clearStatuses()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "clearStatuses"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::clearStatuses();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::collapse()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "collapse"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::collapse();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::connectNotify(const char * signal)
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

QWidget * DisplayGroupWrapper::createEditor(QWidget * parent, const QStyleOptionViewItem & option)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QWidget*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createEditor"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::createEditor(parent, option);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], parent),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], &option)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QWidget*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.createEditor", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayGroupWrapper::customEvent(QEvent * arg__1)
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

void DisplayGroupWrapper::deleteStatus(const QString & name)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "deleteStatus"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::deleteStatus(name);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::disconnectNotify(const char * signal)
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

bool DisplayGroupWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::event(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool DisplayGroupWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void DisplayGroupWrapper::expand()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "expand"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::expand();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::fixedFrameChanged()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fixedFrameChanged"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::fixedFrameChanged();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool DisplayGroupWrapper::getBool() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getBool"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::BoolProperty::getBool();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getBool", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString DisplayGroupWrapper::getClassId() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getClassId"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::getClassId();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getClassId", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString DisplayGroupWrapper::getDescription() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getDescription"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::getDescription();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getDescription", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool DisplayGroupWrapper::getDisableChildren()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getDisableChildren"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::BoolProperty::getDisableChildren();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getDisableChildren", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Display * DisplayGroupWrapper::getDisplayAt(int index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::Display*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getDisplayAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::getDisplayAt(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        index
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::Display*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getDisplayAt", Shiboken::SbkType< rviz::Display >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Display*)0);
    }
    ::rviz::Display* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::DisplayGroup * DisplayGroupWrapper::getGroupAt(int index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::DisplayGroup*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getGroupAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::getGroupAt(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        index
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::DisplayGroup*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getGroupAt", Shiboken::SbkType< rviz::DisplayGroup >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::DisplayGroup*)0);
    }
    ::rviz::DisplayGroup* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool DisplayGroupWrapper::getHidden() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getHidden"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::getHidden();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getHidden", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QIcon DisplayGroupWrapper::getIcon() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QIcon();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getIcon"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::getIcon();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QIcon();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getIcon", Shiboken::SbkType< QIcon >()->tp_name, pyResult->ob_type->tp_name);
        return ::QIcon();
    }
    ::QIcon cppResult = ::QIcon();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString DisplayGroupWrapper::getName() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getName"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::getName();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getName", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool DisplayGroupWrapper::getReadOnly()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getReadOnly"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::getReadOnly();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getReadOnly", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant DisplayGroupWrapper::getValue() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getValue"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::getValue();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getValue", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant DisplayGroupWrapper::getViewData(int column, int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getViewData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::getViewData(column, role);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(ii)",
        column,
        role
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getViewData", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFlags<Qt::ItemFlag> DisplayGroupWrapper::getViewFlags(int column) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::ItemFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getViewFlags"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::getViewFlags(column);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        column
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QFlags<Qt::ItemFlag>)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.getViewFlags", Shiboken::SbkType< QFlags<Qt::ItemFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::ItemFlag>)0);
    }
    ::QFlags<Qt::ItemFlag> cppResult = ((::QFlags<Qt::ItemFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayGroupWrapper::load(const rviz::Config & config)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "load"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::load(config);
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

void DisplayGroupWrapper::moveChild(int from_index, int to_index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "moveChild"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::moveChild(from_index, to_index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(ii)",
        from_index,
        to_index
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int DisplayGroupWrapper::numChildren() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "numChildren"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::numChildren();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.numChildren", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int DisplayGroupWrapper::numDisplays() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "numDisplays"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::numDisplays();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.numDisplays", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayGroupWrapper::onDisable()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onDisable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::onDisable();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::onEnable()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onEnable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::onEnable();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::onEnableChanged()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onEnableChanged"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::onEnableChanged();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::onInitialize()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onInitialize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::onInitialize();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool DisplayGroupWrapper::paint(QPainter * painter, const QStyleOptionViewItem & option) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::paint(painter, option);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], &option)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.paint", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayGroupWrapper::removeAllDisplays()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeAllDisplays"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::removeAllDisplays();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::removeChildren(int start_index, int count)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeChildren"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::removeChildren(start_index, count);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(ii)",
        start_index,
        count
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::reset()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "reset"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::reset();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::save(rviz::Config config) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "save"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::save(config);
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

void DisplayGroupWrapper::setClassId(const QString & class_id)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setClassId"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::setClassId(class_id);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &class_id)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::setDescription(const QString & description)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setDescription"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::setDescription(description);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &description)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::setHidden(bool hidden)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setHidden"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::setHidden(hidden);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &hidden)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::setIcon(const QIcon & icon)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setIcon"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::setIcon(icon);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &icon)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::setName(const QString & name)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setName"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::setName(name);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::setReadOnly(bool read_only)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setReadOnly"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::setReadOnly(read_only);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &read_only)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayGroupWrapper::setTopic(const QString & topic, const QString & datatype)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setTopic"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::setTopic(topic, datatype);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &topic),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &datatype)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool DisplayGroupWrapper::setValue(const QVariant & new_value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setValue"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::setValue(new_value);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &new_value)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.setValue", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Property * DisplayGroupWrapper::subProp(const QString & sub_name)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::Property*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "subProp"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::subProp(sub_name);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &sub_name)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::Property*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.subProp", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Property * DisplayGroupWrapper::takeChildAt(int index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::Property*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "takeChildAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::takeChildAt(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        index
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::Property*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.takeChildAt", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Display * DisplayGroupWrapper::takeDisplay(rviz::Display * child)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::Display*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "takeDisplay"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::takeDisplay(child);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], child)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::Display*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "DisplayGroup.takeDisplay", Shiboken::SbkType< rviz::Display >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Display*)0);
    }
    ::rviz::Display* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayGroupWrapper::timerEvent(QTimerEvent * arg__1)
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

void DisplayGroupWrapper::update(float wall_dt, float ros_dt)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "update"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::DisplayGroup::update(wall_dt, ros_dt);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(ff)",
        wall_dt,
        ros_dt
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

DisplayGroupWrapper::~DisplayGroupWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_rviz_DisplayGroup_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::rviz::DisplayGroup >()))
        return -1;

    ::DisplayGroupWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // DisplayGroup()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::DisplayGroupWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::rviz::DisplayGroup >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_addChild(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.DisplayGroup.addChild(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.DisplayGroup.addChild(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:addChild", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addChild(rviz::Property*,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addChild(rviz::Property*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // addChild(rviz::Property*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_addChild_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "index");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.DisplayGroup.addChild(): got multiple values for keyword argument 'index'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_rviz_DisplayGroupFunc_addChild_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::rviz::Property* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addChild(rviz::Property*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::addChild(cppArg0, cppArg1) : cppSelf->addChild(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayGroupFunc_addChild_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Property, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.DisplayGroup.addChild", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_addDisplay(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addDisplay(rviz::Display*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (pyArg)))) {
        overloadId = 0; // addDisplay(rviz::Display*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_addDisplay_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Display* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addDisplay(rviz::Display*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::addDisplay(cppArg0) : cppSelf->addDisplay(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayGroupFunc_addDisplay_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Display", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.addDisplay", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_addDisplayWithoutSignallingModel(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addDisplayWithoutSignallingModel(rviz::Display*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (pyArg)))) {
        overloadId = 0; // addDisplayWithoutSignallingModel(rviz::Display*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_addDisplayWithoutSignallingModel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Display* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addDisplayWithoutSignallingModel(rviz::Display*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::addDisplayWithoutSignallingModel(cppArg0) : cppSelf->addDisplayWithoutSignallingModel(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayGroupFunc_addDisplayWithoutSignallingModel_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Display", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.addDisplayWithoutSignallingModel", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_childAtUnchecked(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: childAtUnchecked(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // childAtUnchecked(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_childAtUnchecked_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // childAtUnchecked(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Property * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::DisplayGroup*>(cppSelf)->::rviz::DisplayGroup::childAtUnchecked(cppArg0) : const_cast<const ::rviz::DisplayGroup*>(cppSelf)->childAtUnchecked(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_DisplayGroupFunc_childAtUnchecked_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.childAtUnchecked", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_createDisplay(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createDisplay(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // createDisplay(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_createDisplay_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createDisplay(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Display * cppResult = cppSelf->createDisplay(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_DisplayGroupFunc_createDisplay_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.createDisplay", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_fixedFrameChanged(PyObject* self)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fixedFrameChanged()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::fixedFrameChanged() : cppSelf->fixedFrameChanged();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_getDisplayAt(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getDisplayAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getDisplayAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_getDisplayAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getDisplayAt(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Display * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::DisplayGroup*>(cppSelf)->::rviz::DisplayGroup::getDisplayAt(cppArg0) : const_cast<const ::rviz::DisplayGroup*>(cppSelf)->getDisplayAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_DisplayGroupFunc_getDisplayAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.getDisplayAt", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_getGroupAt(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getGroupAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getGroupAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_getGroupAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getGroupAt(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::DisplayGroup * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::DisplayGroup*>(cppSelf)->::rviz::DisplayGroup::getGroupAt(cppArg0) : const_cast<const ::rviz::DisplayGroup*>(cppSelf)->getGroupAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_DisplayGroupFunc_getGroupAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.getGroupAt", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_getViewFlags(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getViewFlags(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getViewFlags(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_getViewFlags_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewFlags(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::ItemFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::DisplayGroup*>(cppSelf)->::rviz::DisplayGroup::getViewFlags(cppArg0) : const_cast<const ::rviz::DisplayGroup*>(cppSelf)->getViewFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_DisplayGroupFunc_getViewFlags_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.getViewFlags", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_load(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: load(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // load(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_load_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // load(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::load(*cppArg0) : cppSelf->load(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayGroupFunc_load_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.load", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_numChildren(PyObject* self)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numChildren()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::DisplayGroup*>(cppSelf)->::rviz::DisplayGroup::numChildren() : const_cast<const ::rviz::DisplayGroup*>(cppSelf)->numChildren();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_numDisplays(PyObject* self)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numDisplays()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::DisplayGroup*>(cppSelf)->::rviz::DisplayGroup::numDisplays() : const_cast<const ::rviz::DisplayGroup*>(cppSelf)->numDisplays();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_onEnableChanged(PyObject* self)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onEnableChanged()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::onEnableChanged() : cppSelf->onEnableChanged();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_removeAllDisplays(PyObject* self)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeAllDisplays()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::removeAllDisplays() : cppSelf->removeAllDisplays();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_reset(PyObject* self)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::reset() : cppSelf->reset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_save(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: save(rviz::Config)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // save(rviz::Config)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_save_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // save(rviz::Config)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::DisplayGroup*>(cppSelf)->::rviz::DisplayGroup::save(*cppArg0) : const_cast<const ::rviz::DisplayGroup*>(cppSelf)->save(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayGroupFunc_save_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.save", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_takeChildAt(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeChildAt(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // takeChildAt(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_takeChildAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeChildAt(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Property * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::takeChildAt(cppArg0) : cppSelf->takeChildAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_DisplayGroupFunc_takeChildAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.takeChildAt", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_takeDisplay(PyObject* self, PyObject* pyArg)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeDisplay(rviz::Display*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (pyArg)))) {
        overloadId = 0; // takeDisplay(rviz::Display*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_takeDisplay_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Display* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeDisplay(rviz::Display*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Display * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::takeDisplay(cppArg0) : cppSelf->takeDisplay(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_DisplayGroupFunc_takeDisplay_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Display", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.DisplayGroup.takeDisplay", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayGroupFunc_update(PyObject* self, PyObject* args)
{
    ::rviz::DisplayGroup* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::DisplayGroup*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "update", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: update(float,float)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[1])))) {
        overloadId = 0; // update(float,float)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayGroupFunc_update_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        float cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // update(float,float)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::DisplayGroup::update(cppArg0, cppArg1) : cppSelf->update(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayGroupFunc_update_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.DisplayGroup.update", overloads);
        return 0;
}

static PyMethodDef Sbk_rviz_DisplayGroup_methods[] = {
    {"addChild", (PyCFunction)Sbk_rviz_DisplayGroupFunc_addChild, METH_VARARGS|METH_KEYWORDS},
    {"addDisplay", (PyCFunction)Sbk_rviz_DisplayGroupFunc_addDisplay, METH_O},
    {"addDisplayWithoutSignallingModel", (PyCFunction)Sbk_rviz_DisplayGroupFunc_addDisplayWithoutSignallingModel, METH_O},
    {"childAtUnchecked", (PyCFunction)Sbk_rviz_DisplayGroupFunc_childAtUnchecked, METH_O},
    {"createDisplay", (PyCFunction)Sbk_rviz_DisplayGroupFunc_createDisplay, METH_O},
    {"fixedFrameChanged", (PyCFunction)Sbk_rviz_DisplayGroupFunc_fixedFrameChanged, METH_NOARGS},
    {"getDisplayAt", (PyCFunction)Sbk_rviz_DisplayGroupFunc_getDisplayAt, METH_O},
    {"getGroupAt", (PyCFunction)Sbk_rviz_DisplayGroupFunc_getGroupAt, METH_O},
    {"getViewFlags", (PyCFunction)Sbk_rviz_DisplayGroupFunc_getViewFlags, METH_O},
    {"load", (PyCFunction)Sbk_rviz_DisplayGroupFunc_load, METH_O},
    {"numChildren", (PyCFunction)Sbk_rviz_DisplayGroupFunc_numChildren, METH_NOARGS},
    {"numDisplays", (PyCFunction)Sbk_rviz_DisplayGroupFunc_numDisplays, METH_NOARGS},
    {"onEnableChanged", (PyCFunction)Sbk_rviz_DisplayGroupFunc_onEnableChanged, METH_NOARGS},
    {"removeAllDisplays", (PyCFunction)Sbk_rviz_DisplayGroupFunc_removeAllDisplays, METH_NOARGS},
    {"reset", (PyCFunction)Sbk_rviz_DisplayGroupFunc_reset, METH_NOARGS},
    {"save", (PyCFunction)Sbk_rviz_DisplayGroupFunc_save, METH_O},
    {"takeChildAt", (PyCFunction)Sbk_rviz_DisplayGroupFunc_takeChildAt, METH_O},
    {"takeDisplay", (PyCFunction)Sbk_rviz_DisplayGroupFunc_takeDisplay, METH_O},
    {"update", (PyCFunction)Sbk_rviz_DisplayGroupFunc_update, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_rviz_DisplayGroup_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_DisplayGroup_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_DisplayGroup_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.DisplayGroup",
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
    /*tp_traverse*/         Sbk_rviz_DisplayGroup_traverse,
    /*tp_clear*/            Sbk_rviz_DisplayGroup_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_DisplayGroup_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_rviz_DisplayGroup_Init,
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

static void* Sbk_rviz_DisplayGroup_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::rviz::DisplayGroup*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void DisplayGroup_PythonToCpp_DisplayGroup_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_DisplayGroup_Type, pyIn, cppOut);
}
static PythonToCppFunc is_DisplayGroup_PythonToCpp_DisplayGroup_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_DisplayGroup_Type))
        return DisplayGroup_PythonToCpp_DisplayGroup_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* DisplayGroup_PTR_CppToPython_DisplayGroup(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::DisplayGroup*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_DisplayGroup_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_DisplayGroup(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_DisplayGroup_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "DisplayGroup", "rviz::DisplayGroup*",
        &Sbk_rviz_DisplayGroup_Type, &Shiboken::callCppDestructor< ::rviz::DisplayGroup >, (SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_DisplayGroup_Type,
        DisplayGroup_PythonToCpp_DisplayGroup_PTR,
        is_DisplayGroup_PythonToCpp_DisplayGroup_PTR_Convertible,
        DisplayGroup_PTR_CppToPython_DisplayGroup);

    Shiboken::Conversions::registerConverterName(converter, "rviz::DisplayGroup");
    Shiboken::Conversions::registerConverterName(converter, "rviz::DisplayGroup*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::DisplayGroup&");
    Shiboken::Conversions::registerConverterName(converter, "DisplayGroup");
    Shiboken::Conversions::registerConverterName(converter, "DisplayGroup*");
    Shiboken::Conversions::registerConverterName(converter, "DisplayGroup&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::DisplayGroup).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::DisplayGroupWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_rviz_DisplayGroup_Type, &Sbk_rviz_DisplayGroup_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_rviz_DisplayGroup_Type, &::rviz::DisplayGroup::staticMetaObject);

}
