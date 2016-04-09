
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_tool_wrapper.h"

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
#include <qthread.h>

using namespace rviz;

// Native ---------------------------------------------------------

ToolWrapper::ToolWrapper() : rviz::Tool() {
    // ... middle
}

void ToolWrapper::activate()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "activate"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'Tool.activate()' not implemented.");
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

void ToolWrapper::childEvent(QChildEvent * arg__1)
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

void ToolWrapper::connectNotify(const char * signal)
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

void ToolWrapper::customEvent(QEvent * arg__1)
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

void ToolWrapper::deactivate()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "deactivate"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'Tool.deactivate()' not implemented.");
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

void ToolWrapper::disconnectNotify(const char * signal)
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

bool ToolWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Tool.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool ToolWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Tool.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QString ToolWrapper::getClassId() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getClassId"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Tool::getClassId();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Tool.getClassId", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::Property * ToolWrapper::getPropertyContainer() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::Property*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getPropertyContainer"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Tool::getPropertyContainer();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::Property*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "Tool.getPropertyContainer", Shiboken::SbkType< rviz::Property >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::Property*)0);
    }
    ::rviz::Property* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void ToolWrapper::load(const rviz::Config & config)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "load"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Tool::load(config);
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

void ToolWrapper::onInitialize()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onInitialize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Tool::onInitialize();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void ToolWrapper::save(rviz::Config config) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "save"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Tool::save(config);
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

void ToolWrapper::setClassId(const QString & class_id)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setClassId"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Tool::setClassId(class_id);
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

void ToolWrapper::timerEvent(QTimerEvent * arg__1)
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

void ToolWrapper::update(float wall_dt, float ros_dt)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "update"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::Tool::update(wall_dt, ros_dt);
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

ToolWrapper::~ToolWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_rviz_Tool_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'rviz::Tool' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::rviz::Tool >()))
        return -1;

    ::ToolWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // Tool()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::ToolWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::rviz::Tool >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_rviz_ToolFunc_activate(PyObject* self)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activate()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'Tool.activate()' not implemented.");
                return 0;
            }
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

static PyObject* Sbk_rviz_ToolFunc_deactivate(PyObject* self)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deactivate()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'Tool.deactivate()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->deactivate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_ToolFunc_getClassId(PyObject* self)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getClassId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Tool*>(cppSelf)->::rviz::Tool::getClassId() : const_cast<const ::rviz::Tool*>(cppSelf)->getClassId();
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

static PyObject* Sbk_rviz_ToolFunc_getCursor(PyObject* self)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCursor()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QCursor & cppResult = cppSelf->getCursor();
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

static PyObject* Sbk_rviz_ToolFunc_getDescription(PyObject* self)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDescription()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::rviz::Tool*>(cppSelf)->getDescription();
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

static PyObject* Sbk_rviz_ToolFunc_getIcon(PyObject* self)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIcon()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QIcon & cppResult = cppSelf->getIcon();
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

static PyObject* Sbk_rviz_ToolFunc_getName(PyObject* self)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::rviz::Tool*>(cppSelf)->getName();
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

static PyObject* Sbk_rviz_ToolFunc_getPropertyContainer(PyObject* self)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPropertyContainer()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Property * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Tool*>(cppSelf)->::rviz::Tool::getPropertyContainer() : const_cast<const ::rviz::Tool*>(cppSelf)->getPropertyContainer();
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

static PyObject* Sbk_rviz_ToolFunc_getShortcutKey(PyObject* self)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getShortcutKey()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            char cppResult = cppSelf->getShortcutKey();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<char>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_ToolFunc_load(PyObject* self, PyObject* pyArg)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: load(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // load(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ToolFunc_load_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // load(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Tool::load(*cppArg0) : cppSelf->load(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ToolFunc_load_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Tool.load", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ToolFunc_onInitialize(PyObject* self)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onInitialize()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Tool::onInitialize() : cppSelf->onInitialize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_ToolFunc_save(PyObject* self, PyObject* pyArg)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: save(rviz::Config)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // save(rviz::Config)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ToolFunc_save_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // save(rviz::Config)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::Tool*>(cppSelf)->::rviz::Tool::save(*cppArg0) : const_cast<const ::rviz::Tool*>(cppSelf)->save(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ToolFunc_save_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Tool.save", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ToolFunc_setClassId(PyObject* self, PyObject* pyArg)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setClassId(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setClassId(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ToolFunc_setClassId_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setClassId(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Tool::setClassId(cppArg0) : cppSelf->setClassId(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ToolFunc_setClassId_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Tool.setClassId", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ToolFunc_setCursor(PyObject* self, PyObject* pyArg)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCursor(QCursor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], (pyArg)))) {
        overloadId = 0; // setCursor(QCursor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ToolFunc_setCursor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QCursor cppArg0_local = ::QCursor();
        ::QCursor* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setCursor(QCursor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCursor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ToolFunc_setCursor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCursor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Tool.setCursor", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ToolFunc_setDescription(PyObject* self, PyObject* pyArg)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDescription(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDescription(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ToolFunc_setDescription_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDescription(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDescription(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ToolFunc_setDescription_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Tool.setDescription", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ToolFunc_setIcon(PyObject* self, PyObject* pyArg)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIcon(QIcon)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArg)))) {
        overloadId = 0; // setIcon(QIcon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ToolFunc_setIcon_TypeError;

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
            cppSelf->setIcon(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ToolFunc_setIcon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Tool.setIcon", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ToolFunc_setName(PyObject* self, PyObject* pyArg)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ToolFunc_setName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ToolFunc_setName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Tool.setName", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ToolFunc_setStatus(PyObject* self, PyObject* pyArg)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStatus(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setStatus(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ToolFunc_setStatus_TypeError;

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

    Sbk_rviz_ToolFunc_setStatus_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Tool.setStatus", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ToolFunc_update(PyObject* self, PyObject* args)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_rviz_ToolFunc_update_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        float cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // update(float,float)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::Tool::update(cppArg0, cppArg1) : cppSelf->update(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ToolFunc_update_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Tool.update", overloads);
        return 0;
}

static PyMethodDef Sbk_rviz_Tool_methods[] = {
    {"activate", (PyCFunction)Sbk_rviz_ToolFunc_activate, METH_NOARGS},
    {"deactivate", (PyCFunction)Sbk_rviz_ToolFunc_deactivate, METH_NOARGS},
    {"getClassId", (PyCFunction)Sbk_rviz_ToolFunc_getClassId, METH_NOARGS},
    {"getCursor", (PyCFunction)Sbk_rviz_ToolFunc_getCursor, METH_NOARGS},
    {"getDescription", (PyCFunction)Sbk_rviz_ToolFunc_getDescription, METH_NOARGS},
    {"getIcon", (PyCFunction)Sbk_rviz_ToolFunc_getIcon, METH_NOARGS},
    {"getName", (PyCFunction)Sbk_rviz_ToolFunc_getName, METH_NOARGS},
    {"getPropertyContainer", (PyCFunction)Sbk_rviz_ToolFunc_getPropertyContainer, METH_NOARGS},
    {"getShortcutKey", (PyCFunction)Sbk_rviz_ToolFunc_getShortcutKey, METH_NOARGS},
    {"load", (PyCFunction)Sbk_rviz_ToolFunc_load, METH_O},
    {"onInitialize", (PyCFunction)Sbk_rviz_ToolFunc_onInitialize, METH_NOARGS},
    {"save", (PyCFunction)Sbk_rviz_ToolFunc_save, METH_O},
    {"setClassId", (PyCFunction)Sbk_rviz_ToolFunc_setClassId, METH_O},
    {"setCursor", (PyCFunction)Sbk_rviz_ToolFunc_setCursor, METH_O},
    {"setDescription", (PyCFunction)Sbk_rviz_ToolFunc_setDescription, METH_O},
    {"setIcon", (PyCFunction)Sbk_rviz_ToolFunc_setIcon, METH_O},
    {"setName", (PyCFunction)Sbk_rviz_ToolFunc_setName, METH_O},
    {"setStatus", (PyCFunction)Sbk_rviz_ToolFunc_setStatus, METH_O},
    {"update", (PyCFunction)Sbk_rviz_ToolFunc_update, METH_VARARGS},

    {0} // Sentinel
};

static PyObject* Sbk_rviz_Tool_get_icon_(PyObject* self, void*)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &(cppSelf->icon_), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_rviz_Tool_set_icon_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
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

static PyObject* Sbk_rviz_Tool_get_shortcut_key_(PyObject* self, void*)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    char cppOut_local = cppSelf->shortcut_key_;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<char>(), &cppOut_local);
    return pyOut;
}
static int Sbk_rviz_Tool_set_shortcut_key_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'shortcut_key_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!SbkChar_Check(pyIn) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'shortcut_key_', 'char' or convertible type expected");
        return -1;
    }

    char cppOut_local = cppSelf->shortcut_key_;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->shortcut_key_ = cppOut_local;

    return 0;
}

static PyObject* Sbk_rviz_Tool_get_cursor_(PyObject* self, void*)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], &(cppSelf->cursor_), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_rviz_Tool_set_cursor_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::Tool* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Tool*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (SbkObject*)self));
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

// Getters and Setters for Tool
static PyGetSetDef Sbk_rviz_Tool_getsetlist[] = {
    {const_cast<char*>("icon_"), Sbk_rviz_Tool_get_icon_, Sbk_rviz_Tool_set_icon_},
    {const_cast<char*>("shortcut_key_"), Sbk_rviz_Tool_get_shortcut_key_, Sbk_rviz_Tool_set_shortcut_key_},
    {const_cast<char*>("cursor_"), Sbk_rviz_Tool_get_cursor_, Sbk_rviz_Tool_set_cursor_},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_rviz_Tool_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_Tool_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_Tool_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.Tool",
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
    /*tp_traverse*/         Sbk_rviz_Tool_traverse,
    /*tp_clear*/            Sbk_rviz_Tool_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_Tool_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_rviz_Tool_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_rviz_Tool_Init,
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

static void* Sbk_rviz_Tool_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::rviz::Tool*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Tool_PythonToCpp_Tool_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_Tool_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Tool_PythonToCpp_Tool_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_Tool_Type))
        return Tool_PythonToCpp_Tool_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Tool_PTR_CppToPython_Tool(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::Tool*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_Tool_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_Tool(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_Tool_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "Tool", "rviz::Tool*",
        &Sbk_rviz_Tool_Type, &Shiboken::callCppDestructor< ::rviz::Tool >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_Tool_Type,
        Tool_PythonToCpp_Tool_PTR,
        is_Tool_PythonToCpp_Tool_PTR_Convertible,
        Tool_PTR_CppToPython_Tool);

    Shiboken::Conversions::registerConverterName(converter, "rviz::Tool");
    Shiboken::Conversions::registerConverterName(converter, "rviz::Tool*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::Tool&");
    Shiboken::Conversions::registerConverterName(converter, "Tool");
    Shiboken::Conversions::registerConverterName(converter, "Tool*");
    Shiboken::Conversions::registerConverterName(converter, "Tool&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::Tool).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ToolWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_rviz_Tool_Type, &Sbk_rviz_Tool_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_rviz_Tool_Type, &::rviz::Tool::staticMetaObject);

}
