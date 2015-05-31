
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_ogrelogging_wrapper.h"

// Extra includes

using namespace rviz;


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_rviz_OgreLogging_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::rviz::OgreLogging >()))
        return -1;

    ::rviz::OgreLogging* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // OgreLogging()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::rviz::OgreLogging();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::rviz::OgreLogging >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_rviz_OgreLoggingFunc_configureLogging(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // configureLogging()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::rviz::OgreLogging::configureLogging();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_OgreLoggingFunc_noLog(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // noLog()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::rviz::OgreLogging::noLog();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_OgreLoggingFunc_useLogFile(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.OgreLogging.useLogFile(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:useLogFile", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: useLogFile(QString)
    if (numArgs == 0) {
        overloadId = 0; // useLogFile(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // useLogFile(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_OgreLoggingFunc_useLogFile_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "filename");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.OgreLogging.useLogFile(): got multiple values for keyword argument 'filename'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_rviz_OgreLoggingFunc_useLogFile_TypeError;
            }
        }
        ::QString cppArg0 = "Ogre.log";
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // useLogFile(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::rviz::OgreLogging::useLogFile(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_OgreLoggingFunc_useLogFile_TypeError:
        const char* overloads[] = {"unicode = \"Ogre.log\"", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.OgreLogging.useLogFile", overloads);
        return 0;
}

static PyObject* Sbk_rviz_OgreLoggingFunc_useRosLog(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // useRosLog()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::rviz::OgreLogging::useRosLog();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_rviz_OgreLogging_methods[] = {
    {"configureLogging", (PyCFunction)Sbk_rviz_OgreLoggingFunc_configureLogging, METH_NOARGS|METH_STATIC},
    {"noLog", (PyCFunction)Sbk_rviz_OgreLoggingFunc_noLog, METH_NOARGS|METH_STATIC},
    {"useLogFile", (PyCFunction)Sbk_rviz_OgreLoggingFunc_useLogFile, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"useRosLog", (PyCFunction)Sbk_rviz_OgreLoggingFunc_useRosLog, METH_NOARGS|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_rviz_OgreLogging_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_OgreLogging_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_OgreLogging_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.OgreLogging",
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
    /*tp_traverse*/         Sbk_rviz_OgreLogging_traverse,
    /*tp_clear*/            Sbk_rviz_OgreLogging_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_OgreLogging_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_rviz_OgreLogging_Init,
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

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void OgreLogging_PythonToCpp_OgreLogging_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_OgreLogging_Type, pyIn, cppOut);
}
static PythonToCppFunc is_OgreLogging_PythonToCpp_OgreLogging_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_OgreLogging_Type))
        return OgreLogging_PythonToCpp_OgreLogging_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* OgreLogging_PTR_CppToPython_OgreLogging(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::OgreLogging*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_OgreLogging_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_OgreLogging(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_OGRELOGGING_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_OgreLogging_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "OgreLogging", "rviz::OgreLogging*",
        &Sbk_rviz_OgreLogging_Type, &Shiboken::callCppDestructor< ::rviz::OgreLogging >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_OgreLogging_Type,
        OgreLogging_PythonToCpp_OgreLogging_PTR,
        is_OgreLogging_PythonToCpp_OgreLogging_PTR_Convertible,
        OgreLogging_PTR_CppToPython_OgreLogging);

    Shiboken::Conversions::registerConverterName(converter, "rviz::OgreLogging");
    Shiboken::Conversions::registerConverterName(converter, "rviz::OgreLogging*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::OgreLogging&");
    Shiboken::Conversions::registerConverterName(converter, "OgreLogging");
    Shiboken::Conversions::registerConverterName(converter, "OgreLogging*");
    Shiboken::Conversions::registerConverterName(converter, "OgreLogging&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::OgreLogging).name());



}
