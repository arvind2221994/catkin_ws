
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_display_wrapper.h"

// Extra includes
#include <QList>
#include <config.h>
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

DisplayWrapper::DisplayWrapper() : rviz::Display() {
    // ... middle
}

void DisplayWrapper::addChild(rviz::Property * child, int index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "addChild"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::addChild(child, index);
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

rviz::Property * DisplayWrapper::childAtUnchecked(int index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::Property*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childAtUnchecked"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::childAtUnchecked(index);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.childAtUnchecked", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayWrapper::childEvent(QChildEvent * arg__1)
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

void DisplayWrapper::clearStatuses()
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

void DisplayWrapper::collapse()
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

void DisplayWrapper::connectNotify(const char * signal)
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

QWidget * DisplayWrapper::createEditor(QWidget * parent, const QStyleOptionViewItem & option)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.createEditor", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayWrapper::customEvent(QEvent * arg__1)
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

void DisplayWrapper::deleteStatus(const QString & name)
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

void DisplayWrapper::disconnectNotify(const char * signal)
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

bool DisplayWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool DisplayWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void DisplayWrapper::expand()
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

void DisplayWrapper::fixedFrameChanged()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fixedFrameChanged"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::fixedFrameChanged();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool DisplayWrapper::getBool() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getBool", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString DisplayWrapper::getClassId() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getClassId", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString DisplayWrapper::getDescription() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getDescription", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool DisplayWrapper::getDisableChildren()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getDisableChildren", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool DisplayWrapper::getHidden() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getHidden", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QIcon DisplayWrapper::getIcon() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getIcon", Shiboken::SbkType< QIcon >()->tp_name, pyResult->ob_type->tp_name);
        return ::QIcon();
    }
    ::QIcon cppResult = ::QIcon();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString DisplayWrapper::getName() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getName", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool DisplayWrapper::getReadOnly()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getReadOnly", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant DisplayWrapper::getValue() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getValue", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant DisplayWrapper::getViewData(int column, int role) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getViewData", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFlags<Qt::ItemFlag> DisplayWrapper::getViewFlags(int column) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::ItemFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getViewFlags"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::getViewFlags(column);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.getViewFlags", Shiboken::SbkType< QFlags<Qt::ItemFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::ItemFlag>)0);
    }
    ::QFlags<Qt::ItemFlag> cppResult = ((::QFlags<Qt::ItemFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayWrapper::load(const rviz::Config & config)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "load"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::load(config);
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

void DisplayWrapper::moveChild(int from_index, int to_index)
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

int DisplayWrapper::numChildren() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "numChildren"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::numChildren();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.numChildren", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayWrapper::onDisable()
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

void DisplayWrapper::onEnable()
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

void DisplayWrapper::onEnableChanged()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onEnableChanged"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::onEnableChanged();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayWrapper::onInitialize()
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

bool DisplayWrapper::paint(QPainter * painter, const QStyleOptionViewItem & option) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.paint", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayWrapper::removeChildren(int start_index, int count)
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

void DisplayWrapper::reset()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "reset"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::reset();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void DisplayWrapper::save(rviz::Config config) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "save"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::save(config);
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

void DisplayWrapper::setClassId(const QString & class_id)
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

void DisplayWrapper::setDescription(const QString & description)
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

void DisplayWrapper::setHidden(bool hidden)
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

void DisplayWrapper::setIcon(const QIcon & icon)
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

void DisplayWrapper::setName(const QString & name)
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

void DisplayWrapper::setReadOnly(bool read_only)
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

void DisplayWrapper::setTopic(const QString & topic, const QString & datatype)
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

bool DisplayWrapper::setValue(const QVariant & new_value)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.setValue", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Property * DisplayWrapper::subProp(const QString & sub_name)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.subProp", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Property * DisplayWrapper::takeChildAt(int index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::Property*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "takeChildAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::takeChildAt(index);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Display.takeChildAt", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void DisplayWrapper::timerEvent(QTimerEvent * arg__1)
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

void DisplayWrapper::update(float wall_dt, float ros_dt)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "update"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Display::update(wall_dt, ros_dt);
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

DisplayWrapper::~DisplayWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_rviz_Display_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::rviz::Display >()))
        return -1;

    ::DisplayWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // Display()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::DisplayWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::rviz::Display >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_rviz_DisplayFunc_clearStatuses(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearStatuses()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::clearStatuses() : cppSelf->clearStatuses();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayFunc_deleteStatus(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: deleteStatus(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // deleteStatus(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_deleteStatus_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // deleteStatus(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::deleteStatus(cppArg0) : cppSelf->deleteStatus(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_deleteStatus_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.deleteStatus", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_fixedFrameChanged(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fixedFrameChanged()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::fixedFrameChanged() : cppSelf->fixedFrameChanged();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayFunc_getAssociatedWidget(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAssociatedWidget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::rviz::Display*>(cppSelf)->getAssociatedWidget();
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

static PyObject* Sbk_rviz_DisplayFunc_getAssociatedWidgetPanel(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAssociatedWidgetPanel()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::PanelDockWidget * cppResult = cppSelf->getAssociatedWidgetPanel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PANELDOCKWIDGET_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_DisplayFunc_getClassId(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getClassId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Display*>(cppSelf)->::rviz::Display::getClassId() : const_cast<const ::rviz::Display*>(cppSelf)->getClassId();
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

static PyObject* Sbk_rviz_DisplayFunc_getViewData(PyObject* self, PyObject* args)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getViewData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: getViewData(int,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // getViewData(int,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_getViewData_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getViewData(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Display*>(cppSelf)->::rviz::Display::getViewData(cppArg0, cppArg1) : const_cast<const ::rviz::Display*>(cppSelf)->getViewData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_DisplayFunc_getViewData_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Display.getViewData", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_getViewFlags(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_getViewFlags_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewFlags(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::ItemFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Display*>(cppSelf)->::rviz::Display::getViewFlags(cppArg0) : const_cast<const ::rviz::Display*>(cppSelf)->getViewFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_DisplayFunc_getViewFlags_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.getViewFlags", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_getVisibilityBits(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getVisibilityBits()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            unsigned int cppResult = cppSelf->getVisibilityBits();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_DisplayFunc_initialized(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // initialized()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Display*>(cppSelf)->initialized();
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

static PyObject* Sbk_rviz_DisplayFunc_isEnabled(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Display*>(cppSelf)->isEnabled();
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

static PyObject* Sbk_rviz_DisplayFunc_load(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: load(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // load(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_load_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // load(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::load(*cppArg0) : cppSelf->load(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_load_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.load", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_onDisable(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onDisable()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::onDisable() : cppSelf->onDisable();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayFunc_onEnable(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onEnable()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::onEnable() : cppSelf->onEnable();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayFunc_onEnableChanged(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onEnableChanged()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::onEnableChanged() : cppSelf->onEnableChanged();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayFunc_onInitialize(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onInitialize()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::onInitialize() : cppSelf->onInitialize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayFunc_queueRender(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // queueRender()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->queueRender();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayFunc_reset(PyObject* self)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::reset() : cppSelf->reset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_DisplayFunc_save(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: save(rviz::Config)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // save(rviz::Config)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_save_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // save(rviz::Config)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Display*>(cppSelf)->::rviz::Display::save(*cppArg0) : const_cast<const ::rviz::Display*>(cppSelf)->save(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_save_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.save", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_setAssociatedWidget(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAssociatedWidget(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setAssociatedWidget(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_setAssociatedWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAssociatedWidget(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAssociatedWidget(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_setAssociatedWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.setAssociatedWidget", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_setClassId(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setClassId(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setClassId(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_setClassId_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setClassId(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::setClassId(cppArg0) : cppSelf->setClassId(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_setClassId_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.setClassId", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_setEnabled(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_setEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_setEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.setEnabled", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_setFixedFrame(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFixedFrame(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setFixedFrame(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_setFixedFrame_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFixedFrame(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFixedFrame(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_setFixedFrame_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.setFixedFrame", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_setIcon(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIcon(QIcon)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArg)))) {
        overloadId = 0; // setIcon(QIcon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_setIcon_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QIcon cppArg0_local = ::QIcon();
        ::QIcon* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setIcon(QIcon)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::setIcon(*cppArg0) : cppSelf->setIcon(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_setIcon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.setIcon", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_setName(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_setName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::setName(cppArg0) : cppSelf->setName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_setName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.setName", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_setTopic(PyObject* self, PyObject* args)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setTopic", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setTopic(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setTopic(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_setTopic_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setTopic(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::setTopic(cppArg0, cppArg1) : cppSelf->setTopic(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_setTopic_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Display.setTopic", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_setVisibilityBits(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVisibilityBits(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // setVisibilityBits(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_setVisibilityBits_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVisibilityBits(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVisibilityBits(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_setVisibilityBits_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.setVisibilityBits", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_unsetVisibilityBits(PyObject* self, PyObject* pyArg)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unsetVisibilityBits(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // unsetVisibilityBits(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_unsetVisibilityBits_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unsetVisibilityBits(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->unsetVisibilityBits(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_unsetVisibilityBits_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Display.unsetVisibilityBits", overloads);
        return 0;
}

static PyObject* Sbk_rviz_DisplayFunc_update(PyObject* self, PyObject* args)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_rviz_DisplayFunc_update_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        float cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // update(float,float)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Display::update(cppArg0, cppArg1) : cppSelf->update(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_DisplayFunc_update_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Display.update", overloads);
        return 0;
}

static PyMethodDef Sbk_rviz_Display_methods[] = {
    {"clearStatuses", (PyCFunction)Sbk_rviz_DisplayFunc_clearStatuses, METH_NOARGS},
    {"deleteStatus", (PyCFunction)Sbk_rviz_DisplayFunc_deleteStatus, METH_O},
    {"fixedFrameChanged", (PyCFunction)Sbk_rviz_DisplayFunc_fixedFrameChanged, METH_NOARGS},
    {"getAssociatedWidget", (PyCFunction)Sbk_rviz_DisplayFunc_getAssociatedWidget, METH_NOARGS},
    {"getAssociatedWidgetPanel", (PyCFunction)Sbk_rviz_DisplayFunc_getAssociatedWidgetPanel, METH_NOARGS},
    {"getClassId", (PyCFunction)Sbk_rviz_DisplayFunc_getClassId, METH_NOARGS},
    {"getViewData", (PyCFunction)Sbk_rviz_DisplayFunc_getViewData, METH_VARARGS},
    {"getViewFlags", (PyCFunction)Sbk_rviz_DisplayFunc_getViewFlags, METH_O},
    {"getVisibilityBits", (PyCFunction)Sbk_rviz_DisplayFunc_getVisibilityBits, METH_NOARGS},
    {"initialized", (PyCFunction)Sbk_rviz_DisplayFunc_initialized, METH_NOARGS},
    {"isEnabled", (PyCFunction)Sbk_rviz_DisplayFunc_isEnabled, METH_NOARGS},
    {"load", (PyCFunction)Sbk_rviz_DisplayFunc_load, METH_O},
    {"onDisable", (PyCFunction)Sbk_rviz_DisplayFunc_onDisable, METH_NOARGS},
    {"onEnable", (PyCFunction)Sbk_rviz_DisplayFunc_onEnable, METH_NOARGS},
    {"onEnableChanged", (PyCFunction)Sbk_rviz_DisplayFunc_onEnableChanged, METH_NOARGS},
    {"onInitialize", (PyCFunction)Sbk_rviz_DisplayFunc_onInitialize, METH_NOARGS},
    {"queueRender", (PyCFunction)Sbk_rviz_DisplayFunc_queueRender, METH_NOARGS},
    {"reset", (PyCFunction)Sbk_rviz_DisplayFunc_reset, METH_NOARGS},
    {"save", (PyCFunction)Sbk_rviz_DisplayFunc_save, METH_O},
    {"setAssociatedWidget", (PyCFunction)Sbk_rviz_DisplayFunc_setAssociatedWidget, METH_O},
    {"setClassId", (PyCFunction)Sbk_rviz_DisplayFunc_setClassId, METH_O},
    {"setEnabled", (PyCFunction)Sbk_rviz_DisplayFunc_setEnabled, METH_O},
    {"setFixedFrame", (PyCFunction)Sbk_rviz_DisplayFunc_setFixedFrame, METH_O},
    {"setIcon", (PyCFunction)Sbk_rviz_DisplayFunc_setIcon, METH_O},
    {"setName", (PyCFunction)Sbk_rviz_DisplayFunc_setName, METH_O},
    {"setTopic", (PyCFunction)Sbk_rviz_DisplayFunc_setTopic, METH_VARARGS},
    {"setVisibilityBits", (PyCFunction)Sbk_rviz_DisplayFunc_setVisibilityBits, METH_O},
    {"unsetVisibilityBits", (PyCFunction)Sbk_rviz_DisplayFunc_unsetVisibilityBits, METH_O},
    {"update", (PyCFunction)Sbk_rviz_DisplayFunc_update, METH_VARARGS},

    {0} // Sentinel
};

static PyObject* Sbk_rviz_Display_get_fixed_frame_(PyObject* self, void*)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->fixed_frame_);
    return pyOut;
}
static int Sbk_rviz_Display_set_fixed_frame_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::Display* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Display*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'fixed_frame_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'fixed_frame_', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->fixed_frame_;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for Display
static PyGetSetDef Sbk_rviz_Display_getsetlist[] = {
    {const_cast<char*>("fixed_frame_"), Sbk_rviz_Display_get_fixed_frame_, Sbk_rviz_Display_set_fixed_frame_},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_rviz_Display_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_Display_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_Display_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.Display",
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
    /*tp_traverse*/         Sbk_rviz_Display_traverse,
    /*tp_clear*/            Sbk_rviz_Display_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_Display_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_rviz_Display_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_rviz_Display_Init,
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

static void* Sbk_rviz_Display_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::rviz::Display*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Display_PythonToCpp_Display_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_Display_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Display_PythonToCpp_Display_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_Display_Type))
        return Display_PythonToCpp_Display_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Display_PTR_CppToPython_Display(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::Display*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_Display_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_Display(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_Display_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "Display", "rviz::Display*",
        &Sbk_rviz_Display_Type, &Shiboken::callCppDestructor< ::rviz::Display >, (SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_BOOLPROPERTY_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_Display_Type,
        Display_PythonToCpp_Display_PTR,
        is_Display_PythonToCpp_Display_PTR_Convertible,
        Display_PTR_CppToPython_Display);

    Shiboken::Conversions::registerConverterName(converter, "rviz::Display");
    Shiboken::Conversions::registerConverterName(converter, "rviz::Display*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::Display&");
    Shiboken::Conversions::registerConverterName(converter, "Display");
    Shiboken::Conversions::registerConverterName(converter, "Display*");
    Shiboken::Conversions::registerConverterName(converter, "Display&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::Display).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::DisplayWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_rviz_Display_Type, &Sbk_rviz_Display_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_rviz_Display_Type, &::rviz::Display::staticMetaObject);

}
