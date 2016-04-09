
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_viewcontroller_wrapper.h"

// Extra includes
#include <QList>
#include <config.h>
#include <property.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qicon.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qpainter.h>
#include <qstyleoption.h>
#include <qthread.h>
#include <qwidget.h>
#include <view_controller.h>

using namespace rviz;

// Native ---------------------------------------------------------

ViewControllerWrapper::ViewControllerWrapper() : rviz::ViewController() {
    // ... middle
}

void ViewControllerWrapper::addChild(rviz::Property * child, int index)
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

rviz::Property * ViewControllerWrapper::childAtUnchecked(int index) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.childAtUnchecked", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void ViewControllerWrapper::childEvent(QChildEvent * arg__1)
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

void ViewControllerWrapper::collapse()
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

void ViewControllerWrapper::connectNotify(const char * signal)
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

QWidget * ViewControllerWrapper::createEditor(QWidget * parent, const QStyleOptionViewItem & option)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.createEditor", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void ViewControllerWrapper::customEvent(QEvent * arg__1)
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

void ViewControllerWrapper::disconnectNotify(const char * signal)
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

bool ViewControllerWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool ViewControllerWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void ViewControllerWrapper::expand()
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

QString ViewControllerWrapper::getClassId() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getClassId"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::getClassId();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getClassId", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QCursor ViewControllerWrapper::getCursor()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QCursor();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getCursor"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::getCursor();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QCursor();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getCursor", Shiboken::SbkType< QCursor >()->tp_name, pyResult->ob_type->tp_name);
        return ::QCursor();
    }
    ::QCursor cppResult = ::QCursor();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString ViewControllerWrapper::getDescription() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getDescription", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool ViewControllerWrapper::getDisableChildren()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getDisableChildren"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::getDisableChildren();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getDisableChildren", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool ViewControllerWrapper::getHidden() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getHidden", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QIcon ViewControllerWrapper::getIcon() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getIcon", Shiboken::SbkType< QIcon >()->tp_name, pyResult->ob_type->tp_name);
        return ::QIcon();
    }
    ::QIcon cppResult = ::QIcon();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString ViewControllerWrapper::getName() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getName", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool ViewControllerWrapper::getReadOnly()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getReadOnly", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant ViewControllerWrapper::getValue() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getValue", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant ViewControllerWrapper::getViewData(int column, int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getViewData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::getViewData(column, role);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getViewData", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFlags<Qt::ItemFlag> ViewControllerWrapper::getViewFlags(int column) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::ItemFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getViewFlags"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::getViewFlags(column);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.getViewFlags", Shiboken::SbkType< QFlags<Qt::ItemFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::ItemFlag>)0);
    }
    ::QFlags<Qt::ItemFlag> cppResult = ((::QFlags<Qt::ItemFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void ViewControllerWrapper::load(const rviz::Config & config)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "load"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::load(config);
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

void ViewControllerWrapper::mimic(rviz::ViewController * source_view)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mimic"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::mimic(source_view);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], source_view)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void ViewControllerWrapper::moveChild(int from_index, int to_index)
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

int ViewControllerWrapper::numChildren() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.numChildren", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void ViewControllerWrapper::onActivate()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onActivate"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::onActivate();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void ViewControllerWrapper::onInitialize()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onInitialize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::onInitialize();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool ViewControllerWrapper::paint(QPainter * painter, const QStyleOptionViewItem & option) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.paint", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void ViewControllerWrapper::removeChildren(int start_index, int count)
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

void ViewControllerWrapper::reset()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "reset"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'ViewController.reset()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void ViewControllerWrapper::save(rviz::Config config) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "save"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::save(config);
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

void ViewControllerWrapper::setClassId(const QString & class_id)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setClassId"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::setClassId(class_id);
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

void ViewControllerWrapper::setDescription(const QString & description)
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

void ViewControllerWrapper::setHidden(bool hidden)
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

void ViewControllerWrapper::setIcon(const QIcon & icon)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setIcon"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::setIcon(icon);
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

void ViewControllerWrapper::setName(const QString & name)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setName"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::setName(name);
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

void ViewControllerWrapper::setReadOnly(bool read_only)
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

bool ViewControllerWrapper::setValue(const QVariant & new_value)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.setValue", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Property * ViewControllerWrapper::subProp(const QString & sub_name)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.subProp", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Property * ViewControllerWrapper::takeChildAt(int index)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "ViewController.takeChildAt", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void ViewControllerWrapper::timerEvent(QTimerEvent * arg__1)
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

void ViewControllerWrapper::transitionFrom(rviz::ViewController * previous_view)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "transitionFrom"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::transitionFrom(previous_view);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], previous_view)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void ViewControllerWrapper::update(float dt, float ros_dt)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "update"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::ViewController::update(dt, ros_dt);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(ff)",
        dt,
        ros_dt
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

ViewControllerWrapper::~ViewControllerWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_rviz_ViewController_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'rviz::ViewController' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::rviz::ViewController >()))
        return -1;

    ::ViewControllerWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ViewController()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::ViewControllerWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::rviz::ViewController >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_rviz_ViewControllerFunc_activate(PyObject* self)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->activate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_ViewControllerFunc_emitConfigChanged(PyObject* self)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // emitConfigChanged()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->emitConfigChanged();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_ViewControllerFunc_formatClassId(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: formatClassId(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // formatClassId(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_formatClassId_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // formatClassId(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::rviz::ViewController::formatClassId(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ViewControllerFunc_formatClassId_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.ViewController.formatClassId", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_getClassId(PyObject* self)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getClassId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::ViewController*>(cppSelf)->::rviz::ViewController::getClassId() : const_cast<const ::rviz::ViewController*>(cppSelf)->getClassId();
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

static PyObject* Sbk_rviz_ViewControllerFunc_getCursor(PyObject* self)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCursor()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QCursor cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::ViewController::getCursor() : cppSelf->getCursor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_ViewControllerFunc_getViewData(PyObject* self, PyObject* args)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_getViewData_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getViewData(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::ViewController*>(cppSelf)->::rviz::ViewController::getViewData(cppArg0, cppArg1) : const_cast<const ::rviz::ViewController*>(cppSelf)->getViewData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ViewControllerFunc_getViewData_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.ViewController.getViewData", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_getViewFlags(PyObject* self, PyObject* pyArg)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_getViewFlags_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewFlags(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::ItemFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::ViewController*>(cppSelf)->::rviz::ViewController::getViewFlags(cppArg0) : const_cast<const ::rviz::ViewController*>(cppSelf)->getViewFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ViewControllerFunc_getViewFlags_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.ViewController.getViewFlags", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_isActive(PyObject* self)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isActive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::ViewController*>(cppSelf)->isActive();
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

static PyObject* Sbk_rviz_ViewControllerFunc_load(PyObject* self, PyObject* pyArg)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: load(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // load(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_load_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // load(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::ViewController::load(*cppArg0) : cppSelf->load(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ViewControllerFunc_load_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.ViewController.load", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_lookAt(PyObject* self, PyObject* args)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "lookAt", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: lookAt(float,float,float)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[2])))) {
        overloadId = 0; // lookAt(float,float,float)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_lookAt_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        float cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        float cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // lookAt(float,float,float)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->lookAt(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ViewControllerFunc_lookAt_TypeError:
        const char* overloads[] = {"float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.ViewController.lookAt", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_mimic(PyObject* self, PyObject* pyArg)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mimic(rviz::ViewController*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (pyArg)))) {
        overloadId = 0; // mimic(rviz::ViewController*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_mimic_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::ViewController* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mimic(rviz::ViewController*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::ViewController::mimic(cppArg0) : cppSelf->mimic(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ViewControllerFunc_mimic_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::ViewController", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.ViewController.mimic", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_onActivate(PyObject* self)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onActivate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::ViewController::onActivate() : cppSelf->onActivate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_ViewControllerFunc_onInitialize(PyObject* self)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onInitialize()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::ViewController::onInitialize() : cppSelf->onInitialize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_ViewControllerFunc_reset(PyObject* self)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'ViewController.reset()' not implemented.");
                return 0;
            }
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

static PyObject* Sbk_rviz_ViewControllerFunc_save(PyObject* self, PyObject* pyArg)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: save(rviz::Config)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // save(rviz::Config)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_save_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // save(rviz::Config)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::ViewController*>(cppSelf)->::rviz::ViewController::save(*cppArg0) : const_cast<const ::rviz::ViewController*>(cppSelf)->save(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ViewControllerFunc_save_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.ViewController.save", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_setClassId(PyObject* self, PyObject* pyArg)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setClassId(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setClassId(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_setClassId_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setClassId(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::ViewController::setClassId(cppArg0) : cppSelf->setClassId(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ViewControllerFunc_setClassId_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.ViewController.setClassId", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_setCursor(PyObject* self, PyObject* pyArg)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCursor(QCursor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], (pyArg)))) {
        overloadId = 0; // setCursor(QCursor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_setCursor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QCursor cppArg0 = ::QCursor();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCursor(QCursor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCursor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ViewControllerFunc_setCursor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCursor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.ViewController.setCursor", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_setStatus(PyObject* self, PyObject* pyArg)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStatus(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setStatus(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_setStatus_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStatus(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStatus(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ViewControllerFunc_setStatus_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.ViewController.setStatus", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_transitionFrom(PyObject* self, PyObject* pyArg)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: transitionFrom(rviz::ViewController*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (pyArg)))) {
        overloadId = 0; // transitionFrom(rviz::ViewController*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_transitionFrom_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::ViewController* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // transitionFrom(rviz::ViewController*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::ViewController::transitionFrom(cppArg0) : cppSelf->transitionFrom(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ViewControllerFunc_transitionFrom_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::ViewController", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.ViewController.transitionFrom", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ViewControllerFunc_update(PyObject* self, PyObject* args)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_rviz_ViewControllerFunc_update_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        float cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // update(float,float)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::ViewController::update(cppArg0, cppArg1) : cppSelf->update(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ViewControllerFunc_update_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.ViewController.update", overloads);
        return 0;
}

static PyMethodDef Sbk_rviz_ViewController_methods[] = {
    {"activate", (PyCFunction)Sbk_rviz_ViewControllerFunc_activate, METH_NOARGS},
    {"emitConfigChanged", (PyCFunction)Sbk_rviz_ViewControllerFunc_emitConfigChanged, METH_NOARGS},
    {"formatClassId", (PyCFunction)Sbk_rviz_ViewControllerFunc_formatClassId, METH_O|METH_STATIC},
    {"getClassId", (PyCFunction)Sbk_rviz_ViewControllerFunc_getClassId, METH_NOARGS},
    {"getCursor", (PyCFunction)Sbk_rviz_ViewControllerFunc_getCursor, METH_NOARGS},
    {"getViewData", (PyCFunction)Sbk_rviz_ViewControllerFunc_getViewData, METH_VARARGS},
    {"getViewFlags", (PyCFunction)Sbk_rviz_ViewControllerFunc_getViewFlags, METH_O},
    {"isActive", (PyCFunction)Sbk_rviz_ViewControllerFunc_isActive, METH_NOARGS},
    {"load", (PyCFunction)Sbk_rviz_ViewControllerFunc_load, METH_O},
    {"lookAt", (PyCFunction)Sbk_rviz_ViewControllerFunc_lookAt, METH_VARARGS},
    {"mimic", (PyCFunction)Sbk_rviz_ViewControllerFunc_mimic, METH_O},
    {"onActivate", (PyCFunction)Sbk_rviz_ViewControllerFunc_onActivate, METH_NOARGS},
    {"onInitialize", (PyCFunction)Sbk_rviz_ViewControllerFunc_onInitialize, METH_NOARGS},
    {"reset", (PyCFunction)Sbk_rviz_ViewControllerFunc_reset, METH_NOARGS},
    {"save", (PyCFunction)Sbk_rviz_ViewControllerFunc_save, METH_O},
    {"setClassId", (PyCFunction)Sbk_rviz_ViewControllerFunc_setClassId, METH_O},
    {"setCursor", (PyCFunction)Sbk_rviz_ViewControllerFunc_setCursor, METH_O},
    {"setStatus", (PyCFunction)Sbk_rviz_ViewControllerFunc_setStatus, METH_O},
    {"transitionFrom", (PyCFunction)Sbk_rviz_ViewControllerFunc_transitionFrom, METH_O},
    {"update", (PyCFunction)Sbk_rviz_ViewControllerFunc_update, METH_VARARGS},

    {0} // Sentinel
};

static PyObject* Sbk_rviz_ViewController_get_cursor_(PyObject* self, void*)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], &(cppSelf->cursor_), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_rviz_ViewController_set_cursor_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'cursor_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'cursor_', 'QCursor' or convertible type expected");
        return -1;
    }

    ::QCursor& cppOut_ptr = cppSelf->cursor_;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_rviz_ViewController_get_stereo_enable_(PyObject* self, void*)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_BOOLPROPERTY_IDX], cppSelf->stereo_enable_);
    return pyOut;
}
static int Sbk_rviz_ViewController_set_stereo_enable_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'stereo_enable_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_BOOLPROPERTY_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'stereo_enable_', 'BoolProperty' or convertible type expected");
        return -1;
    }

    ::rviz::BoolProperty*& cppOut_ptr = cppSelf->stereo_enable_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "stereo_enable_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_ViewController_get_is_active_(PyObject* self, void*)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->is_active_;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_rviz_ViewController_set_is_active_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'is_active_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'is_active_', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->is_active_;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->is_active_ = cppOut_local;

    return 0;
}

static PyObject* Sbk_rviz_ViewController_get_stereo_eye_swap_(PyObject* self, void*)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_BOOLPROPERTY_IDX], cppSelf->stereo_eye_swap_);
    return pyOut;
}
static int Sbk_rviz_ViewController_set_stereo_eye_swap_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::ViewController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::ViewController*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'stereo_eye_swap_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_BOOLPROPERTY_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'stereo_eye_swap_', 'BoolProperty' or convertible type expected");
        return -1;
    }

    ::rviz::BoolProperty*& cppOut_ptr = cppSelf->stereo_eye_swap_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "stereo_eye_swap_", pyIn);
    return 0;
}

// Getters and Setters for ViewController
static PyGetSetDef Sbk_rviz_ViewController_getsetlist[] = {
    {const_cast<char*>("cursor_"), Sbk_rviz_ViewController_get_cursor_, Sbk_rviz_ViewController_set_cursor_},
    {const_cast<char*>("stereo_enable_"), Sbk_rviz_ViewController_get_stereo_enable_, Sbk_rviz_ViewController_set_stereo_enable_},
    {const_cast<char*>("is_active_"), Sbk_rviz_ViewController_get_is_active_, Sbk_rviz_ViewController_set_is_active_},
    {const_cast<char*>("stereo_eye_swap_"), Sbk_rviz_ViewController_get_stereo_eye_swap_, Sbk_rviz_ViewController_set_stereo_eye_swap_},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_rviz_ViewController_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_ViewController_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_ViewController_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.ViewController",
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
    /*tp_traverse*/         Sbk_rviz_ViewController_traverse,
    /*tp_clear*/            Sbk_rviz_ViewController_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_ViewController_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_rviz_ViewController_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_rviz_ViewController_Init,
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

static void* Sbk_rviz_ViewController_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::rviz::ViewController*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ViewController_PythonToCpp_ViewController_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_ViewController_Type, pyIn, cppOut);
}
static PythonToCppFunc is_ViewController_PythonToCpp_ViewController_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_ViewController_Type))
        return ViewController_PythonToCpp_ViewController_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ViewController_PTR_CppToPython_ViewController(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::ViewController*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_ViewController_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_ViewController(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_ViewController_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "ViewController", "rviz::ViewController*",
        &Sbk_rviz_ViewController_Type, &Shiboken::callCppDestructor< ::rviz::ViewController >, (SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_ViewController_Type,
        ViewController_PythonToCpp_ViewController_PTR,
        is_ViewController_PythonToCpp_ViewController_PTR_Convertible,
        ViewController_PTR_CppToPython_ViewController);

    Shiboken::Conversions::registerConverterName(converter, "rviz::ViewController");
    Shiboken::Conversions::registerConverterName(converter, "rviz::ViewController*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::ViewController&");
    Shiboken::Conversions::registerConverterName(converter, "ViewController");
    Shiboken::Conversions::registerConverterName(converter, "ViewController*");
    Shiboken::Conversions::registerConverterName(converter, "ViewController&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::ViewController).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ViewControllerWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_rviz_ViewController_Type, &Sbk_rviz_ViewController_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_rviz_ViewController_Type, &::rviz::ViewController::staticMetaObject);

}
