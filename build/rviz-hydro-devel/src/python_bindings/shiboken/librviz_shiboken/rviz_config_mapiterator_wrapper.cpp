
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_config_mapiterator_wrapper.h"

// Extra includes
#include <config.h>

using namespace rviz;


// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_rviz_Config_MapIteratorFunc_advance(PyObject* self)
{
    ::rviz::Config::MapIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config::MapIterator*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_MAPITERATOR_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // advance()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->advance();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_rviz_Config_MapIteratorFunc_currentChild(PyObject* self)
{
    ::rviz::Config::MapIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config::MapIterator*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_MAPITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentChild()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            rviz::Config* cppResult = new rviz::Config(cppSelf->currentChild());
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

static PyObject* Sbk_rviz_Config_MapIteratorFunc_currentKey(PyObject* self)
{
    ::rviz::Config::MapIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config::MapIterator*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_MAPITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentKey()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->currentKey();
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

static PyObject* Sbk_rviz_Config_MapIteratorFunc_isValid(PyObject* self)
{
    ::rviz::Config::MapIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config::MapIterator*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_MAPITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->isValid();
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

static PyObject* Sbk_rviz_Config_MapIteratorFunc_start(PyObject* self)
{
    ::rviz::Config::MapIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::rviz::Config::MapIterator*)Shiboken::Conversions::cppPointer(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_MAPITERATOR_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // start()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->start();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_rviz_Config_MapIterator_methods[] = {
    {"advance", (PyCFunction)Sbk_rviz_Config_MapIteratorFunc_advance, METH_NOARGS},
    {"currentChild", (PyCFunction)Sbk_rviz_Config_MapIteratorFunc_currentChild, METH_NOARGS},
    {"currentKey", (PyCFunction)Sbk_rviz_Config_MapIteratorFunc_currentKey, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_rviz_Config_MapIteratorFunc_isValid, METH_NOARGS},
    {"start", (PyCFunction)Sbk_rviz_Config_MapIteratorFunc_start, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_rviz_Config_MapIterator_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_Config_MapIterator_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_Config_MapIterator_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz.Config.MapIterator",
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
    /*tp_traverse*/         Sbk_rviz_Config_MapIterator_traverse,
    /*tp_clear*/            Sbk_rviz_Config_MapIterator_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_Config_MapIterator_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
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
static void MapIterator_PythonToCpp_MapIterator_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_rviz_Config_MapIterator_Type, pyIn, cppOut);
}
static PythonToCppFunc is_MapIterator_PythonToCpp_MapIterator_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_rviz_Config_MapIterator_Type))
        return MapIterator_PythonToCpp_MapIterator_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* MapIterator_PTR_CppToPython_MapIterator(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::rviz::Config::MapIterator*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_rviz_Config_MapIterator_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_rviz_Config_MapIterator(PyObject* enclosingClass)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_MAPITERATOR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_Config_MapIterator_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "MapIterator", "rviz::Config::MapIterator*",
        &Sbk_rviz_Config_MapIterator_Type, &Shiboken::callCppDestructor< ::rviz::Config::MapIterator >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_rviz_Config_MapIterator_Type,
        MapIterator_PythonToCpp_MapIterator_PTR,
        is_MapIterator_PythonToCpp_MapIterator_PTR_Convertible,
        MapIterator_PTR_CppToPython_MapIterator);

    Shiboken::Conversions::registerConverterName(converter, "rviz::Config::MapIterator");
    Shiboken::Conversions::registerConverterName(converter, "rviz::Config::MapIterator*");
    Shiboken::Conversions::registerConverterName(converter, "rviz::Config::MapIterator&");
    Shiboken::Conversions::registerConverterName(converter, "Config::MapIterator");
    Shiboken::Conversions::registerConverterName(converter, "Config::MapIterator*");
    Shiboken::Conversions::registerConverterName(converter, "Config::MapIterator&");
    Shiboken::Conversions::registerConverterName(converter, "MapIterator");
    Shiboken::Conversions::registerConverterName(converter, "MapIterator*");
    Shiboken::Conversions::registerConverterName(converter, "MapIterator&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::rviz::Config::MapIterator).name());



}
