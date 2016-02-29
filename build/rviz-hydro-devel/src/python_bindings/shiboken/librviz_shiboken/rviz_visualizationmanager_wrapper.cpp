
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_visualizationmanager_wrapper.h"

// Extra includes
#include <config.h>
#include <display.h>
#include <display_group.h>
#include <tool.h>
#include <tool_manager.h>
#include <view_manager.h>

using namespace rviz;

// Native ---------------------------------------------------------

unsigned int VisualizationManagerWrapper::getDefaultVisibilityBit() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((unsigned int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getDefaultVisibilityBit"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationManager::getDefaultVisibilityBit();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((unsigned int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationManager.getDefaultVisibilityBit", "unsigned int", pyResult->ob_type->tp_name);
        return ((unsigned int)0);
    }
    unsigned int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString VisualizationManagerWrapper::getHelpPath() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getHelpPath"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationManager::getHelpPath();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationManager.getHelpPath", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::DisplayGroup * VisualizationManagerWrapper::getRootDisplayGroup() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::DisplayGroup*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getRootDisplayGroup"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationManager::getRootDisplayGroup();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::DisplayGroup*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationManager.getRootDisplayGroup", Shiboken::SbkType< rviz::DisplayGroup >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::DisplayGroup*)0);
    }
    ::rviz::DisplayGroup* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::ToolManager * VisualizationManagerWrapper::getToolManager() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::ToolManager*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getToolManager"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationManager::getToolManager();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::ToolManager*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOLMANAGER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationManager.getToolManager", Shiboken::SbkType< rviz::ToolManager >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::ToolManager*)0);
    }
    ::rviz::ToolManager* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

rviz::ViewManager * VisualizationManagerWrapper::getViewManager() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::rviz::ViewManager*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getViewManager"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationManager::getViewManager();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::rviz::ViewManager*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWMANAGER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VisualizationManager.getViewManager", Shiboken::SbkType< rviz::ViewManager >()->tp_name, pyResult->ob_type->tp_name);
        return ((::rviz::ViewManager*)0);
    }
    ::rviz::ViewManager* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VisualizationManagerWrapper::setHelpPath(const QString & help_path)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setHelpPath"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationManager::setHelpPath(help_path);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &help_path)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VisualizationManagerWrapper::setStatus(const QString & message)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setStatus"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::rviz::VisualizationManager::setStatus(message);
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

VisualizationManagerWrapper::~VisualizationManagerWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_rviz_VisualizationManagerFunc_addDisplay(PyObject* self, PyObject* args)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addDisplay", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addDisplay(rviz::Display*,bool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // addDisplay(rviz::Display*,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationManagerFunc_addDisplay_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::rviz::Display* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addDisplay(rviz::Display*,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addDisplay(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationManagerFunc_addDisplay_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Display, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.VisualizationManager.addDisplay", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_createColorMaterials(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createColorMaterials()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->createColorMaterials();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_createDisplay(PyObject* self, PyObject* args)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createDisplay", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: createDisplay(QString,QString,bool)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))) {
        overloadId = 0; // createDisplay(QString,QString,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationManagerFunc_createDisplay_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        bool cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createDisplay(QString,QString,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Display * cppResult = cppSelf->createDisplay(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_VisualizationManagerFunc_createDisplay_TypeError:
        const char* overloads[] = {"unicode, unicode, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.VisualizationManager.createDisplay", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_emitStatusUpdate(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: emitStatusUpdate(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // emitStatusUpdate(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationManagerFunc_emitStatusUpdate_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // emitStatusUpdate(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->emitStatusUpdate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationManagerFunc_emitStatusUpdate_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationManager.emitStatusUpdate", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_getDefaultVisibilityBit(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDefaultVisibilityBit()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            unsigned int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::VisualizationManager*>(cppSelf)->::rviz::VisualizationManager::getDefaultVisibilityBit() : const_cast<const ::rviz::VisualizationManager*>(cppSelf)->getDefaultVisibilityBit();
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

static PyObject* Sbk_rviz_VisualizationManagerFunc_getFixedFrame(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getFixedFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::rviz::VisualizationManager*>(cppSelf)->getFixedFrame();
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

static PyObject* Sbk_rviz_VisualizationManagerFunc_getHelpPath(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getHelpPath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::VisualizationManager*>(cppSelf)->::rviz::VisualizationManager::getHelpPath() : const_cast<const ::rviz::VisualizationManager*>(cppSelf)->getHelpPath();
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

static PyObject* Sbk_rviz_VisualizationManagerFunc_getROSTime(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getROSTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double cppResult = cppSelf->getROSTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_getROSTimeElapsed(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getROSTimeElapsed()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double cppResult = cppSelf->getROSTimeElapsed();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_getRootDisplayGroup(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getRootDisplayGroup()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::DisplayGroup * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::VisualizationManager*>(cppSelf)->::rviz::VisualizationManager::getRootDisplayGroup() : const_cast<const ::rviz::VisualizationManager*>(cppSelf)->getRootDisplayGroup();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_getToolManager(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getToolManager()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::ToolManager * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::VisualizationManager*>(cppSelf)->::rviz::VisualizationManager::getToolManager() : const_cast<const ::rviz::VisualizationManager*>(cppSelf)->getToolManager();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOLMANAGER_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_getViewManager(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getViewManager()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::ViewManager * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::rviz::VisualizationManager*>(cppSelf)->::rviz::VisualizationManager::getViewManager() : const_cast<const ::rviz::VisualizationManager*>(cppSelf)->getViewManager();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWMANAGER_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_getWallClock(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getWallClock()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double cppResult = cppSelf->getWallClock();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_getWallClockElapsed(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getWallClockElapsed()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double cppResult = cppSelf->getWallClockElapsed();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_initialize(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // initialize()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->initialize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_load(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: load(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // load(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationManagerFunc_load_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // load(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->load(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationManagerFunc_load_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationManager.load", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_lockRender(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lockRender()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->lockRender();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_notifyConfigChanged(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // notifyConfigChanged()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->notifyConfigChanged();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_onToolChanged(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: onToolChanged(rviz::Tool*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX], (pyArg)))) {
        overloadId = 0; // onToolChanged(rviz::Tool*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationManagerFunc_onToolChanged_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Tool* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // onToolChanged(rviz::Tool*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onToolChanged(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationManagerFunc_onToolChanged_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Tool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationManager.onToolChanged", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_onUpdate(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onUpdate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->onUpdate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_queueRender(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

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

static PyObject* Sbk_rviz_VisualizationManagerFunc_removeAllDisplays(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeAllDisplays()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAllDisplays();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_resetTime(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resetTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resetTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_save(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: save(rviz::Config)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // save(rviz::Config)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationManagerFunc_save_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // save(rviz::Config)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::rviz::VisualizationManager*>(cppSelf)->save(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationManagerFunc_save_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationManager.save", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_setFixedFrame(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFixedFrame(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setFixedFrame(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationManagerFunc_setFixedFrame_TypeError;

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

    Sbk_rviz_VisualizationManagerFunc_setFixedFrame_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationManager.setFixedFrame", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_setHelpPath(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHelpPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setHelpPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationManagerFunc_setHelpPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHelpPath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::VisualizationManager::setHelpPath(cppArg0) : cppSelf->setHelpPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationManagerFunc_setHelpPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationManager.setHelpPath", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_setStatus(PyObject* self, PyObject* pyArg)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStatus(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setStatus(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_VisualizationManagerFunc_setStatus_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStatus(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::rviz::VisualizationManager::setStatus(cppArg0) : cppSelf->setStatus(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_VisualizationManagerFunc_setStatus_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.VisualizationManager.setStatus", overloads);
        return 0;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_startUpdate(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startUpdate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->startUpdate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_stopUpdate(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stopUpdate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->stopUpdate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_threadedQueueThreadFunc(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // threadedQueueThreadFunc()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->threadedQueueThreadFunc();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_unlockRender(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unlockRender()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->unlockRender();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_updateFrames(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateFrames()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateFrames();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_VisualizationManagerFunc_updateTime(PyObject* self)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_rviz_VisualizationManager_methods[] = {
    {"addDisplay", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_addDisplay, METH_VARARGS},
    {"createColorMaterials", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_createColorMaterials, METH_NOARGS},
    {"createDisplay", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_createDisplay, METH_VARARGS},
    {"emitStatusUpdate", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_emitStatusUpdate, METH_O},
    {"getDefaultVisibilityBit", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_getDefaultVisibilityBit, METH_NOARGS},
    {"getFixedFrame", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_getFixedFrame, METH_NOARGS},
    {"getHelpPath", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_getHelpPath, METH_NOARGS},
    {"getROSTime", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_getROSTime, METH_NOARGS},
    {"getROSTimeElapsed", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_getROSTimeElapsed, METH_NOARGS},
    {"getRootDisplayGroup", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_getRootDisplayGroup, METH_NOARGS},
    {"getToolManager", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_getToolManager, METH_NOARGS},
    {"getViewManager", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_getViewManager, METH_NOARGS},
    {"getWallClock", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_getWallClock, METH_NOARGS},
    {"getWallClockElapsed", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_getWallClockElapsed, METH_NOARGS},
    {"initialize", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_initialize, METH_NOARGS},
    {"load", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_load, METH_O},
    {"lockRender", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_lockRender, METH_NOARGS},
    {"notifyConfigChanged", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_notifyConfigChanged, METH_NOARGS},
    {"onToolChanged", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_onToolChanged, METH_O},
    {"onUpdate", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_onUpdate, METH_NOARGS},
    {"queueRender", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_queueRender, METH_NOARGS},
    {"removeAllDisplays", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_removeAllDisplays, METH_NOARGS},
    {"resetTime", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_resetTime, METH_NOARGS},
    {"save", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_save, METH_O},
    {"setFixedFrame", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_setFixedFrame, METH_O},
    {"setHelpPath", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_setHelpPath, METH_O},
    {"setStatus", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_setStatus, METH_O},
    {"startUpdate", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_startUpdate, METH_NOARGS},
    {"stopUpdate", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_stopUpdate, METH_NOARGS},
    {"threadedQueueThreadFunc", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_threadedQueueThreadFunc, METH_NOARGS},
    {"unlockRender", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_unlockRender, METH_NOARGS},
    {"updateFrames", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_updateFrames, METH_NOARGS},
    {"updateTime", (PyCFunction)Sbk_rviz_VisualizationManagerFunc_updateTime, METH_NOARGS},

    {0} // Sentinel
};

static PyObject* Sbk_rviz_VisualizationManager_get_global_options_(PyObject* self, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], cppSelf->global_options_);
    return pyOut;
}
static int Sbk_rviz_VisualizationManager_set_global_options_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'global_options_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'global_options_', 'Property' or convertible type expected");
        return -1;
    }

    ::rviz::Property*& cppOut_ptr = cppSelf->global_options_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "global_options_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationManager_get_render_requested_(PyObject* self, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    unsigned int cppOut_local = cppSelf->render_requested_;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_rviz_VisualizationManager_set_render_requested_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'render_requested_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'render_requested_', 'unsigned int' or convertible type expected");
        return -1;
    }

    unsigned int cppOut_local = cppSelf->render_requested_;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->render_requested_ = cppOut_local;

    return 0;
}

static PyObject* Sbk_rviz_VisualizationManager_get_view_manager_(PyObject* self, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWMANAGER_IDX], cppSelf->view_manager_);
    return pyOut;
}
static int Sbk_rviz_VisualizationManager_set_view_manager_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'view_manager_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWMANAGER_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'view_manager_', 'ViewManager' or convertible type expected");
        return -1;
    }

    ::rviz::ViewManager*& cppOut_ptr = cppSelf->view_manager_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "view_manager_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationManager_get_time_update_timer_(PyObject* self, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<float>(), &cppSelf->time_update_timer_);
    return pyOut;
}
static int Sbk_rviz_VisualizationManager_set_time_update_timer_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'time_update_timer_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'time_update_timer_', 'float' or convertible type expected");
        return -1;
    }

    float& cppOut_ptr = cppSelf->time_update_timer_;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_rviz_VisualizationManager_get_tool_manager_(PyObject* self, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOLMANAGER_IDX], cppSelf->tool_manager_);
    return pyOut;
}
static int Sbk_rviz_VisualizationManager_set_tool_manager_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'tool_manager_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOLMANAGER_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'tool_manager_', 'ToolManager' or convertible type expected");
        return -1;
    }

    ::rviz::ToolManager*& cppOut_ptr = cppSelf->tool_manager_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "tool_manager_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationManager_get_root_display_group_(PyObject* self, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], cppSelf->root_display_group_);
    return pyOut;
}
static int Sbk_rviz_VisualizationManager_set_root_display_group_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'root_display_group_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'root_display_group_', 'DisplayGroup' or convertible type expected");
        return -1;
    }

    ::rviz::DisplayGroup*& cppOut_ptr = cppSelf->root_display_group_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "root_display_group_", pyIn);
    return 0;
}

static PyObject* Sbk_rviz_VisualizationManager_get_frame_update_timer_(PyObject* self, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<float>(), &cppSelf->frame_update_timer_);
    return pyOut;
}
static int Sbk_rviz_VisualizationManager_set_frame_update_timer_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'frame_update_timer_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'frame_update_timer_', 'float' or convertible type expected");
        return -1;
    }

    float& cppOut_ptr = cppSelf->frame_update_timer_;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_rviz_VisualizationManager_get_update_timer_(PyObject* self, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMER_IDX], cppSelf->update_timer_);
    return pyOut;
}
static int Sbk_rviz_VisualizationManager_set_update_timer_(PyObject* self, PyObject* pyIn, void*)
{
    ::rviz::VisualizationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::VisualizationManager*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'update_timer_' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMER_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'update_timer_', 'QTimer' or convertible type expected");
        return -1;
    }

    ::QTimer*& cppOut_ptr = cppSelf->update_timer_;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "update_timer_", pyIn);
    return 0;
}

// Getters and Setters for VisualizationManager
static PyGetSetDef Sbk_rviz_VisualizationManager_getsetlist[] = {
    {const_cast<char*>("global_options_"), Sbk_rviz_VisualizationManager_get_global_options_, Sbk_rviz_VisualizationManager_set_global_options_},
    {const_cast<char*>("render_requested_"), Sbk_rviz_VisualizationManager_get_render_requested_, Sbk_rviz_VisualizationManager_set_render_requested_},
    {const_cast<char*>("view_manager_"), Sbk_rviz_VisualizationManager_get_view_manager_, Sbk_rviz_VisualizationManager_set_view_manager_},
    {const_cast<char*>("time_update_timer_"), Sbk_rviz_VisualizationManager_get_time_update_timer_, Sbk_rviz_VisualizationManager_set_time_update_timer_},
    {const_cast<char*>("tool_manager_"), Sbk_rviz_VisualizationManager_get_tool_manager_, Sbk_rviz_VisualizationManager_set_tool_manager_},
    {const_cast<char*>("root_display_group_"), Sbk_rviz_VisualizationManager_get_root_display_group_, Sbk_rviz_VisualizationManager_set_root_display_group_},
    {const_cast<char*>("frame_update_timer_"), Sbk_rviz_VisualizationManager_get_frame_update_timer_, Sbk_rviz_VisualizationManager_set_frame_update_timer_},
    {const_cast<char*>("update_timer_"), Sbk_rviz_VisualizationManager_get_update_timer_, Sbk_rviz_VisualizationManager_set_update_timer_},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_rviz_VisualizationManager_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_VisualizationManager_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_VisualizationManager_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.VisualizationManager",
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_rviz_VisualizationManager_traverse,
    /*tp_clear*/            Sbk_rviz_VisualizationManager_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_VisualizationManager_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_rviz_VisualizationManager_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void VisualizationManager_PythonToCpp_VisualizationManager_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_VisualizationManager_Type, pyIn, cppOut);
}
static PythonToCppFunc is_VisualizationManager_PythonToCpp_VisualizationManager_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_VisualizationManager_Type))
        return VisualizationManager_PythonToCpp_VisualizationManager_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* VisualizationManager_PTR_CppToPython_VisualizationManager(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::VisualizationManager*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_VisualizationManager_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_VisualizationManager(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_VisualizationManager_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "VisualizationManager", "rviz::VisualizationManager*",
        &Sbk_rviz_VisualizationManager_Type, &Shiboken::callCppDestructor< ::rviz::VisualizationManager >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_VisualizationManager_Type,
        VisualizationManager_PythonToCpp_VisualizationManager_PTR,
        is_VisualizationManager_PythonToCpp_VisualizationManager_PTR_Convertible,
        VisualizationManager_PTR_CppToPython_VisualizationManager);

    Shiboken::Conversions::registerConverterName(converter, "rviz::VisualizationManager");
    Shiboken::Conversions::registerConverterName(converter, "rviz::VisualizationManager*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::VisualizationManager&");
    Shiboken::Conversions::registerConverterName(converter, "VisualizationManager");
    Shiboken::Conversions::registerConverterName(converter, "VisualizationManager*");
    Shiboken::Conversions::registerConverterName(converter, "VisualizationManager&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::VisualizationManager).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::VisualizationManagerWrapper).name());


    PySide::Signal::registerSignals(&Sbk_rviz_VisualizationManager_Type, &::rviz::VisualizationManager::staticMetaObject);

}
