
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_config_wrapper.h"
#include "rviz_config_mapiterator_wrapper.h"

// Extra includes
#include <config.h>

using namespace rviz;


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_rviz_Config_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::rviz::Config >()))
        return -1;

    ::rviz::Config* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "Config", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: Config()
    // 1: Config(QVariant)
    // 2: Config(rviz::Config)
    if (numArgs == 0) {
        overloadId = 0; // Config()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArgs[0])))) {
        overloadId = 2; // Config(rviz::Config)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[0])))) {
        overloadId = 1; // Config(QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_Config_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // Config()
        {

            if (!PyErr_Occurred()) {
                // Config()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::rviz::Config();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // Config(QVariant value)
        {
            ::QVariant cppArg0 = ::QVariant();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // Config(QVariant)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::rviz::Config(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // Config(const rviz::Config & source)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::rviz::Config* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // Config(rviz::Config)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::rviz::Config(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::rviz::Config >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_rviz_Config_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_rviz_Config_Init_TypeError:
        const char* overloads[] = {"", "QVariant", "librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Config", overloads);
        return -1;
}

static PyObject* Sbk_rviz_ConfigFunc_copy(PyObject* self, PyObject* pyArg)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: copy(rviz::Config)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArg)))) {
        overloadId = 0; // copy(rviz::Config)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_copy_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // copy(rviz::Config)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->copy(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ConfigFunc_copy_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Config.copy", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_getType(PyObject* self)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Config::Type cppResult = const_cast<const ::rviz::Config*>(cppSelf)->getType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_ConfigFunc_getValue(PyObject* self)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::rviz::Config*>(cppSelf)->getValue();
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

static PyObject* Sbk_rviz_ConfigFunc_isValid(PyObject* self)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Config*>(cppSelf)->isValid();
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

static PyObject* Sbk_rviz_ConfigFunc_listAppendNew(PyObject* self)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // listAppendNew()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Config* cppResult = new rviz::Config(cppSelf->listAppendNew());
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Object::newObject((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_ConfigFunc_listChildAt(PyObject* self, PyObject* pyArg)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: listChildAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // listChildAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_listChildAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // listChildAt(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Config* cppResult = new rviz::Config(const_cast<const ::rviz::Config*>(cppSelf)->listChildAt(cppArg0));
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Object::newObject((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ConfigFunc_listChildAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Config.listChildAt", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_listLength(PyObject* self)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // listLength()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::rviz::Config*>(cppSelf)->listLength();
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

static PyObject* Sbk_rviz_ConfigFunc_mapGetBool(PyObject* self, PyObject* args)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "mapGetBool", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mapGetBool(QString,bool*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && PyBool_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // mapGetBool(QString,bool*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_mapGetBool_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mapGetBool(QString,bool*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Config*>(cppSelf)->mapGetBool(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ConfigFunc_mapGetBool_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Config.mapGetBool", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_mapGetChild(PyObject* self, PyObject* pyArg)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mapGetChild(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // mapGetChild(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_mapGetChild_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mapGetChild(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Config* cppResult = new rviz::Config(const_cast<const ::rviz::Config*>(cppSelf)->mapGetChild(cppArg0));
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Object::newObject((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ConfigFunc_mapGetChild_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Config.mapGetChild", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_mapGetFloat(PyObject* self, PyObject* args)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "mapGetFloat", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mapGetFloat(QString,float*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && PyFloat_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[1])))) {
        overloadId = 0; // mapGetFloat(QString,float*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_mapGetFloat_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        float* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mapGetFloat(QString,float*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Config*>(cppSelf)->mapGetFloat(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ConfigFunc_mapGetFloat_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Config.mapGetFloat", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_mapGetInt(PyObject* self, PyObject* args)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "mapGetInt", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mapGetInt(QString,int*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // mapGetInt(QString,int*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_mapGetInt_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mapGetInt(QString,int*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Config*>(cppSelf)->mapGetInt(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ConfigFunc_mapGetInt_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Config.mapGetInt", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_mapGetString(PyObject* self, PyObject* args)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "mapGetString", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mapGetString(QString,QString*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // mapGetString(QString,QString*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_mapGetString_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mapGetString(QString,QString*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Config*>(cppSelf)->mapGetString(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ConfigFunc_mapGetString_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QString", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Config.mapGetString", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_mapGetValue(PyObject* self, PyObject* args)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "mapGetValue", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mapGetValue(QString,QVariant*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // mapGetValue(QString,QVariant*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_mapGetValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mapGetValue(QString,QVariant*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::rviz::Config*>(cppSelf)->mapGetValue(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ConfigFunc_mapGetValue_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Config.mapGetValue", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_mapIterator(PyObject* self)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mapIterator()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Config::MapIterator* cppResult = new rviz::Config::MapIterator(const_cast<const ::rviz::Config*>(cppSelf)->mapIterator());
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Object::newObject((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_MAPITERATOR_IDX], cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_rviz_ConfigFunc_mapMakeChild(PyObject* self, PyObject* pyArg)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mapMakeChild(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // mapMakeChild(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_mapMakeChild_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mapMakeChild(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Config* cppResult = new rviz::Config(cppSelf->mapMakeChild(cppArg0));
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Object::newObject((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_ConfigFunc_mapMakeChild_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Config.mapMakeChild", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_mapSetValue(PyObject* self, PyObject* args)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "mapSetValue", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mapSetValue(QString,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // mapSetValue(QString,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_mapSetValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mapSetValue(QString,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->mapSetValue(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ConfigFunc_mapSetValue_TypeError:
        const char* overloads[] = {"unicode, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.Config.mapSetValue", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_setType(PyObject* self, PyObject* pyArg)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setType(rviz::Config::Type)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX]), (pyArg)))) {
        overloadId = 0; // setType(rviz::Config::Type)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_setType_TypeError;

    // Call function/method
    {
        ::rviz::Config::Type cppArg0 = ((::rviz::Config::Type)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setType(rviz::Config::Type)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ConfigFunc_setType_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config.Type", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Config.setType", overloads);
        return 0;
}

static PyObject* Sbk_rviz_ConfigFunc_setValue(PyObject* self, PyObject* pyArg)
{
    ::rviz::Config* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setValue(QVariant)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArg)))) {
        overloadId = 0; // setValue(QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_ConfigFunc_setValue_TypeError;

    // Call function/method
    {
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setValue(QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_ConfigFunc_setValue_TypeError:
        const char* overloads[] = {"QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "librviz_shiboken.Config.setValue", overloads);
        return 0;
}

static PyMethodDef Sbk_rviz_Config_methods[] = {
    {"copy", (PyCFunction)Sbk_rviz_ConfigFunc_copy, METH_O},
    {"getType", (PyCFunction)Sbk_rviz_ConfigFunc_getType, METH_NOARGS},
    {"getValue", (PyCFunction)Sbk_rviz_ConfigFunc_getValue, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_rviz_ConfigFunc_isValid, METH_NOARGS},
    {"listAppendNew", (PyCFunction)Sbk_rviz_ConfigFunc_listAppendNew, METH_NOARGS},
    {"listChildAt", (PyCFunction)Sbk_rviz_ConfigFunc_listChildAt, METH_O},
    {"listLength", (PyCFunction)Sbk_rviz_ConfigFunc_listLength, METH_NOARGS},
    {"mapGetBool", (PyCFunction)Sbk_rviz_ConfigFunc_mapGetBool, METH_VARARGS},
    {"mapGetChild", (PyCFunction)Sbk_rviz_ConfigFunc_mapGetChild, METH_O},
    {"mapGetFloat", (PyCFunction)Sbk_rviz_ConfigFunc_mapGetFloat, METH_VARARGS},
    {"mapGetInt", (PyCFunction)Sbk_rviz_ConfigFunc_mapGetInt, METH_VARARGS},
    {"mapGetString", (PyCFunction)Sbk_rviz_ConfigFunc_mapGetString, METH_VARARGS},
    {"mapGetValue", (PyCFunction)Sbk_rviz_ConfigFunc_mapGetValue, METH_VARARGS},
    {"mapIterator", (PyCFunction)Sbk_rviz_ConfigFunc_mapIterator, METH_NOARGS},
    {"mapMakeChild", (PyCFunction)Sbk_rviz_ConfigFunc_mapMakeChild, METH_O},
    {"mapSetValue", (PyCFunction)Sbk_rviz_ConfigFunc_mapSetValue, METH_VARARGS},
    {"setType", (PyCFunction)Sbk_rviz_ConfigFunc_setType, METH_O},
    {"setValue", (PyCFunction)Sbk_rviz_ConfigFunc_setValue, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_rviz_Config_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_Config_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_Config_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.Config",
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
    /*tp_traverse*/         Sbk_rviz_Config_traverse,
    /*tp_clear*/            Sbk_rviz_Config_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_Config_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_rviz_Config_Init,
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


// Type conversion functions.

// Python to C++ enum conversion.
static void rviz_Config_Type_PythonToCpp_rviz_Config_Type(PyObject* pyIn, void* cppOut) {
    *((::rviz::Config::Type*)cppOut) = (::rviz::Config::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_rviz_Config_Type_PythonToCpp_rviz_Config_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX]))
        return rviz_Config_Type_PythonToCpp_rviz_Config_Type;
    return 0;
}
static PyObject* rviz_Config_Type_CppToPython_rviz_Config_Type(const void* cppIn) {
    int castCppIn = *((::rviz::Config::Type*)cppIn);
    return Shiboken::Enum::newItem(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Config_PythonToCpp_Config_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_Config_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Config_PythonToCpp_Config_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_Config_Type))
        return Config_PythonToCpp_Config_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Config_PTR_CppToPython_Config(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::Config*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_Config_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_Config(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_Config_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "Config", "rviz::Config*",
        &Sbk_rviz_Config_Type, &Shiboken::callCppDestructor< ::rviz::Config >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_Config_Type,
        Config_PythonToCpp_Config_PTR,
        is_Config_PythonToCpp_Config_PTR_Convertible,
        Config_PTR_CppToPython_Config);

    Shiboken::Conversions::registerConverterName(converter, "rviz::Config");
    Shiboken::Conversions::registerConverterName(converter, "rviz::Config*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::Config&");
    Shiboken::Conversions::registerConverterName(converter, "Config");
    Shiboken::Conversions::registerConverterName(converter, "Config*");
    Shiboken::Conversions::registerConverterName(converter, "Config&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::Config).name());


    // Initialization of enums.

    // Initialization of enum 'Type'.
    Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_rviz_Config_Type,
        "Type",
        "librviz_shiboken.rviz.Config.Type",
        "rviz::Config::Type");
    if (!Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX],
        &Sbk_rviz_Config_Type, "Map", (long) rviz::Config::Map))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX],
        &Sbk_rviz_Config_Type, "List", (long) rviz::Config::List))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX],
        &Sbk_rviz_Config_Type, "Value", (long) rviz::Config::Value))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX],
        &Sbk_rviz_Config_Type, "Empty", (long) rviz::Config::Empty))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX],
        &Sbk_rviz_Config_Type, "Invalid", (long) rviz::Config::Invalid))
        return ;
    // Register converter for enum 'rviz::Config::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX],
            rviz_Config_Type_CppToPython_rviz_Config_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            rviz_Config_Type_PythonToCpp_rviz_Config_Type,
            is_rviz_Config_Type_PythonToCpp_rviz_Config_Type_Convertible);
        Shiboken::Enum::setTypeConverter(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "rviz::Config::Type");
        Shiboken::Conversions::registerConverterName(converter, "Config::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.


}
