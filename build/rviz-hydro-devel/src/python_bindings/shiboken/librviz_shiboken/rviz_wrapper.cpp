
// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include "librviz_shiboken_python.h"

#include "rviz_wrapper.h"
#include "rviz_yamlconfigwriter_wrapper.h"
#include "rviz_yamlconfigreader_wrapper.h"
#include "rviz_toolmanager_wrapper.h"
#include "rviz_tool_wrapper.h"
#include "rviz_viewmanager_wrapper.h"
#include "rviz_paneldockwidget_wrapper.h"
#include "rviz_ogrelogging_wrapper.h"
#include "rviz_property_wrapper.h"
#include "rviz_viewcontroller_wrapper.h"
#include "rviz_boolproperty_wrapper.h"
#include "rviz_display_wrapper.h"
#include "rviz_displaygroup_wrapper.h"
#include "rviz_visualizationmanager_wrapper.h"
#include "rviz_visualizationframe_wrapper.h"
#include "rviz_config_wrapper.h"

// Extra includes
#include <qcursor.h>
#include <qpixmap.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_rvizFunc_getDefaultCursor(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.rviz.getDefaultCursor(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:getDefaultCursor", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: getDefaultCursor(bool)
    if (numArgs == 0) {
        overloadId = 0; // getDefaultCursor(bool)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 0; // getDefaultCursor(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rvizFunc_getDefaultCursor_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "fill_cache");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.rviz.getDefaultCursor(): got multiple values for keyword argument 'fill_cache'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0]))))
                    goto Sbk_rvizFunc_getDefaultCursor_TypeError;
            }
        }
        bool cppArg0 = true;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getDefaultCursor(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QCursor cppResult = ::rviz::getDefaultCursor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rvizFunc_getDefaultCursor_TypeError:
        const char* overloads[] = {"bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.rviz.getDefaultCursor", overloads);
        return 0;
}

static PyObject* Sbk_rvizFunc_loadPixmap(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.rviz.loadPixmap(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.rviz.loadPixmap(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:loadPixmap", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: loadPixmap(QString,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // loadPixmap(QString,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // loadPixmap(QString,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rvizFunc_loadPixmap_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "fill_cache");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "librviz_shiboken.rviz.loadPixmap(): got multiple values for keyword argument 'fill_cache'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_rvizFunc_loadPixmap_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // loadPixmap(QString,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = ::rviz::loadPixmap(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rvizFunc_loadPixmap_TypeError:
        const char* overloads[] = {"unicode, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.rviz.loadPixmap", overloads);
        return 0;
}

static PyObject* Sbk_rvizFunc_makeIconCursor(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.rviz.makeIconCursor(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "librviz_shiboken.rviz.makeIconCursor(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:makeIconCursor", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: makeIconCursor(QPixmap,QString,bool)
    // 1: makeIconCursor(QString,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // makeIconCursor(QString,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 1; // makeIconCursor(QString,bool)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // makeIconCursor(QPixmap,QString,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // makeIconCursor(QPixmap,QString,bool)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))) {
                overloadId = 0; // makeIconCursor(QPixmap,QString,bool)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_rvizFunc_makeIconCursor_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // makeIconCursor(QPixmap icon, QString cache_key, bool fill_cache)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "cache_key");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "librviz_shiboken.rviz.makeIconCursor(): got multiple values for keyword argument 'cache_key'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_rvizFunc_makeIconCursor_TypeError;
                }
                value = PyDict_GetItemString(kwds, "fill_cache");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "librviz_shiboken.rviz.makeIconCursor(): got multiple values for keyword argument 'fill_cache'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2]))))
                        goto Sbk_rvizFunc_makeIconCursor_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPixmap cppArg0 = ::QPixmap();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = "";
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            bool cppArg2 = true;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // makeIconCursor(QPixmap,QString,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QCursor cppResult = ::rviz::makeIconCursor(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], &cppResult);
            }
            break;
        }
        case 1: // makeIconCursor(QString icon_url, bool fill_cache)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "fill_cache");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "librviz_shiboken.rviz.makeIconCursor(): got multiple values for keyword argument 'fill_cache'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                        goto Sbk_rvizFunc_makeIconCursor_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1 = true;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // makeIconCursor(QString,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QCursor cppResult = ::rviz::makeIconCursor(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_rvizFunc_makeIconCursor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmap, unicode = \"\", bool = true", "unicode, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "librviz_shiboken.rviz.makeIconCursor", overloads);
        return 0;
}

static PyMethodDef Sbk_rviz_methods[] = {
    {"getDefaultCursor", (PyCFunction)Sbk_rvizFunc_getDefaultCursor, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"loadPixmap", (PyCFunction)Sbk_rvizFunc_loadPixmap, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"makeIconCursor", (PyCFunction)Sbk_rvizFunc_makeIconCursor, METH_VARARGS|METH_KEYWORDS|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_rviz_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_rviz_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_rviz_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "librviz_shiboken.rviz",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          0,
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
    /*tp_traverse*/         Sbk_rviz_traverse,
    /*tp_clear*/            Sbk_rviz_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_rviz_methods,
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

void init_rviz(PyObject* module)
{
    Sbklibrviz_shibokenTypes[SBK_RVIZ_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_rviz_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "rviz", "rviz",
        &Sbk_rviz_Type)) {
        return;
    }



}
