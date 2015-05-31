
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_property_wrapper.h"

// Extra includes
#include <QList>
#include <config.h>
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

PropertyWrapper::PropertyWrapper(const QString & name, const QVariant default_value, const QString & description, rviz::Property * parent, const char * changed_slot, QObject * receiver) : rviz::Property(name, default_value, description, parent, changed_slot, receiver) {
    // ... middle
}

void PropertyWrapper::addChild(rviz::Property * child, int index)
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

rviz::Property * PropertyWrapper::childAtUnchecked(int index) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.childAtUnchecked", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PropertyWrapper::childEvent(QChildEvent * arg__1)
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

void PropertyWrapper::collapse()
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

void PropertyWrapper::connectNotify(const char * signal)
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

QWidget * PropertyWrapper::createEditor(QWidget * parent, const QStyleOptionViewItem & option)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.createEditor", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PropertyWrapper::customEvent(QEvent * arg__1)
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

void PropertyWrapper::disconnectNotify(const char * signal)
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

bool PropertyWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool PropertyWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void PropertyWrapper::expand()
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

QString PropertyWrapper::getDescription() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.getDescription", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PropertyWrapper::getDisableChildren()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.getDisableChildren", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PropertyWrapper::getHidden() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.getHidden", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QIcon PropertyWrapper::getIcon() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.getIcon", Shiboken::SbkType< QIcon >()->tp_name, pyResult->ob_type->tp_name);
        return ::QIcon();
    }
    ::QIcon cppResult = ::QIcon();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString PropertyWrapper::getName() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.getName", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PropertyWrapper::getReadOnly()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.getReadOnly", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant PropertyWrapper::getValue() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.getValue", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant PropertyWrapper::getViewData(int column, int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getViewData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::getViewData(column, role);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.getViewData", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFlags<Qt::ItemFlag> PropertyWrapper::getViewFlags(int column) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::ItemFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getViewFlags"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::getViewFlags(column);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.getViewFlags", Shiboken::SbkType< QFlags<Qt::ItemFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::ItemFlag>)0);
    }
    ::QFlags<Qt::ItemFlag> cppResult = ((::QFlags<Qt::ItemFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PropertyWrapper::load(const rviz::Config & config)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "load"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::load(config);
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

void PropertyWrapper::moveChild(int from_index, int to_index)
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

int PropertyWrapper::numChildren() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.numChildren", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PropertyWrapper::paint(QPainter * painter, const QStyleOptionViewItem & option) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.paint", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PropertyWrapper::removeChildren(int start_index, int count)
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

void PropertyWrapper::save(rviz::Config config) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "save"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Property::save(config);
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

void PropertyWrapper::setDescription(const QString & description)
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

void PropertyWrapper::setHidden(bool hidden)
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

void PropertyWrapper::setIcon(const QIcon & icon)
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

void PropertyWrapper::setName(const QString & name)
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

void PropertyWrapper::setReadOnly(bool read_only)
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

bool PropertyWrapper::setValue(const QVariant & new_value)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.setValue", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Property * PropertyWrapper::subProp(const QString & sub_name)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.subProp", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Property * PropertyWrapper::takeChildAt(int index)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Property.takeChildAt", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PropertyWrapper::timerEvent(QTimerEvent * arg__1)
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

PropertyWrapper::~PropertyWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_rviz_Property_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::rviz::Property >()))
        return -1;

    ::PropertyWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OOOOOO:Property", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return -1;


    // Overloaded function decisor
    // 0: Property(QString,QVariant,QString,rviz::Property*,const char*,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // Property(QString,QVariant,QString,rviz::Property*,const char*,QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // Property(QString,QVariant,QString,rviz::Property*,const char*,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // Property(QString,QVariant,QString,rviz::Property*,const char*,QObject*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // Property(QString,QVariant,QString,rviz::Property*,const char*,QObject*)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // Property(QString,QVariant,QString,rviz::Property*,const char*,QObject*)
                    } else if (Shiboken::String::check(pyArgs[4]) && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[4])))) {
                        if (numArgs == 5) {
                            overloadId = 0; // Property(QString,QVariant,QString,rviz::Property*,const char*,QObject*)
                        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[5])))) {
                            overloadId = 0; // Property(QString,QVariant,QString,rviz::Property*,const char*,QObject*)
                        }
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_Property_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "name");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property(): got multiple values for keyword argument 'name'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_rviz_Property_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "default_value");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property(): got multiple values for keyword argument 'default_value'.");
                return -1;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1]))))
                    goto Sbk_rviz_Property_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "description");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property(): got multiple values for keyword argument 'description'.");
                return -1;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_rviz_Property_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (pyArgs[3]))))
                    goto Sbk_rviz_Property_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "changed_slot");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property(): got multiple values for keyword argument 'changed_slot'.");
                return -1;
            } else if (value) {
                pyArgs[4] = value;
                if (!Shiboken::String::check(pyArgs[4]) && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[4]))))
                    goto Sbk_rviz_Property_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "receiver");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property(): got multiple values for keyword argument 'receiver'.");
                return -1;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[5]))))
                    goto Sbk_rviz_Property_Init_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = QVariant();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QString();
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return -1;
        ::rviz::Property* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        const char* cppArg4 = 0;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
        if (!Shiboken::Object::isValid(pyArgs[5]))
            return -1;
        ::QObject* cppArg5 = 0;
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // Property(QString,QVariant,QString,rviz::Property*,const char*,QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::PropertyWrapper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::rviz::Property >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_rviz_Property_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_rviz_Property_Init_TypeError:
        const char* overloads[] = {"unicode = QString(), QVariant = QVariant(), unicode = QString(), librviz_shiboken.rviz::Property = None, "SBK_STR_NAME" = None, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Property", overloads);
        return -1;
}

static PyObject* Sbk_rviz_PropertyFunc_addChild(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property.addChild(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property.addChild(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_addChild_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "index");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property.addChild(): got multiple values for keyword argument 'index'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_rviz_PropertyFunc_addChild_TypeError;
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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::addChild(cppArg0, cppArg1) : cppSelf->addChild(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_addChild_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Property, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Property.addChild", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_childAt(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: childAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // childAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_childAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // childAt(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Property * cppResult = const_cast<const ::rviz::Property*>(cppSelf)->childAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_childAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.childAt", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_childAtUnchecked(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_childAtUnchecked_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // childAtUnchecked(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Property * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::childAtUnchecked(cppArg0) : const_cast<const ::rviz::Property*>(cppSelf)->childAtUnchecked(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_childAtUnchecked_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.childAtUnchecked", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_collapse(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // collapse()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::collapse() : cppSelf->collapse();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_PropertyFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contains(rviz::Property*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (pyArg)))) {
        overloadId = 0; // contains(rviz::Property*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_contains_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Property* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contains(rviz::Property*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Property*>(cppSelf)->contains(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_contains_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Property", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.contains", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_createEditor(PyObject* self, PyObject* args)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createEditor", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createEditor(QWidget*,QStyleOptionViewItem)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (pyArgs[1])))) {
        overloadId = 0; // createEditor(QWidget*,QStyleOptionViewItem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_createEditor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOptionViewItem cppArg1_local = ::QStyleOptionViewItem();
        ::QStyleOptionViewItem* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // createEditor(QWidget*,QStyleOptionViewItem)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::createEditor(cppArg0, *cppArg1) : cppSelf->createEditor(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_createEditor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtGui.QStyleOptionViewItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Property.createEditor", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_expand(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // expand()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::expand() : cppSelf->expand();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_PropertyFunc_getDescription(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDescription()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::getDescription() : const_cast<const ::rviz::Property*>(cppSelf)->getDescription();
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

static PyObject* Sbk_rviz_PropertyFunc_getDisableChildren(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDisableChildren()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::getDisableChildren() : cppSelf->getDisableChildren();
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

static PyObject* Sbk_rviz_PropertyFunc_getHidden(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getHidden()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::getHidden() : const_cast<const ::rviz::Property*>(cppSelf)->getHidden();
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

static PyObject* Sbk_rviz_PropertyFunc_getIcon(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIcon()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::getIcon() : const_cast<const ::rviz::Property*>(cppSelf)->getIcon();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_PropertyFunc_getName(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::getName() : const_cast<const ::rviz::Property*>(cppSelf)->getName();
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

static PyObject* Sbk_rviz_PropertyFunc_getParent(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getParent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Property * cppResult = const_cast<const ::rviz::Property*>(cppSelf)->getParent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_PropertyFunc_getReadOnly(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getReadOnly()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::getReadOnly() : cppSelf->getReadOnly();
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

static PyObject* Sbk_rviz_PropertyFunc_getValue(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::getValue() : const_cast<const ::rviz::Property*>(cppSelf)->getValue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_PropertyFunc_getViewData(PyObject* self, PyObject* args)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_getViewData_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getViewData(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::getViewData(cppArg0, cppArg1) : const_cast<const ::rviz::Property*>(cppSelf)->getViewData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_getViewData_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Property.getViewData", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_getViewFlags(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_getViewFlags_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewFlags(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::ItemFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::getViewFlags(cppArg0) : const_cast<const ::rviz::Property*>(cppSelf)->getViewFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_getViewFlags_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.getViewFlags", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_hide(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hide()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->hide();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_PropertyFunc_isAncestorOf(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isAncestorOf(rviz::Property*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (pyArg)))) {
        overloadId = 0; // isAncestorOf(rviz::Property*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_isAncestorOf_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Property* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isAncestorOf(rviz::Property*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Property*>(cppSelf)->isAncestorOf(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_isAncestorOf_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Property", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.isAncestorOf", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_load(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: load(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // load(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_load_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // load(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::load(*cppArg0) : cppSelf->load(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_load_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.load", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_loadValue(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: loadValue(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // loadValue(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_loadValue_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // loadValue(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->loadValue(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_loadValue_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.loadValue", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_moveChild(PyObject* self, PyObject* args)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "moveChild", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: moveChild(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // moveChild(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_moveChild_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // moveChild(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::moveChild(cppArg0, cppArg1) : cppSelf->moveChild(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_moveChild_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Property.moveChild", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_numChildren(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numChildren()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::numChildren() : const_cast<const ::rviz::Property*>(cppSelf)->numChildren();
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

static PyObject* Sbk_rviz_PropertyFunc_paint(PyObject* self, PyObject* args)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "paint", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: paint(QPainter*,QStyleOptionViewItem)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (pyArgs[1])))) {
        overloadId = 0; // paint(QPainter*,QStyleOptionViewItem)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_paint_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOptionViewItem cppArg1_local = ::QStyleOptionViewItem();
        ::QStyleOptionViewItem* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // paint(QPainter*,QStyleOptionViewItem)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::paint(cppArg0, *cppArg1) : const_cast<const ::rviz::Property*>(cppSelf)->paint(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_paint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtGui.QStyleOptionViewItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Property.paint", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_removeChildren(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property.removeChildren(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:removeChildren", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: removeChildren(int,int)
    if (numArgs == 0) {
        overloadId = 0; // removeChildren(int,int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // removeChildren(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // removeChildren(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_removeChildren_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "start_index");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property.removeChildren(): got multiple values for keyword argument 'start_index'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_rviz_PropertyFunc_removeChildren_TypeError;
            }
            value = PyDict_GetItemString(kwds, "count");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.Property.removeChildren(): got multiple values for keyword argument 'count'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_rviz_PropertyFunc_removeChildren_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // removeChildren(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::removeChildren(cppArg0, cppArg1) : cppSelf->removeChildren(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_removeChildren_TypeError:
        const char* overloads[] = {"int = 0, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Property.removeChildren", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_rowNumberInParent(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rowNumberInParent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::rviz::Property*>(cppSelf)->rowNumberInParent();
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

static PyObject* Sbk_rviz_PropertyFunc_save(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: save(rviz::Config)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // save(rviz::Config)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_save_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // save(rviz::Config)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Property*>(cppSelf)->::rviz::Property::save(*cppArg0) : const_cast<const ::rviz::Property*>(cppSelf)->save(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_save_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.save", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_setDescription(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDescription(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDescription(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_setDescription_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDescription(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::setDescription(cppArg0) : cppSelf->setDescription(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_setDescription_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.setDescription", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_setHidden(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHidden(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setHidden(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_setHidden_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHidden(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::setHidden(cppArg0) : cppSelf->setHidden(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_setHidden_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.setHidden", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_setIcon(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIcon(QIcon)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArg)))) {
        overloadId = 0; // setIcon(QIcon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_setIcon_TypeError;

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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::setIcon(*cppArg0) : cppSelf->setIcon(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_setIcon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.setIcon", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_setName(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_setName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::setName(cppArg0) : cppSelf->setName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_setName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.setName", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_setParent(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setParent(rviz::Property*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (pyArg)))) {
        overloadId = 0; // setParent(rviz::Property*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_setParent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Property* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setParent(rviz::Property*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setParent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_setParent_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Property", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.setParent", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_setReadOnly(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadOnly(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setReadOnly(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_setReadOnly_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setReadOnly(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::setReadOnly(cppArg0) : cppSelf->setReadOnly(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_setReadOnly_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.setReadOnly", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_setShouldBeSaved(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setShouldBeSaved(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setShouldBeSaved(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_setShouldBeSaved_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setShouldBeSaved(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setShouldBeSaved(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_PropertyFunc_setShouldBeSaved_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.setShouldBeSaved", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_setValue(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setValue(QVariant)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArg)))) {
        overloadId = 0; // setValue(QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_setValue_TypeError;

    // Call function/method
    {
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setValue(QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::setValue(cppArg0) : cppSelf->setValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_setValue_TypeError:
        const char* overloads[] = {"QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.setValue", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_shouldBeSaved(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // shouldBeSaved()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Property*>(cppSelf)->shouldBeSaved();
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

static PyObject* Sbk_rviz_PropertyFunc_show(PyObject* self)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // show()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->show();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_PropertyFunc_subProp(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: subProp(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // subProp(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_subProp_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // subProp(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Property * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::subProp(cppArg0) : cppSelf->subProp(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_subProp_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.subProp", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_takeChild(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeChild(rviz::Property*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (pyArg)))) {
        overloadId = 0; // takeChild(rviz::Property*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_takeChild_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Property* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeChild(rviz::Property*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Property * cppResult = cppSelf->takeChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_takeChild_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Property", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.takeChild", overloads);
        return 0;
}

static PyObject* Sbk_rviz_PropertyFunc_takeChildAt(PyObject* self, PyObject* pyArg)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_rviz_PropertyFunc_takeChildAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeChildAt(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Property * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Property::takeChildAt(cppArg0) : cppSelf->takeChildAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_PropertyFunc_takeChildAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Property.takeChildAt", overloads);
        return 0;
}

static PyMethodDef Sbk_rviz_Property_methods[] = {
    {"addChild", (PyCFunction)Sbk_rviz_PropertyFunc_addChild, METH_VARARGS|METH_KEYWORDS},
    {"childAt", (PyCFunction)Sbk_rviz_PropertyFunc_childAt, METH_O},
    {"childAtUnchecked", (PyCFunction)Sbk_rviz_PropertyFunc_childAtUnchecked, METH_O},
    {"collapse", (PyCFunction)Sbk_rviz_PropertyFunc_collapse, METH_NOARGS},
    {"contains", (PyCFunction)Sbk_rviz_PropertyFunc_contains, METH_O},
    {"createEditor", (PyCFunction)Sbk_rviz_PropertyFunc_createEditor, METH_VARARGS},
    {"expand", (PyCFunction)Sbk_rviz_PropertyFunc_expand, METH_NOARGS},
    {"getDescription", (PyCFunction)Sbk_rviz_PropertyFunc_getDescription, METH_NOARGS},
    {"getDisableChildren", (PyCFunction)Sbk_rviz_PropertyFunc_getDisableChildren, METH_NOARGS},
    {"getHidden", (PyCFunction)Sbk_rviz_PropertyFunc_getHidden, METH_NOARGS},
    {"getIcon", (PyCFunction)Sbk_rviz_PropertyFunc_getIcon, METH_NOARGS},
    {"getName", (PyCFunction)Sbk_rviz_PropertyFunc_getName, METH_NOARGS},
    {"getParent", (PyCFunction)Sbk_rviz_PropertyFunc_getParent, METH_NOARGS},
    {"getReadOnly", (PyCFunction)Sbk_rviz_PropertyFunc_getReadOnly, METH_NOARGS},
    {"getValue", (PyCFunction)Sbk_rviz_PropertyFunc_getValue, METH_NOARGS},
    {"getViewData", (PyCFunction)Sbk_rviz_PropertyFunc_getViewData, METH_VARARGS},
    {"getViewFlags", (PyCFunction)Sbk_rviz_PropertyFunc_getViewFlags, METH_O},
    {"hide", (PyCFunction)Sbk_rviz_PropertyFunc_hide, METH_NOARGS},
    {"isAncestorOf", (PyCFunction)Sbk_rviz_PropertyFunc_isAncestorOf, METH_O},
    {"load", (PyCFunction)Sbk_rviz_PropertyFunc_load, METH_O},
    {"loadValue", (PyCFunction)Sbk_rviz_PropertyFunc_loadValue, METH_O},
    {"moveChild", (PyCFunction)Sbk_rviz_PropertyFunc_moveChild, METH_VARARGS},
    {"numChildren", (PyCFunction)Sbk_rviz_PropertyFunc_numChildren, METH_NOARGS},
    {"paint", (PyCFunction)Sbk_rviz_PropertyFunc_paint, METH_VARARGS},
    {"removeChildren", (PyCFunction)Sbk_rviz_PropertyFunc_removeChildren, METH_VARARGS|METH_KEYWORDS},
    {"rowNumberInParent", (PyCFunction)Sbk_rviz_PropertyFunc_rowNumberInParent, METH_NOARGS},
    {"save", (PyCFunction)Sbk_rviz_PropertyFunc_save, METH_O},
    {"setDescription", (PyCFunction)Sbk_rviz_PropertyFunc_setDescription, METH_O},
    {"setHidden", (PyCFunction)Sbk_rviz_PropertyFunc_setHidden, METH_O},
    {"setIcon", (PyCFunction)Sbk_rviz_PropertyFunc_setIcon, METH_O},
    {"setName", (PyCFunction)Sbk_rviz_PropertyFunc_setName, METH_O},
    {"setParent", (PyCFunction)Sbk_rviz_PropertyFunc_setParent, METH_O},
    {"setReadOnly", (PyCFunction)Sbk_rviz_PropertyFunc_setReadOnly, METH_O},
    {"setShouldBeSaved", (PyCFunction)Sbk_rviz_PropertyFunc_setShouldBeSaved, METH_O},
    {"setValue", (PyCFunction)Sbk_rviz_PropertyFunc_setValue, METH_O},
    {"shouldBeSaved", (PyCFunction)Sbk_rviz_PropertyFunc_shouldBeSaved, METH_NOARGS},
    {"show", (PyCFunction)Sbk_rviz_PropertyFunc_show, METH_NOARGS},
    {"subProp", (PyCFunction)Sbk_rviz_PropertyFunc_subProp, METH_O},
    {"takeChild", (PyCFunction)Sbk_rviz_PropertyFunc_takeChild, METH_O},
    {"takeChildAt", (PyCFunction)Sbk_rviz_PropertyFunc_takeChildAt, METH_O},

    {0} // Sentinel
};

static PyObject* Sbk_rviz_Property_get_icon_(PyObject* self, void*)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &(cppSelf->icon_), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_rviz_Property_set_icon_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'icon_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'icon_', 'QIcon' or convertible type expected");
        return -1;
    }

    ::QIcon& cppOut_ptr = cppSelf->icon_;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_rviz_Property_get_child_indexes_valid_(PyObject* self, void*)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->child_indexes_valid_;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_rviz_Property_set_child_indexes_valid_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'child_indexes_valid_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'child_indexes_valid_', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->child_indexes_valid_;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->child_indexes_valid_ = cppOut_local;

    return 0;
}

static PyObject* Sbk_rviz_Property_get_value_(PyObject* self, void*)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppSelf->value_);
    return pyOut;
}
static int Sbk_rviz_Property_set_value_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::Property* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Property*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'value_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'value_', 'QVariant' or convertible type expected");
        return -1;
    }

    ::QVariant& cppOut_ptr = cppSelf->value_;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for Property
static PyGetSetDef Sbk_rviz_Property_getsetlist[] = {
    {const_cast<char*>("icon_"), Sbk_rviz_Property_get_icon_, Sbk_rviz_Property_set_icon_},
    {const_cast<char*>("child_indexes_valid_"), Sbk_rviz_Property_get_child_indexes_valid_, Sbk_rviz_Property_set_child_indexes_valid_},
    {const_cast<char*>("value_"), Sbk_rviz_Property_get_value_, Sbk_rviz_Property_set_value_},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_rviz_Property_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_Property_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_Property_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.Property",
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
    /*tp_traverse*/         Sbk_rviz_Property_traverse,
    /*tp_clear*/            Sbk_rviz_Property_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_Property_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_rviz_Property_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_rviz_Property_Init,
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

static void* Sbk_rviz_Property_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::rviz::Property*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Property_PythonToCpp_Property_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_Property_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Property_PythonToCpp_Property_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_Property_Type))
        return Property_PythonToCpp_Property_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Property_PTR_CppToPython_Property(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::Property*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_Property_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_Property(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_Property_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "Property", "rviz::Property*",
        &Sbk_rviz_Property_Type, &Shiboken::callCppDestructor< ::rviz::Property >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_Property_Type,
        Property_PythonToCpp_Property_PTR,
        is_Property_PythonToCpp_Property_PTR_Convertible,
        Property_PTR_CppToPython_Property);

    Shiboken::Conversions::registerConverterName(converter, "rviz::Property");
    Shiboken::Conversions::registerConverterName(converter, "rviz::Property*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::Property&");
    Shiboken::Conversions::registerConverterName(converter, "Property");
    Shiboken::Conversions::registerConverterName(converter, "Property*");
    Shiboken::Conversions::registerConverterName(converter, "Property&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::Property).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PropertyWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_rviz_Property_Type, &Sbk_rviz_Property_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_rviz_Property_Type, &::rviz::Property::staticMetaObject);

}
