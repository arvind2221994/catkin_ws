
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_yamlconfigwriter_wrapper.h"

// Extra includes
#include <config.h>

using namespace rviz;


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_rviz_YamlConfigWriter_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::rviz::YamlConfigWriter >()))
        return -1;

    ::rviz::YamlConfigWriter* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // YamlConfigWriter()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::rviz::YamlConfigWriter();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::rviz::YamlConfigWriter >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_rviz_YamlConfigWriterFunc_error(PyObject* self)
{
    ::rviz::YamlConfigWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::YamlConfigWriter*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_YAMLCONFIGWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->error();
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

static PyObject* Sbk_rviz_YamlConfigWriterFunc_errorMessage(PyObject* self)
{
    ::rviz::YamlConfigWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::YamlConfigWriter*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_YAMLCONFIGWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorMessage()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->errorMessage();
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

static PyObject* Sbk_rviz_YamlConfigWriterFunc_writeFile(PyObject* self, PyObject* args)
{
    ::rviz::YamlConfigWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::YamlConfigWriter*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_YAMLCONFIGWRITER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "writeFile", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: writeFile(rviz::Config,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // writeFile(rviz::Config,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_YamlConfigWriterFunc_writeFile_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // writeFile(rviz::Config,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->writeFile(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_rviz_YamlConfigWriterFunc_writeFile_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.YamlConfigWriter.writeFile", overloads);
        return 0;
}

static PyObject* Sbk_rviz_YamlConfigWriterFunc_writeString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::rviz::YamlConfigWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::YamlConfigWriter*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_YAMLCONFIGWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.YamlConfigWriter.writeString(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.YamlConfigWriter.writeString(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:writeString", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: writeString(rviz::Config,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // writeString(rviz::Config,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // writeString(rviz::Config,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rviz_YamlConfigWriterFunc_writeString_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "filename");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.YamlConfigWriter.writeString(): got multiple values for keyword argument 'filename'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_rviz_YamlConfigWriterFunc_writeString_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::rviz::Config* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = "data string";
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // writeString(rviz::Config,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->writeString(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rviz_YamlConfigWriterFunc_writeString_TypeError:
        const char* overloads[] = {"librviz_shiboken.rviz::Config, unicode = \"data string\"", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.YamlConfigWriter.writeString", overloads);
        return 0;
}

static PyMethodDef Sbk_rviz_YamlConfigWriter_methods[] = {
    {"error", (PyCFunction)Sbk_rviz_YamlConfigWriterFunc_error, METH_NOARGS},
    {"errorMessage", (PyCFunction)Sbk_rviz_YamlConfigWriterFunc_errorMessage, METH_NOARGS},
    {"writeFile", (PyCFunction)Sbk_rviz_YamlConfigWriterFunc_writeFile, METH_VARARGS},
    {"writeString", (PyCFunction)Sbk_rviz_YamlConfigWriterFunc_writeString, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_rviz_YamlConfigWriter_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_YamlConfigWriter_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_YamlConfigWriter_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.YamlConfigWriter",
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
    /*tp_traverse*/         Sbk_rviz_YamlConfigWriter_traverse,
    /*tp_clear*/            Sbk_rviz_YamlConfigWriter_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_YamlConfigWriter_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_rviz_YamlConfigWriter_Init,
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
static void YamlConfigWriter_PythonToCpp_YamlConfigWriter_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_YamlConfigWriter_Type, pyIn, cppOut);
}
static PythonToCppFunc is_YamlConfigWriter_PythonToCpp_YamlConfigWriter_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_YamlConfigWriter_Type))
        return YamlConfigWriter_PythonToCpp_YamlConfigWriter_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* YamlConfigWriter_PTR_CppToPython_YamlConfigWriter(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::YamlConfigWriter*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_YamlConfigWriter_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_YamlConfigWriter(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_YAMLCONFIGWRITER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_YamlConfigWriter_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "YamlConfigWriter", "rviz::YamlConfigWriter*",
        &Sbk_rviz_YamlConfigWriter_Type, &Shiboken::callCppDestructor< ::rviz::YamlConfigWriter >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_YamlConfigWriter_Type,
        YamlConfigWriter_PythonToCpp_YamlConfigWriter_PTR,
        is_YamlConfigWriter_PythonToCpp_YamlConfigWriter_PTR_Convertible,
        YamlConfigWriter_PTR_CppToPython_YamlConfigWriter);

    Shiboken::Conversions::registerConverterName(converter, "rviz::YamlConfigWriter");
    Shiboken::Conversions::registerConverterName(converter, "rviz::YamlConfigWriter*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::YamlConfigWriter&");
    Shiboken::Conversions::registerConverterName(converter, "YamlConfigWriter");
    Shiboken::Conversions::registerConverterName(converter, "YamlConfigWriter*");
    Shiboken::Conversions::registerConverterName(converter, "YamlConfigWriter&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::YamlConfigWriter).name());



}
