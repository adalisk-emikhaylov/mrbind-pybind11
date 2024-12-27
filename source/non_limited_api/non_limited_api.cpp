#ifdef Py_LIMITED_API
#undef Py_LIMITED_API
#endif

#define PYBIND11_NONLIMITEDAPI_API_IMPL PYBIND11_NONLIMITEDAPI_EXPORT

#include "pybind11/pybind11.h"
#include "pybind11/embed.h"

using namespace pybind11;
using namespace pybind11::detail;

// -------- SIMPLE WRAPPERS:

using pybind11::non_limited_api::PyStatus_;
using pybind11::non_limited_api::Py_buffer_;

void        pybind11::non_limited_api::pybind11NLA_PyBuffer_Release         (Py_buffer_ *buf)                                  {::PyBuffer_Release((Py_buffer *)buf);}
void        pybind11::non_limited_api::pybind11NLA_PyBuffer_delete          (Py_buffer_ *buf)                                  {delete (Py_buffer *)buf;}
int         pybind11::non_limited_api::pybind11NLA_PyGILState_Check         ()                                                 {return ::PyGILState_Check();}
PyObject ** pybind11::non_limited_api::pybind11NLA_PySequence_Fast_ITEMS_   (PyObject *obj)                                    {return PySequence_Fast_ITEMS(obj);}
char *      pybind11::non_limited_api::pybind11NLA_PyByteArray_AS_STRING_   (PyObject *obj)                                    {return PyByteArray_AS_STRING(obj);}
ssize_t     pybind11::non_limited_api::pybind11NLA_PyByteArray_GET_SIZE_    (PyObject *obj)                                    {return PyByteArray_GET_SIZE(obj);}
ssize_t     pybind11::non_limited_api::pybind11NLA_PyTuple_GET_SIZE_        (PyObject *obj)                                    {return PyTuple_GET_SIZE(obj);}
PyObject *  pybind11::non_limited_api::pybind11NLA_PyTuple_GET_ITEM_        (PyObject *obj, ssize_t i)                         {return PyTuple_GET_ITEM(obj, i);}
void        pybind11::non_limited_api::pybind11NLA_PyTuple_SET_ITEM_        (PyObject *obj, ssize_t i, PyObject *value)        {PyTuple_SET_ITEM(obj, i, value);}
ssize_t     pybind11::non_limited_api::pybind11NLA_PyList_GET_SIZE_         (PyObject *obj)                                    {return PyList_GET_SIZE(obj);}
void        pybind11::non_limited_api::pybind11NLA_PyList_SET_ITEM_         (PyObject *obj, ssize_t i, PyObject *value)        {PyList_SET_ITEM(obj, i, value);}
PyObject *  pybind11::non_limited_api::pybind11NLA_PyStaticMethod_New       (PyObject *obj)                                    {return ::PyStaticMethod_New(obj);}
int         pybind11::non_limited_api::pybind11NLA_PyObject_CheckBuffer_    (PyObject *obj)                                    {return PyObject_CheckBuffer(obj);}
ssize_t     pybind11::non_limited_api::pybind11NLA_PyObject_LengthHint      (PyObject *obj, ssize_t i)                         {return ::PyObject_LengthHint(obj, i);}
PyObject ** pybind11::non_limited_api::pybind11NLA__PyObject_GetDictPtr     (PyObject *obj)                                    {return ::_PyObject_GetDictPtr(obj);}
PyObject *  pybind11::non_limited_api::pybind11NLA_PyCFunction_GET_SELF_    (PyObject *obj)                                    {return PyCFunction_GET_SELF(obj);}
Py_complex  pybind11::non_limited_api::pybind11NLA_PyComplex_AsCComplex     (PyObject *obj)                                    {return ::PyComplex_AsCComplex(obj);}
const char *pybind11::non_limited_api::pybind11NLA_PyUnicode_AsUTF8AndSize  (PyObject *unicode, ssize_t *size)                 {return ::PyUnicode_AsUTF8AndSize(unicode, size);}
PyObject *  pybind11::non_limited_api::pybind11NLA_PyRun_String_            (const char *str, int s, PyObject *g, PyObject *l) {return PyRun_String(str, s, g, l);}
FILE *      pybind11::non_limited_api::pybind11NLA__Py_fopen_obj            (PyObject *path, const char *mode)                 {return ::_Py_fopen_obj(path, mode);}
PyObject *  pybind11::non_limited_api::pybind11NLA_PyRun_FileEx_            (FILE *fp, const char *p, int s, PyObject *g, PyObject *l, int c) {return PyRun_FileEx(fp, p, s, g, l, c);}
void        pybind11::non_limited_api::pybind11NLA_PyMem_RawFree            (void *ptr)                                        {return ::PyMem_RawFree(ptr);}
PyConfig *  pybind11::non_limited_api::pybind11NLA_PyConfig_new             ()                                                 {return new PyConfig;}
void        pybind11::non_limited_api::pybind11NLA_PyConfig_delete          (PyConfig *c)                                      {delete c;}
void        pybind11::non_limited_api::pybind11NLA_PyConfig_InitPythonConfig(PyConfig *c)                                      {::PyConfig_InitPythonConfig(c);}
void        pybind11::non_limited_api::pybind11NLA_PyConfig_Clear           (PyConfig *c)                                      {::PyConfig_Clear(c);}
void        pybind11::non_limited_api::pybind11NLA_PyConfig_set_site_import (PyConfig *c, int value)                           {c->site_import = value;}
void        pybind11::non_limited_api::pybind11NLA_PyConfig_set_parse_argv  (PyConfig *c, int value)                           {c->parse_argv = value;}
void        pybind11::non_limited_api::pybind11NLA_PyConfig_set_install_signal_handlers(PyConfig *c, int value)                {c->install_signal_handlers = value;}
void        pybind11::non_limited_api::pybind11NLA_PyConfig_set_isolated    (PyConfig *c, int value)                           {c->isolated = value;}
wchar_t **  pybind11::non_limited_api::pybind11NLA_PyConfig_home_ptr        (PyConfig *c)                                      {return &c->home;}
void        pybind11::non_limited_api::pybind11NLA_PyStatus_delete          (PyStatus_ *ptr)                                   {delete (PyStatus *)ptr;}
PyStatus_ * pybind11::non_limited_api::pybind11NLA_PyConfig_SetString       (PyConfig *config, wchar_t **config_str, const wchar_t *str) {return (PyStatus_ *)new PyStatus(::PyConfig_SetString(config, config_str, str));}
PyStatus_ * pybind11::non_limited_api::pybind11NLA_PyConfig_SetBytesArgv    (PyConfig *config, ssize_t argc, char *const *argv){return (PyStatus_ *)new PyStatus(::PyConfig_SetBytesArgv(config, argc, argv));}
int         pybind11::non_limited_api::pybind11NLA_PyStatus_Exception       (const PyStatus_ *err)                             {return ::PyStatus_Exception(*(PyStatus *)err);}
const char *pybind11::non_limited_api::pybind11NLA_PyStatus_get_err_msg     (const PyStatus_ *s)                               {return ((PyStatus *)s)->err_msg;}
PyStatus_ * pybind11::non_limited_api::pybind11NLA_Py_InitializeFromConfig  (const PyConfig *config)                           {return (PyStatus_ *)new PyStatus(::Py_InitializeFromConfig(config));}
int         pybind11::non_limited_api::pybind11NLA_PyGen_Check_             (PyObject *obj)                                    {return PyGen_Check(obj);}

// -------- STATIC FUNCTIONS:

static void pybind11_object_dealloc(PyObject *self) {
    auto *type = Py_TYPE(self);

    // If this is a GC tracked object, untrack it first
    // Note that the track call is implicitly done by the
    // default tp_alloc, which we never override.
    if (PyType_HasFeature(type, Py_TPFLAGS_HAVE_GC) != 0) {
        PyObject_GC_UnTrack(self);
    }

    clear_instance(self);

    type->tp_free(self);

    // This was not needed before Python 3.8 (Python issue 35810)
    // https://github.com/pybind/pybind11/issues/1946
    Py_DECREF(type);
}

static PyObject *make_object_base_type(PyTypeObject *metaclass) {
    constexpr auto *name = "pybind11_object";
    auto name_obj = reinterpret_steal<object>(PYBIND11_FROM_STRING(name));

    /* Danger zone: from now (and until PyType_Ready), make sure to
       issue no Python C API calls which could potentially invoke the
       garbage collector (the GC will call type_traverse(), which will in
       turn find the newly constructed type in an invalid state) */
    auto *heap_type = (PyHeapTypeObject *) metaclass->tp_alloc(metaclass, 0);
    if (!heap_type) {
        pybind11_fail("make_object_base_type(): error allocating type!");
    }

    heap_type->ht_name = name_obj.inc_ref().ptr();
#ifdef PYBIND11_BUILTIN_QUALNAME
    heap_type->ht_qualname = name_obj.inc_ref().ptr();
#endif

    auto *type = &heap_type->ht_type;
    type->tp_name = name;
    type->tp_base = type_incref(&PyBaseObject_Type);
    type->tp_basicsize = static_cast<ssize_t>(sizeof(instance));
    type->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HEAPTYPE;

    type->tp_new = pybind11_object_new;
    type->tp_init = pybind11_object_init;
    type->tp_dealloc = pybind11_object_dealloc;

    /* Support weak references (needed for the keep_alive feature) */
    type->tp_weaklistoffset = offsetof(instance, weakrefs);

    if (PyType_Ready(type) < 0) {
        pybind11_fail("PyType_Ready failed in make_object_base_type(): " + error_string());
    }

    setattr((PyObject *) type, "__module__", str("pybind11_builtins"));
    PYBIND11_SET_OLDPY_QUALNAME(type, name_obj);

    assert(!PyType_HasFeature(type, Py_TPFLAGS_HAVE_GC));
    return (PyObject *) heap_type;
}

/// Cleanup the type-info for a pybind11-registered type.
static void pybind11_meta_dealloc(PyObject *obj) {
    with_internals([obj](internals &internals) {
        auto *type = (PyTypeObject *) obj;

        // A pybind11-registered type will:
        // 1) be found in internals.registered_types_py
        // 2) have exactly one associated `detail::type_info`
        auto found_type = internals.registered_types_py.find(type);
        if (found_type != internals.registered_types_py.end() && found_type->second.size() == 1
            && found_type->second[0]->type == type) {

            auto *tinfo = found_type->second[0];
            auto tindex = std::type_index(*tinfo->cpptype);
            internals.direct_conversions.erase(tindex);

            if (tinfo->module_local) {
                get_local_internals().registered_types_cpp.erase(tindex);
            } else {
                internals.registered_types_cpp.erase(tindex);
            }
            internals.registered_types_py.erase(tinfo->type);

            // Actually just `std::erase_if`, but that's only available in C++20
            auto &cache = internals.inactive_override_cache;
            for (auto it = cache.begin(), last = cache.end(); it != last;) {
                if (it->first == (PyObject *) tinfo->type) {
                    it = cache.erase(it);
                } else {
                    ++it;
                }
            }

            delete tinfo;
        }
    });

    PyType_Type.tp_dealloc(obj);
}

/// metaclass `__call__` function that is used to create all pybind11 objects.
static PyObject *pybind11_meta_call(PyObject *type, PyObject *args, PyObject *kwargs) {
    // use the default metaclass call to create/initialize the object
    PyObject *self = PyType_Type.tp_call(type, args, kwargs);
    if (self == nullptr) {
        return nullptr;
    }

    // Ensure that the base __init__ function(s) were called
    values_and_holders vhs(self);
    for (const auto &vh : vhs) {
        if (!vh.holder_constructed() && !vhs.is_redundant_value_and_holder(vh)) {
            PyErr_Format(PyExc_TypeError,
                         "%.200s.__init__() must be called when overriding __init__",
                         get_fully_qualified_tp_name(vh.type->type).c_str());
            Py_DECREF(self);
            return nullptr;
        }
    }

    return self;
}

/** Types with static properties need to handle `Type.static_prop = x` in a specific way.
    By default, Python replaces the `static_property` itself, but for wrapped C++ types
    we need to call `static_property.__set__()` in order to propagate the new value to
    the underlying C++ data structure. */
static int pybind11_meta_setattro(PyObject *obj, PyObject *name, PyObject *value) {
    // Use `_PyType_Lookup()` instead of `PyObject_GetAttr()` in order to get the raw
    // descriptor (`property`) instead of calling `tp_descr_get` (`property.__get__()`).
    PyObject *descr = _PyType_Lookup((PyTypeObject *) obj, name);

    // The following assignment combinations are possible:
    //   1. `Type.static_prop = value`             --> descr_set: `Type.static_prop.__set__(value)`
    //   2. `Type.static_prop = other_static_prop` --> setattro:  replace existing `static_prop`
    //   3. `Type.regular_attribute = value`       --> setattro:  regular attribute assignment
    auto *const static_prop = (PyObject *) get_internals().static_property_type;
    const auto call_descr_set = (descr != nullptr) && (value != nullptr)
                                && (PyObject_IsInstance(descr, static_prop) != 0)
                                && (PyObject_IsInstance(value, static_prop) == 0);
    if (call_descr_set) {
        // Call `static_property.__set__()` instead of replacing the `static_property`.
#if !defined(PYPY_VERSION)
        return Py_TYPE(descr)->tp_descr_set(descr, obj, value);
#else
        if (PyObject *result = PyObject_CallMethod(descr, "__set__", "OO", obj, value)) {
            Py_DECREF(result);
            return 0;
        } else {
            return -1;
        }
#endif
    } else {
        // Replace existing attribute.
        return PyType_Type.tp_setattro(obj, name, value);
    }
}

/**
 * Python 3's PyInstanceMethod_Type hides itself via its tp_descr_get, which prevents aliasing
 * methods via cls.attr("m2") = cls.attr("m1"): instead the tp_descr_get returns a plain function,
 * when called on a class, or a PyMethod, when called on an instance.  Override that behaviour here
 * to do a special case bypass for PyInstanceMethod_Types.
 */
static PyObject *pybind11_meta_getattro(PyObject *obj, PyObject *name) {
    PyObject *descr = _PyType_Lookup((PyTypeObject *) obj, name);
    if (descr && PyInstanceMethod_Check(descr)) {
        Py_INCREF(descr);
        return descr;
    }
    return PyType_Type.tp_getattro(obj, name);
}


/** This metaclass is assigned by default to all pybind11 types and is required in order
    for static properties to function correctly. Users may override this using `py::metaclass`.
    Return value: New reference. */
static PyTypeObject *make_default_metaclass() {
    constexpr auto *name = "pybind11_type";
    auto name_obj = reinterpret_steal<object>(PYBIND11_FROM_STRING(name));

    /* Danger zone: from now (and until PyType_Ready), make sure to
       issue no Python C API calls which could potentially invoke the
       garbage collector (the GC will call type_traverse(), which will in
       turn find the newly constructed type in an invalid state) */
    auto *heap_type = (PyHeapTypeObject *) PyType_Type.tp_alloc(&PyType_Type, 0);
    if (!heap_type) {
        pybind11_fail("make_default_metaclass(): error allocating metaclass!");
    }

    heap_type->ht_name = name_obj.inc_ref().ptr();
#ifdef PYBIND11_BUILTIN_QUALNAME
    heap_type->ht_qualname = name_obj.inc_ref().ptr();
#endif

    auto *type = &heap_type->ht_type;
    type->tp_name = name;
    type->tp_base = type_incref(&PyType_Type);
    type->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HEAPTYPE;

    type->tp_call = pybind11_meta_call;

    type->tp_setattro = pybind11_meta_setattro;
    type->tp_getattro = pybind11_meta_getattro;

    type->tp_dealloc = pybind11_meta_dealloc;

    if (PyType_Ready(type) < 0) {
        pybind11_fail("make_default_metaclass(): failure in PyType_Ready()!");
    }

    setattr((PyObject *) type, "__module__", str("pybind11_builtins"));
    PYBIND11_SET_OLDPY_QUALNAME(type, name_obj);

    return type;
}

#if !defined(PYPY_VERSION)

static PyObject *pybind11_static_get(PyObject *self, PyObject * /*ob*/, PyObject *cls) {
    return PyProperty_Type.tp_descr_get(self, cls, cls);
}

static int pybind11_static_set(PyObject *self, PyObject *obj, PyObject *value) {
    PyObject *cls = PyType_Check(obj) ? obj : (PyObject *) Py_TYPE(obj);
    return PyProperty_Type.tp_descr_set(self, cls, value);
}

/// Give instances of this type a `__dict__` and opt into garbage collection.
static void enable_dynamic_attributes(PyHeapTypeObject *heap_type) {
    auto *type = &heap_type->ht_type;
    type->tp_flags |= Py_TPFLAGS_HAVE_GC;
#if PY_VERSION_HEX < 0x030B0000
    type->tp_dictoffset = type->tp_basicsize;           // place dict at the end
    type->tp_basicsize += (ssize_t) sizeof(PyObject *); // and allocate enough space for it
#else
    type->tp_flags |= Py_TPFLAGS_MANAGED_DICT;
#endif
    type->tp_traverse = pybind11_traverse;
    type->tp_clear = pybind11_clear;

    static PyGetSetDef getset[]
        = {{"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict, nullptr, nullptr},
           {nullptr, nullptr, nullptr, nullptr, nullptr}};
    type->tp_getset = getset;
}

/** A `static_property` is the same as a `property` but the `__get__()` and `__set__()`
    methods are modified to always use the object type instead of a concrete instance.
    Return value: New reference. */
static PyTypeObject *make_static_property_type() {
    constexpr auto *name = "pybind11_static_property";
    auto name_obj = reinterpret_steal<object>(PYBIND11_FROM_STRING(name));

    /* Danger zone: from now (and until PyType_Ready), make sure to
       issue no Python C API calls which could potentially invoke the
       garbage collector (the GC will call type_traverse(), which will in
       turn find the newly constructed type in an invalid state) */
    auto *heap_type = (PyHeapTypeObject *) PyType_Type.tp_alloc(&PyType_Type, 0);
    if (!heap_type) {
        pybind11_fail("make_static_property_type(): error allocating type!");
    }

    heap_type->ht_name = name_obj.inc_ref().ptr();
#    ifdef PYBIND11_BUILTIN_QUALNAME
    heap_type->ht_qualname = name_obj.inc_ref().ptr();
#    endif

    auto *type = &heap_type->ht_type;
    type->tp_name = name;
    type->tp_base = type_incref(&PyProperty_Type);
    type->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HEAPTYPE;
    type->tp_descr_get = pybind11_static_get;
    type->tp_descr_set = pybind11_static_set;

#    if PY_VERSION_HEX >= 0x030C0000
    // Since Python-3.12 property-derived types are required to
    // have dynamic attributes (to set `__doc__`)
    enable_dynamic_attributes(heap_type);
#    endif

    if (PyType_Ready(type) < 0) {
        pybind11_fail("make_static_property_type(): failure in PyType_Ready()!");
    }

    setattr((PyObject *) type, "__module__", str("pybind11_builtins"));
    PYBIND11_SET_OLDPY_QUALNAME(type, name_obj);

    return type;
}

#else // PYPY

static PyTypeObject *make_static_property_type() {
    auto d = dict();
    PyObject *result = PyRun_String(R"(\
class pybind11_static_property(property):
    def __get__(self, obj, cls):
        return property.__get__(self, cls, cls)

    def __set__(self, obj, value):
        cls = obj if isinstance(obj, type) else type(obj)
        property.__set__(self, cls, value)
)",
                                    Py_file_input,
                                    d.ptr(),
                                    d.ptr());
    if (result == nullptr)
        throw error_already_set();
    Py_DECREF(result);
    return (PyTypeObject *) d["pybind11_static_property"].cast<object>().release().ptr();
}

#endif // PYPY

static PyThreadState *get_thread_state_unchecked() {
#if defined(PYPY_VERSION) || defined(GRAALVM_PYTHON)
    return PyThreadState_GET();
#elif PY_VERSION_HEX < 0x030D0000
    return _PyThreadState_UncheckedGet();
#else
    return PyThreadState_GetUnchecked();
#endif
}

static int pybind11_getbuffer(PyObject *obj, Py_buffer *view, int flags) {
    // Look for a `get_buffer` implementation in this type's info or any bases (following MRO).
    type_info *tinfo = nullptr;
    for (auto type : reinterpret_borrow<tuple>(Py_TYPE(obj)->tp_mro)) {
        tinfo = get_type_info((PyTypeObject *) type.ptr());
        if (tinfo && tinfo->get_buffer) {
            break;
        }
    }
    if (view == nullptr || !tinfo || !tinfo->get_buffer) {
        if (view) {
            view->obj = nullptr;
        }
        set_error(PyExc_BufferError, "pybind11_getbuffer(): Internal error");
        return -1;
    }
    std::memset(view, 0, sizeof(Py_buffer));
    std::unique_ptr<buffer_info> info = nullptr;
    try {
        info.reset(tinfo->get_buffer(obj, tinfo->get_buffer_data));
    } catch (...) {
        try_translate_exceptions();
        raise_from(PyExc_BufferError, "Error getting buffer");
        return -1;
    }
    if (info == nullptr) {
        pybind11_fail("FATAL UNEXPECTED SITUATION: tinfo->get_buffer() returned nullptr.");
    }

    if ((flags & PyBUF_WRITABLE) == PyBUF_WRITABLE && info->readonly) {
        // view->obj = nullptr;  // Was just memset to 0, so not necessary
        set_error(PyExc_BufferError, "Writable buffer requested for readonly storage");
        return -1;
    }

    // Fill in all the information, and then downgrade as requested by the caller, or raise an
    // error if that's not possible.
    view->itemsize = info->itemsize;
    view->len = view->itemsize;
    for (auto s : info->shape) {
        view->len *= s;
    }
    view->ndim = static_cast<int>(info->ndim);
    view->shape = info->shape.data();
    view->strides = info->strides.data();
    view->readonly = static_cast<int>(info->readonly);
    if ((flags & PyBUF_FORMAT) == PyBUF_FORMAT) {
        view->format = const_cast<char *>(info->format.c_str());
    }

    // Note, all contiguity flags imply PyBUF_STRIDES and lower.
    if ((flags & PyBUF_C_CONTIGUOUS) == PyBUF_C_CONTIGUOUS) {
        if (PyBuffer_IsContiguous(view, 'C') == 0) {
            std::memset(view, 0, sizeof(Py_buffer));
            set_error(PyExc_BufferError,
                      "C-contiguous buffer requested for discontiguous storage");
            return -1;
        }
    } else if ((flags & PyBUF_F_CONTIGUOUS) == PyBUF_F_CONTIGUOUS) {
        if (PyBuffer_IsContiguous(view, 'F') == 0) {
            std::memset(view, 0, sizeof(Py_buffer));
            set_error(PyExc_BufferError,
                      "Fortran-contiguous buffer requested for discontiguous storage");
            return -1;
        }
    } else if ((flags & PyBUF_ANY_CONTIGUOUS) == PyBUF_ANY_CONTIGUOUS) {
        if (PyBuffer_IsContiguous(view, 'A') == 0) {
            std::memset(view, 0, sizeof(Py_buffer));
            set_error(PyExc_BufferError, "Contiguous buffer requested for discontiguous storage");
            return -1;
        }

    } else if ((flags & PyBUF_STRIDES) != PyBUF_STRIDES) {
        // If no strides are requested, the buffer must be C-contiguous.
        // https://docs.python.org/3/c-api/buffer.html#contiguity-requests
        if (PyBuffer_IsContiguous(view, 'C') == 0) {
            std::memset(view, 0, sizeof(Py_buffer));
            set_error(PyExc_BufferError,
                      "C-contiguous buffer requested for discontiguous storage");
            return -1;
        }

        view->strides = nullptr;

        // Since this is a contiguous buffer, it can also pretend to be 1D.
        if ((flags & PyBUF_ND) != PyBUF_ND) {
            view->shape = nullptr;
            view->ndim = 0;
        }
    }

    // Set these after all checks so they don't leak out into the caller, and can be automatically
    // cleaned up on error.
    view->buf = info->ptr;
    view->internal = info.release();
    view->obj = obj;
    Py_INCREF(view->obj);
    return 0;
}

static void pybind11_releasebuffer(PyObject *, Py_buffer *view) {
    delete (buffer_info *) view->internal;
}

static void enable_buffer_protocol(PyHeapTypeObject *heap_type) {
    heap_type->ht_type.tp_as_buffer = &heap_type->as_buffer;

    heap_type->as_buffer.bf_getbuffer = pybind11_getbuffer;
    heap_type->as_buffer.bf_releasebuffer = pybind11_releasebuffer;
}

// -------- BIG FUNCTIONS:

void pybind11::non_limited_api::pybind11NLA_buffer_info_ctor(buffer_info &self, Py_buffer_ *view_, bool ownview)
{
    Py_buffer *view = (Py_buffer *)view_;

    self = buffer_info(
          view->buf,
          view->itemsize,
          view->format,
          view->ndim,
          {view->shape, view->shape + view->ndim},
          /* Though buffer::request() requests PyBUF_STRIDES, ctypes objects
           * ignore this flag and return a view with NULL strides.
           * When strides are NULL, build them manually.  */
          view->strides
              ? std::vector<ssize_t>(view->strides, view->strides + view->ndim)
              : detail::c_strides({view->shape, view->shape + view->ndim}, view->itemsize),
          (view->readonly != 0));

    self.m_view = view;
    self.ownview = ownview;
}

void pybind11::non_limited_api::pybind11NLA_handle_throw_gilstate_error(const handle &self, const std::string &function_name) {
    fprintf(
        stderr,
        "%s is being called while the GIL is either not held or invalid. Please see "
        "https://pybind11.readthedocs.io/en/stable/advanced/"
        "misc.html#common-sources-of-global-interpreter-lock-errors for debugging advice.\n"
        "If you are convinced there is no bug in your code, you can #define "
        "PYBIND11_NO_ASSERT_GIL_HELD_INCREF_DECREF "
        "to disable this check. In that case you have to ensure this #define is consistently "
        "used for all translation units linked into a given pybind11 extension, otherwise "
        "there will be ODR violations.",
        function_name.c_str());
    if (Py_TYPE(self.m_ptr)->tp_name != nullptr) {
        fprintf(stderr,
                " The failing %s call was triggered on a %s object.",
                function_name.c_str(),
                Py_TYPE(self.m_ptr)->tp_name);
    }
    fprintf(stderr, "\n");
    fflush(stderr);
    throw std::runtime_error(function_name + " PyGILState_Check() failure.");
}

const char *pybind11::non_limited_api::pybind11NLA_obj_class_name(PyObject *obj) {
    if (PyType_Check(obj)) {
        return reinterpret_cast<PyTypeObject *>(obj)->tp_name;
    }
    return Py_TYPE(obj)->tp_name;
}

std::string pybind11::non_limited_api::pybind11NLA_error_fetch_and_normalize_format_value_and_trace(const error_fetch_and_normalize &self) {
    std::string result;
    std::string message_error_string;
    if (self.m_value) {
        auto value_str = reinterpret_steal<object>(PyObject_Str(self.m_value.ptr()));
        constexpr const char *message_unavailable_exc
            = "<MESSAGE UNAVAILABLE DUE TO ANOTHER EXCEPTION>";
        if (!value_str) {
            message_error_string = detail::error_string();
            result = message_unavailable_exc;
        } else {
            // Not using `value_str.cast<std::string>()`, to not potentially throw a secondary
            // error_already_set that will then result in process termination (#4288).
            auto value_bytes = reinterpret_steal<object>(
                PyUnicode_AsEncodedString(value_str.ptr(), "utf-8", "backslashreplace"));
            if (!value_bytes) {
                message_error_string = detail::error_string();
                result = message_unavailable_exc;
            } else {
                char *buffer = nullptr;
                Py_ssize_t length = 0;
                if (PyBytes_AsStringAndSize(value_bytes.ptr(), &buffer, &length) == -1) {
                    message_error_string = detail::error_string();
                    result = message_unavailable_exc;
                } else {
                    result = std::string(buffer, static_cast<std::size_t>(length));
                }
            }
        }
#if PY_VERSION_HEX >= 0x030B0000
        auto notes
            = reinterpret_steal<object>(PyObject_GetAttrString(self.m_value.ptr(), "__notes__"));
        if (!notes) {
            PyErr_Clear(); // No notes is good news.
        } else {
            auto len_notes = PyList_Size(notes.ptr());
            if (len_notes < 0) {
                result += "\nFAILURE obtaining len(__notes__): " + detail::error_string();
            } else {
                result += "\n__notes__ (len=" + std::to_string(len_notes) + "):";
                for (ssize_t i = 0; i < len_notes; i++) {
                    PyObject *note = PyList_GET_ITEM(notes.ptr(), i);
                    auto note_bytes = reinterpret_steal<object>(
                        PyUnicode_AsEncodedString(note, "utf-8", "backslashreplace"));
                    if (!note_bytes) {
                        result += "\nFAILURE obtaining __notes__[" + std::to_string(i)
                                  + "]: " + detail::error_string();
                    } else {
                        char *buffer = nullptr;
                        Py_ssize_t length = 0;
                        if (PyBytes_AsStringAndSize(note_bytes.ptr(), &buffer, &length)
                            == -1) {
                            result += "\nFAILURE formatting __notes__[" + std::to_string(i)
                                      + "]: " + detail::error_string();
                        } else {
                            result += '\n';
                            result += std::string(buffer, static_cast<std::size_t>(length));
                        }
                    }
                }
            }
        }
#endif
    } else {
        result = "<MESSAGE UNAVAILABLE>";
    }
    if (result.empty()) {
        result = "<EMPTY MESSAGE>";
    }

    bool have_trace = false;
    if (self.m_trace) {
#if !defined(PYPY_VERSION) && !defined(GRAALVM_PYTHON)
        auto *tb = reinterpret_cast<PyTracebackObject *>(self.m_trace.ptr());

        // Get the deepest trace possible.
        while (tb->tb_next) {
            tb = tb->tb_next;
        }

        PyFrameObject *frame = tb->tb_frame;
        Py_XINCREF(frame);
        result += "\n\nAt:\n";
        while (frame) {
#    if PY_VERSION_HEX >= 0x030900B1
            PyCodeObject *f_code = PyFrame_GetCode(frame);
#    else
            PyCodeObject *f_code = frame->f_code;
            Py_INCREF(f_code);
#    endif
            int lineno = PyFrame_GetLineNumber(frame);
            result += "  ";
            result += handle(f_code->co_filename).cast<std::string>();
            result += '(';
            result += std::to_string(lineno);
            result += "): ";
            result += handle(f_code->co_name).cast<std::string>();
            result += '\n';
            Py_DECREF(f_code);
#    if PY_VERSION_HEX >= 0x030900B1
            auto *b_frame = PyFrame_GetBack(frame);
#    else
            auto *b_frame = frame->f_back;
            Py_XINCREF(b_frame);
#    endif
            Py_DECREF(frame);
            frame = b_frame;
        }

        have_trace = true;
#endif //! defined(PYPY_VERSION)
    }

    if (!message_error_string.empty()) {
        if (!have_trace) {
            result += '\n';
        }
        result += "\nMESSAGE UNAVAILABLE DUE TO EXCEPTION: " + message_error_string;
    }

    return result;
}

void pybind11::non_limited_api::pybind11NLA_get_function(handle &ret, handle value) {
    if (value) {
        if (PyInstanceMethod_Check(value.ptr())) {
            ret = PyInstanceMethod_GET_FUNCTION(value.ptr());
        } else if (PyMethod_Check(value.ptr())) {
            ret = PyMethod_GET_FUNCTION(value.ptr());
        }
    }
}

bool pybind11::non_limited_api::pybind11NLA_PyStaticMethod_Check(PyObject *o) { return Py_TYPE(o) == &PyStaticMethod_Type; }

void pybind11::non_limited_api::pybind11NLA_buffer_request(pybind11::buffer_info &ret, const buffer &self, bool writable) {
    int flags = PyBUF_STRIDES | PyBUF_FORMAT;
    if (writable) {
        flags |= PyBUF_WRITABLE;
    }
    auto *view = new Py_buffer();
    if (PyObject_GetBuffer(self.m_ptr, view, flags) != 0) {
        delete view;
        throw error_already_set();
    }
    ret = buffer_info(view);
}

void pybind11::non_limited_api::pybind11NLA_memoryview_ctor(memoryview &self, const buffer_info &info) {
    if (!info.view()) {
        pybind11_fail("Prohibited to create memoryview without Py_buffer");
    }
    // Note: PyMemoryView_FromBuffer never increments obj reference.
    self.m_ptr = (info.view()->obj) ? PyMemoryView_FromObject(info.view()->obj)
                               : PyMemoryView_FromBuffer(info.view());
    if (!self.m_ptr) {
        pybind11_fail("Unable to create memoryview from buffer descriptor");
    }
}

void pybind11::non_limited_api::pybind11NLA_memoryview_from_memory(memoryview &ret, void *mem, ssize_t size, bool readonly) {
    PyObject *ptr = PyMemoryView_FromMemory(
        reinterpret_cast<char *>(mem), size, (readonly) ? PyBUF_READ : PyBUF_WRITE);
    if (!ptr) {
        pybind11_fail("Could not allocate memoryview object!");
    }
    ret = memoryview(object(ptr, object::stolen_t{}));
}

void pybind11::non_limited_api::pybind11NLA_memoryview_from_buffer(
                                          memoryview &ret,
                                          void *ptr,
                                          ssize_t itemsize,
                                          const char *format,
                                          detail::any_container<ssize_t> shape,
                                          detail::any_container<ssize_t> strides,
                                          bool readonly) {
    size_t ndim = shape->size();
    if (ndim != strides->size()) {
        pybind11_fail("memoryview: shape length doesn't match strides length");
    }
    ssize_t size = ndim != 0u ? 1 : 0;
    for (size_t i = 0; i < ndim; ++i) {
        size *= (*shape)[i];
    }
    Py_buffer view;
    view.buf = ptr;
    view.obj = nullptr;
    view.len = size * itemsize;
    view.readonly = static_cast<int>(readonly);
    view.itemsize = itemsize;
    view.format = const_cast<char *>(format);
    view.ndim = static_cast<int>(ndim);
    view.shape = shape->data();
    view.strides = strides->data();
    view.suboffsets = nullptr;
    view.internal = nullptr;
    PyObject *obj = PyMemoryView_FromBuffer(&view);
    if (!obj) {
        throw error_already_set();
    }
    ret = memoryview(object(obj, object::stolen_t{}));
}

pybind11::detail::internals &pybind11::non_limited_api::pybind11NLA_get_internals() {
    auto **&internals_pp = get_internals_pp();
    if (internals_pp && *internals_pp) {
        return **internals_pp;
    }

#if defined(PYBIND11_SIMPLE_GIL_MANAGEMENT)
    gil_scoped_acquire gil;
#else
    // Ensure that the GIL is held since we will need to make Python calls.
    // Cannot use py::gil_scoped_acquire here since that constructor calls get_internals.
    struct gil_scoped_acquire_local {
        gil_scoped_acquire_local() : state(PyGILState_Ensure()) {}
        gil_scoped_acquire_local(const gil_scoped_acquire_local &) = delete;
        gil_scoped_acquire_local &operator=(const gil_scoped_acquire_local &) = delete;
        ~gil_scoped_acquire_local() { PyGILState_Release(state); }
        const PyGILState_STATE state;
    } gil;
#endif
    error_scope err_scope;

    dict state_dict = get_python_state_dict();
    if (object internals_obj = get_internals_obj_from_state_dict(state_dict)) {
        internals_pp = get_internals_pp_from_capsule(internals_obj);
    }
    if (internals_pp && *internals_pp) {
        // We loaded the internals through `state_dict`, which means that our `error_already_set`
        // and `builtin_exception` may be different local classes than the ones set up in the
        // initial exception translator, below, so add another for our local exception classes.
        //
        // libstdc++ doesn't require this (types there are identified only by name)
        // libc++ with CPython doesn't require this (types are explicitly exported)
        // libc++ with PyPy still need it, awaiting further investigation
#if !defined(__GLIBCXX__)
        (*internals_pp)->registered_exception_translators.push_front(&translate_local_exception);
#endif
    } else {
        if (!internals_pp) {
            internals_pp = new internals *();
        }
        auto *&internals_ptr = *internals_pp;
        internals_ptr = new internals();

        PyThreadState *tstate = PyThreadState_Get();
        // NOLINTNEXTLINE(bugprone-assignment-in-if-condition)
        if (!PYBIND11_TLS_KEY_CREATE(internals_ptr->tstate)) {
            pybind11_fail("get_internals: could not successfully initialize the tstate TSS key!");
        }
        PYBIND11_TLS_REPLACE_VALUE(internals_ptr->tstate, tstate);

#if PYBIND11_INTERNALS_VERSION > 4
        // NOLINTNEXTLINE(bugprone-assignment-in-if-condition)
        if (!PYBIND11_TLS_KEY_CREATE(internals_ptr->loader_life_support_tls_key)) {
            pybind11_fail("get_internals: could not successfully initialize the "
                          "loader_life_support TSS key!");
        }
#endif
        internals_ptr->istate = tstate->interp;
        state_dict[PYBIND11_INTERNALS_ID] = capsule(reinterpret_cast<void *>(internals_pp));
        internals_ptr->registered_exception_translators.push_front(&translate_exception);
        internals_ptr->static_property_type = make_static_property_type();
        internals_ptr->default_metaclass = make_default_metaclass();
        internals_ptr->instance_base = make_object_base_type(internals_ptr->default_metaclass);
#ifdef Py_GIL_DISABLED
        // Scale proportional to the number of cores. 2x is a heuristic to reduce contention.
        auto num_shards
            = static_cast<size_t>(round_up_to_next_pow2(2 * std::thread::hardware_concurrency()));
        if (num_shards == 0) {
            num_shards = 1;
        }
        internals_ptr->instance_shards.reset(new instance_map_shard[num_shards]);
        internals_ptr->instance_shards_mask = num_shards - 1;
#endif // Py_GIL_DISABLED
    }
    return **internals_pp;
}

bool pybind11::non_limited_api::pybind11NLA_type_is_managed_by_our_internals(PyTypeObject *type_obj) {
#if defined(PYPY_VERSION)
    auto &internals = get_internals();
    return bool(internals.registered_types_py.find(type_obj)
                != internals.registered_types_py.end());
#else
    return bool(type_obj->tp_new == pybind11_object_new);
#endif
}

bool pybind11::non_limited_api::pybind11NLA_is_instance_method_of_type(PyTypeObject *type_obj, PyObject *attr_name) {
    PyObject *descr = _PyType_Lookup(type_obj, attr_name);
    return bool((descr != nullptr) && PyInstanceMethod_Check(descr));
}

void pybind11::non_limited_api::pybind11NLA_all_type_info_populate(PyTypeObject *t, std::vector<type_info *> &bases) {
    assert(bases.empty());
    std::vector<PyTypeObject *> check;
    for (handle parent : reinterpret_borrow<tuple>(t->tp_bases)) {
        check.push_back((PyTypeObject *) parent.ptr());
    }
    auto const &type_dict = get_internals().registered_types_py;
    for (size_t i = 0; i < check.size(); i++) {
        auto *type = check[i];
        // Ignore Python2 old-style class super type:
        if (!PyType_Check((PyObject *) type)) {
            continue;
        }

        // Check `type` in the current set of registered python types:
        auto it = type_dict.find(type);
        if (it != type_dict.end()) {
            // We found a cache entry for it, so it's either pybind-registered or has pre-computed
            // pybind bases, but we have to make sure we haven't already seen the type(s) before:
            // we want to follow Python/virtual C++ rules that there should only be one instance of
            // a common base.
            for (auto *tinfo : it->second) {
                // NB: Could use a second set here, rather than doing a linear search, but since
                // having a large number of immediate pybind11-registered types seems fairly
                // unlikely, that probably isn't worthwhile.
                bool found = false;
                for (auto *known : bases) {
                    if (known == tinfo) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    all_type_info_add_base_most_derived_first(bases, tinfo);
                }
            }
        } else if (type->tp_bases) {
            // It's some python type, so keep follow its bases classes to look for one or more
            // registered types
            if (i + 1 == check.size()) {
                // When we're at the end, we can pop off the current element to avoid growing
                // `check` when adding just one base (which is typical--i.e. when there is no
                // multiple inheritance)
                check.pop_back();
                i--;
            }
            for (handle parent : reinterpret_borrow<tuple>(type->tp_bases)) {
                check.push_back((PyTypeObject *) parent.ptr());
            }
        }
    }
}

bool pybind11::non_limited_api::pybind11NLA_type_caster_bool_load(type_caster<bool> &self, handle src, bool convert) {
    if (!src) {
        return false;
    }
    if (src.ptr() == Py_True) {
        self.value = true;
        return true;
    }
    if (src.ptr() == Py_False) {
        self.value = false;
        return true;
    }
    if (convert || type_caster<bool>::is_numpy_bool(src)) {
        // (allow non-implicit conversion for numpy booleans), use strncmp
        // since NumPy 1.x had an additional trailing underscore.

        Py_ssize_t res = -1;
        if (src.is_none()) {
            res = 0; // None is implicitly converted to False
        }
#if defined(PYPY_VERSION)
        // On PyPy, check that "__bool__" attr exists
        else if (hasattr(src, PYBIND11_BOOL_ATTR)) {
            res = PyObject_IsTrue(src.ptr());
        }
#else
        // Alternate approach for CPython: this does the same as the above, but optimized
        // using the CPython API so as to avoid an unneeded attribute lookup.
        else if (auto *tp_as_number = Py_TYPE(src.ptr())->tp_as_number) {
            if (PYBIND11_NB_BOOL(tp_as_number)) {
                res = (*PYBIND11_NB_BOOL(tp_as_number))(src.ptr());
            }
        }
#endif
        if (res == 0 || res == 1) {
            self.value = (res != 0);
            return true;
        }
        PyErr_Clear();
    }
    return false;
}

bool pybind11::non_limited_api::pybind11NLA_type_caster_bool_is_numpy_bool(handle object) {
    const char *type_name = Py_TYPE(object.ptr())->tp_name;
    // Name changed to `numpy.bool` in NumPy 2, `numpy.bool_` is needed for 1.x support
    return std::strcmp("numpy.bool", type_name) == 0
           || std::strcmp("numpy.bool_", type_name) == 0;
}

void pybind11::non_limited_api::pybind11NLA_type_record_add_base(type_record &self, const std::type_info &base, void *(*caster)(void *) ) {
    auto *base_info = detail::get_type_info(base, false);
    if (!base_info) {
        std::string tname(base.name());
        detail::clean_type_id(tname);
        pybind11_fail("generic_type: type \"" + std::string(self.name)
                      + "\" referenced unknown base type \"" + tname + "\"");
    }

    if (self.default_holder != base_info->default_holder) {
        std::string tname(base.name());
        detail::clean_type_id(tname);
        pybind11_fail("generic_type: type \"" + std::string(self.name) + "\" "
                      + (self.default_holder ? "does not have" : "has")
                      + " a non-default holder type while its base \"" + tname + "\" "
                      + (base_info->default_holder ? "does not" : "does"));
    }

    self.bases.append((PyObject *) base_info->type);

#if PY_VERSION_HEX < 0x030B0000
    self.dynamic_attr |= base_info->type->tp_dictoffset != 0;
#else
    self.dynamic_attr |= (base_info->type->tp_flags & Py_TPFLAGS_MANAGED_DICT) != 0;
#endif

    if (caster) {
        base_info->implicit_casts.emplace_back(self.type, caster);
    }
}

std::string pybind11::non_limited_api::pybind11NLA_get_fully_qualified_tp_name(PyTypeObject *type) {
#if !defined(PYPY_VERSION)
    return type->tp_name;
#else
    auto module_name = handle((PyObject *) type).attr("__module__").cast<std::string>();
    if (module_name == PYBIND11_BUILTINS_MODULE)
        return type->tp_name;
    else
        return std::move(module_name) + "." + type->tp_name;
#endif
}

void pybind11::non_limited_api::pybind11NLA_traverse_offset_bases(void *valueptr,
                                  const detail::type_info *tinfo,
                                  instance *self,
                                  bool (*f)(void * /*parentptr*/, instance * /*self*/)) {
    for (handle h : reinterpret_borrow<tuple>(tinfo->type->tp_bases)) {
        if (auto *parent_tinfo = get_type_info((PyTypeObject *) h.ptr())) {
            for (auto &c : parent_tinfo->implicit_casts) {
                if (c.first == tinfo->cpptype) {
                    auto *parentptr = c.second(valueptr);
                    if (parentptr != valueptr) {
                        f(parentptr, self);
                    }
                    pybind11NLA_traverse_offset_bases(parentptr, parent_tinfo, self, f);
                    break;
                }
            }
        }
    }
}

PyObject *pybind11::non_limited_api::pybind11NLA_make_new_instance(PyTypeObject *type) {
#if defined(PYPY_VERSION)
    // PyPy gets tp_basicsize wrong (issue 2482) under multiple inheritance when the first
    // inherited object is a plain Python type (i.e. not derived from an extension type).  Fix it.
    ssize_t instance_size = static_cast<ssize_t>(sizeof(instance));
    if (type->tp_basicsize < instance_size) {
        type->tp_basicsize = instance_size;
    }
#endif
    PyObject *self = type->tp_alloc(type, 0);
    auto *inst = reinterpret_cast<instance *>(self);
    // Allocate the value/holder internals:
    inst->allocate_layout();

    return self;
}

PyObject *pybind11::non_limited_api::pybind11NLA_make_new_python_type(const type_record &rec) {
    auto name = reinterpret_steal<object>(PYBIND11_FROM_STRING(rec.name));

    auto qualname = name;
    if (rec.scope && !PyModule_Check(rec.scope.ptr()) && hasattr(rec.scope, "__qualname__")) {
        qualname = reinterpret_steal<object>(
            PyUnicode_FromFormat("%U.%U", rec.scope.attr("__qualname__").ptr(), name.ptr()));
    }

    object module_;
    if (rec.scope) {
        if (hasattr(rec.scope, "__module__")) {
            module_ = rec.scope.attr("__module__");
        } else if (hasattr(rec.scope, "__name__")) {
            module_ = rec.scope.attr("__name__");
        }
    }

    const auto *full_name = c_str(
#if !defined(PYPY_VERSION)
        module_ ? str(module_).cast<std::string>() + "." + rec.name :
#endif
                rec.name);

    char *tp_doc = nullptr;
    if (rec.doc && options::show_user_defined_docstrings()) {
        /* Allocate memory for docstring (Python will free this later on) */
        size_t size = std::strlen(rec.doc) + 1;
#if PY_VERSION_HEX >= 0x030D0000
        tp_doc = (char *) PyMem_MALLOC(size);
#else
        tp_doc = (char *) PyObject_MALLOC(size);
#endif
        std::memcpy((void *) tp_doc, rec.doc, size);
    }

    auto &internals = get_internals();
    auto bases = tuple(rec.bases);
    auto *base = (bases.empty()) ? internals.instance_base : bases[0].ptr();

    /* Danger zone: from now (and until PyType_Ready), make sure to
       issue no Python C API calls which could potentially invoke the
       garbage collector (the GC will call type_traverse(), which will in
       turn find the newly constructed type in an invalid state) */
    auto *metaclass
        = rec.metaclass.ptr() ? (PyTypeObject *) rec.metaclass.ptr() : internals.default_metaclass;

    auto *heap_type = (PyHeapTypeObject *) metaclass->tp_alloc(metaclass, 0);
    if (!heap_type) {
        pybind11_fail(std::string(rec.name) + ": Unable to create type object!");
    }

    heap_type->ht_name = name.release().ptr();
#ifdef PYBIND11_BUILTIN_QUALNAME
    heap_type->ht_qualname = qualname.inc_ref().ptr();
#endif

    auto *type = &heap_type->ht_type;
    type->tp_name = full_name;
    type->tp_doc = tp_doc;
    type->tp_base = type_incref((PyTypeObject *) base);
    type->tp_basicsize = static_cast<ssize_t>(sizeof(instance));
    if (!bases.empty()) {
        type->tp_bases = bases.release().ptr();
    }

    /* Don't inherit base __init__ */
    type->tp_init = pybind11_object_init;

    /* Supported protocols */
    type->tp_as_number = &heap_type->as_number;
    type->tp_as_sequence = &heap_type->as_sequence;
    type->tp_as_mapping = &heap_type->as_mapping;
    type->tp_as_async = &heap_type->as_async;

    /* Flags */
    type->tp_flags |= Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE;
    if (!rec.is_final) {
        type->tp_flags |= Py_TPFLAGS_BASETYPE;
    }

    if (rec.dynamic_attr) {
        enable_dynamic_attributes(heap_type);
    }

    if (rec.buffer_protocol) {
        enable_buffer_protocol(heap_type);
    }

    if (rec.custom_type_setup_callback) {
        rec.custom_type_setup_callback(heap_type);
    }

    if (PyType_Ready(type) < 0) {
        pybind11_fail(std::string(rec.name) + ": PyType_Ready failed: " + error_string());
    }

    assert(!rec.dynamic_attr || PyType_HasFeature(type, Py_TPFLAGS_HAVE_GC));

    /* Register type with the parent scope */
    if (rec.scope) {
        setattr(rec.scope, rec.name, (PyObject *) type);
    } else {
        Py_INCREF(type); // Keep it alive forever (reference leak)
    }

    if (module_) { // Needed by pydoc
        setattr((PyObject *) type, "__module__", module_);
    }

    PYBIND11_SET_OLDPY_QUALNAME(type, qualname);

    return (PyObject *) type;
}

void pybind11::non_limited_api::pybind11NLA_gil_scoped_acquire_ctor(gil_scoped_acquire &self) {
    auto &internals = detail::get_internals();
    self.tstate = (PyThreadState *) PYBIND11_TLS_GET_VALUE(internals.tstate);

    if (!self.tstate) {
        /* Check if the GIL was acquired using the PyGILState_* API instead (e.g. if
           calling from a Python thread). Since we use a different key, this ensures
           we don't create a new thread state and deadlock in PyEval_AcquireThread
           below. Note we don't save this state with internals.tstate, since we don't
           create it we would fail to clear it (its reference count should be > 0). */
        self.tstate = PyGILState_GetThisThreadState();
    }

    if (!self.tstate) {
        self.tstate = PyThreadState_New(internals.istate);
#    if defined(PYBIND11_DETAILED_ERROR_MESSAGES)
        if (!self.tstate) {
            pybind11_fail("scoped_acquire: could not create thread state!");
        }
#    endif
        self.tstate->gilstate_counter = 0;
        PYBIND11_TLS_REPLACE_VALUE(internals.tstate, self.tstate);
    } else {
        self.release = get_thread_state_unchecked() != self.tstate;
    }

    if (self.release) {
        PyEval_AcquireThread(self.tstate);
    }

    self.inc_ref();
}

void pybind11::non_limited_api::pybind11NLA_gil_scoped_acquire_inc_ref(gil_scoped_acquire &self) { ++self.tstate->gilstate_counter; }

void pybind11::non_limited_api::pybind11NLA_gil_scoped_acquire_dec_ref(gil_scoped_acquire &self) {
    --self.tstate->gilstate_counter;
#    if defined(PYBIND11_DETAILED_ERROR_MESSAGES)
    if (get_thread_state_unchecked() != self.tstate) {
        pybind11_fail("scoped_acquire::dec_ref(): thread state must be current!");
    }
    if (self.tstate->gilstate_counter < 0) {
        pybind11_fail("scoped_acquire::dec_ref(): reference count underflow!");
    }
#    endif
    if (self.tstate->gilstate_counter == 0) {
#    if defined(PYBIND11_DETAILED_ERROR_MESSAGES)
        if (!self.release) {
            pybind11_fail("scoped_acquire::dec_ref(): internal error!");
        }
#    endif
        PyThreadState_Clear(self.tstate);
        if (self.active) {
            PyThreadState_DeleteCurrent();
        }
        PYBIND11_TLS_DELETE_VALUE(detail::get_internals().tstate);
        self.release = false;
    }
}

void pybind11::non_limited_api::pybind11NLA_cpp_function_initialize_generic(cpp_function &self,
                        std::unique_ptr<detail::function_record, InitializingFunctionRecordDeleter> &&unique_rec,
                        const char *text,
                        const std::type_info *const *types,
                        size_t args) {
    // Do NOT receive `unique_rec` by value. If this function fails to move out the unique_ptr,
    // we do not want this to destruct the pointer. `initialize` (the caller) still relies on
    // the pointee being alive after this call. Only move out if a `capsule` is going to keep
    // it alive.
    auto *rec = unique_rec.get();

    // Keep track of strdup'ed strings, and clean them up as long as the function's capsule
    // has not taken ownership yet (when `unique_rec.release()` is called).
    // Note: This cannot easily be fixed by a `unique_ptr` with custom deleter, because the
    // strings are only referenced before strdup'ing. So only *after* the following block could
    // `destruct` safely be called, but even then, `repr` could still throw in the middle of
    // copying all strings.
    cpp_function::strdup_guard guarded_strdup;

    /* Create copies of all referenced C-style strings */
    rec->name = guarded_strdup(rec->name ? rec->name : "");
    if (rec->doc) {
        rec->doc = guarded_strdup(rec->doc);
    }
    for (auto &a : rec->args) {
        if (a.name) {
            a.name = guarded_strdup(a.name);
        }
        if (a.descr) {
            a.descr = guarded_strdup(a.descr);
        } else if (a.value) {
            a.descr = guarded_strdup(repr(a.value).cast<std::string>().c_str());
        }
    }

    rec->is_constructor = (std::strcmp(rec->name, "__init__") == 0)
                          || (std::strcmp(rec->name, "__setstate__") == 0);

#if defined(PYBIND11_DETAILED_ERROR_MESSAGES) && !defined(PYBIND11_DISABLE_NEW_STYLE_INIT_WARNING)
    if (rec->is_constructor && !rec->is_new_style_constructor) {
        const auto class_name
            = detail::get_fully_qualified_tp_name((PyTypeObject *) rec->scope.ptr());
        const auto func_name = std::string(rec->name);
        PyErr_WarnEx(PyExc_FutureWarning,
                     ("pybind11-bound class '" + class_name
                      + "' is using an old-style "
                        "placement-new '"
                      + func_name
                      + "' which has been deprecated. See "
                        "the upgrade guide in pybind11's docs. This message is only visible "
                        "when compiled in debug mode.")
                         .c_str(),
                     0);
    }
#endif

    /* Generate a proper function signature */
    std::string signature;
    size_t type_index = 0, arg_index = 0;
    bool is_starred = false;
    for (const auto *pc = text; *pc != '\0'; ++pc) {
        const auto c = *pc;

        if (c == '{') {
            // Write arg name for everything except *args and **kwargs.
            is_starred = *(pc + 1) == '*';
            if (is_starred) {
                continue;
            }
            // Separator for keyword-only arguments, placed before the kw
            // arguments start (unless we are already putting an *args)
            if (!rec->has_args && arg_index == rec->nargs_pos) {
                signature += "*, ";
            }
            if (arg_index < rec->args.size() && rec->args[arg_index].name) {
                signature += rec->args[arg_index].name;
            } else if (arg_index == 0 && rec->is_method) {
                signature += "self";
            } else {
                signature += "arg" + std::to_string(arg_index - (rec->is_method ? 1 : 0));
            }
            signature += ": ";
        } else if (c == '}') {
            // Write default value if available.
            if (!is_starred && arg_index < rec->args.size() && rec->args[arg_index].descr) {
                signature += " = ";
                signature += detail::replace_newlines_and_squash(rec->args[arg_index].descr);
            }
            // Separator for positional-only arguments (placed after the
            // argument, rather than before like *
            if (rec->nargs_pos_only > 0 && (arg_index + 1) == rec->nargs_pos_only) {
                signature += ", /";
            }
            if (!is_starred) {
                arg_index++;
            }
        } else if (c == '%') {
            const std::type_info *t = types[type_index++];
            if (!t) {
                pybind11_fail("Internal error while parsing type signature (1)");
            }
            if (auto *tinfo = detail::get_type_info(*t)) {
                handle th((PyObject *) tinfo->type);
                signature += th.attr("__module__").cast<std::string>() + "."
                             + th.attr("__qualname__").cast<std::string>();
            } else if (rec->is_new_style_constructor && arg_index == 0) {
                // A new-style `__init__` takes `self` as `value_and_holder`.
                // Rewrite it to the proper class type.
                signature += rec->scope.attr("__module__").cast<std::string>() + "."
                             + rec->scope.attr("__qualname__").cast<std::string>();
            } else {
                signature += detail::quote_cpp_type_name(detail::clean_type_id(t->name()));
            }
        } else {
            signature += c;
        }
    }

    if (arg_index != args - rec->has_args - rec->has_kwargs || types[type_index] != nullptr) {
        pybind11_fail("Internal error while parsing type signature (2)");
    }

    rec->signature = guarded_strdup(signature.c_str());
    rec->args.shrink_to_fit();
    rec->nargs = (std::uint16_t) args;

    if (rec->sibling && PYBIND11_INSTANCE_METHOD_CHECK(rec->sibling.ptr())) {
        rec->sibling = PYBIND11_INSTANCE_METHOD_GET_FUNCTION(rec->sibling.ptr());
    }

    detail::function_record *chain = nullptr, *chain_start = rec;
    if (rec->sibling) {
        if (PyCFunction_Check(rec->sibling.ptr())) {
            auto *self = PyCFunction_GET_SELF(rec->sibling.ptr());
            if (!isinstance<capsule>(self)) {
                chain = nullptr;
            } else {
                auto rec_capsule = reinterpret_borrow<capsule>(self);
                if (detail::is_function_record_capsule(rec_capsule)) {
                    chain = rec_capsule.get_pointer<detail::function_record>();
                    /* Never append a method to an overload chain of a parent class;
                       instead, hide the parent's overloads in this case */
                    if (!chain->scope.is(rec->scope)) {
                        chain = nullptr;
                    }
                } else {
                    chain = nullptr;
                }
            }
        }
        // Don't trigger for things like the default __init__, which are wrapper_descriptors
        // that we are intentionally replacing
        else if (!rec->sibling.is_none() && rec->name[0] != '_') {
            pybind11_fail("Cannot overload existing non-function object \""
                          + std::string(rec->name) + "\" with a function of the same name");
        }
    }

    if (!chain) {
        /* No existing overload was found, create a new function object */
        rec->def = new PyMethodDef();
        std::memset(rec->def, 0, sizeof(PyMethodDef));
        rec->def->ml_name = rec->name;
        rec->def->ml_meth
            = reinterpret_cast<PyCFunction>(reinterpret_cast<void (*)()>(self.dispatcher));
        rec->def->ml_flags = METH_VARARGS | METH_KEYWORDS;

        capsule rec_capsule(unique_rec.release(),
                            detail::get_function_record_capsule_name(),
                            [](void *ptr) { cpp_function::destruct((detail::function_record *) ptr); });
        guarded_strdup.release();

        object scope_module;
        if (rec->scope) {
            if (hasattr(rec->scope, "__module__")) {
                scope_module = rec->scope.attr("__module__");
            } else if (hasattr(rec->scope, "__name__")) {
                scope_module = rec->scope.attr("__name__");
            }
        }

        self.m_ptr = PyCFunction_NewEx(rec->def, rec_capsule.ptr(), scope_module.ptr());
        if (!self.m_ptr) {
            pybind11_fail("cpp_function::cpp_function(): Could not allocate function object");
        }
    } else {
        /* Append at the beginning or end of the overload chain */
        self.m_ptr = rec->sibling.ptr();
        self.inc_ref();
        if (chain->is_method != rec->is_method) {
            pybind11_fail(
                "overloading a method with both static and instance methods is not supported; "
#if !defined(PYBIND11_DETAILED_ERROR_MESSAGES)
                "#define PYBIND11_DETAILED_ERROR_MESSAGES or compile in debug mode for more "
                "details"
#else
                "error while attempting to bind "
                + std::string(rec->is_method ? "instance" : "static") + " method "
                + std::string(pybind11::str(rec->scope.attr("__name__"))) + "."
                + std::string(rec->name) + signature
#endif
            );
        }

        if (rec->prepend) {
            // Beginning of chain; we need to replace the capsule's current head-of-the-chain
            // pointer with this one, then make this one point to the previous head of the
            // chain.
            chain_start = rec;
            rec->next = chain;
            auto rec_capsule = reinterpret_borrow<capsule>(PyCFunction_GET_SELF(self.m_ptr));
            rec_capsule.set_pointer(unique_rec.release());
            guarded_strdup.release();
        } else {
            // Or end of chain (normal behavior)
            chain_start = chain;
            while (chain->next) {
                chain = chain->next;
            }
            chain->next = unique_rec.release();
            guarded_strdup.release();
        }
    }

    std::string signatures;
    int index = 0;
    /* Create a nice pydoc rec including all signatures and
       docstrings of the functions in the overload chain */
    if (chain && options::show_function_signatures()
        && std::strcmp(rec->name, "_pybind11_conduit_v1_") != 0) {
        // First a generic signature
        signatures += rec->name;
        signatures += "(*args, **kwargs)\n";
        signatures += "Overloaded function.\n\n";
    }
    // Then specific overload signatures
    bool first_user_def = true;
    for (auto *it = chain_start; it != nullptr; it = it->next) {
        if (options::show_function_signatures()
            && std::strcmp(rec->name, "_pybind11_conduit_v1_") != 0) {
            if (index > 0) {
                signatures += '\n';
            }
            if (chain) {
                signatures += std::to_string(++index) + ". ";
            }
            signatures += rec->name;
            signatures += it->signature;
            signatures += '\n';
        }
        if (it->doc && it->doc[0] != '\0' && options::show_user_defined_docstrings()) {
            // If we're appending another docstring, and aren't printing function signatures,
            // we need to append a newline first:
            if (!options::show_function_signatures()) {
                if (first_user_def) {
                    first_user_def = false;
                } else {
                    signatures += '\n';
                }
            }
            if (options::show_function_signatures()) {
                signatures += '\n';
            }
            signatures += it->doc;
            if (options::show_function_signatures()) {
                signatures += '\n';
            }
        }
    }

    auto *func = (PyCFunctionObject *) self.m_ptr;
    // Install docstring if it's non-empty (when at least one option is enabled)
    auto *doc = signatures.empty() ? nullptr : PYBIND11_COMPAT_STRDUP(signatures.c_str());
    std::free(const_cast<char *>(PYBIND11_PYCFUNCTION_GET_DOC(func)));
    PYBIND11_PYCFUNCTION_SET_DOC(func, doc);

    if (rec->is_method) {
        self.m_ptr = PYBIND11_INSTANCE_METHOD_NEW(self.m_ptr, rec->scope.ptr());
        if (!self.m_ptr) {
            pybind11_fail(
                "cpp_function::cpp_function(): Could not allocate instance method object");
        }
        Py_DECREF(func);
    }
}

void pybind11::non_limited_api::pybind11NLA_generic_type_mark_parents_nonsimple(generic_type &self, PyTypeObject *value) {
    auto t = reinterpret_borrow<tuple>(value->tp_bases);
    for (handle h : t) {
        auto *tinfo2 = get_type_info((PyTypeObject *) h.ptr());
        if (tinfo2) {
            tinfo2->simple_type = false;
        }
        self.mark_parents_nonsimple((PyTypeObject *) h.ptr());
    }
}

void pybind11::non_limited_api::pybind11NLA_generic_type_install_buffer_funcs(generic_type &self,
                                                         buffer_info *(*get_buffer)(PyObject *, void *),
                                                         void *get_buffer_data)
{
    auto *type = (PyHeapTypeObject *) self.m_ptr;
    auto *tinfo = detail::get_type_info(&type->ht_type);

    if (!type->ht_type.tp_as_buffer) {
        pybind11_fail("To be able to register buffer protocol support for the type '"
                      + get_fully_qualified_tp_name(tinfo->type)
                      + "' the associated class<>(..) invocation must "
                        "include the pybind11::buffer_protocol() annotation!");
    }

    tinfo->get_buffer = get_buffer;
    tinfo->get_buffer_data = get_buffer_data;
}

void pybind11::non_limited_api::pybind11NLA_enum_base_init(enum_base &self, bool is_arithmetic, bool is_convertible) {
    self.m_base.attr("__entries") = dict();
    auto property = handle((PyObject *) &PyProperty_Type);
    auto static_property = handle((PyObject *) get_internals().static_property_type);

    self.m_base.attr("__repr__") = cpp_function(
        [](const object &arg) -> str {
            handle type = type::handle_of(arg);
            object type_name = type.attr("__name__");
            return pybind11::str("<{}.{}: {}>")
                .format(std::move(type_name), enum_name(arg), int_(arg));
        },
        name("__repr__"),
        is_method(self.m_base),
        pos_only());

    self.m_base.attr("name")
        = property(cpp_function(&enum_name, name("name"), is_method(self.m_base), pos_only()));

    self.m_base.attr("__str__") = cpp_function(
        [](handle arg) -> str {
            object type_name = type::handle_of(arg).attr("__name__");
            return pybind11::str("{}.{}").format(std::move(type_name), enum_name(arg));
        },
        name("__str__"),
        is_method(self.m_base),
        pos_only());

    if (options::show_enum_members_docstring()) {
        self.m_base.attr("__doc__") = static_property(
            cpp_function(
                [](handle arg) -> std::string {
                    std::string docstring;
                    dict entries = arg.attr("__entries");
                    if (((PyTypeObject *) arg.ptr())->tp_doc) {
                        docstring += std::string(
                            reinterpret_cast<PyTypeObject *>(arg.ptr())->tp_doc);
                        docstring += "\n\n";
                    }
                    docstring += "Members:";
                    for (auto kv : entries) {
                        auto key = std::string(pybind11::str(kv.first));
                        auto comment = kv.second[int_(1)];
                        docstring += "\n\n  ";
                        docstring += key;
                        if (!comment.is_none()) {
                            docstring += " : ";
                            docstring += pybind11::str(comment).cast<std::string>();
                        }
                    }
                    return docstring;
                },
                name("__doc__")),
            none(),
            none(),
            "");
    }

    self.m_base.attr("__members__") = static_property(cpp_function(
                                                     [](handle arg) -> dict {
                                                         dict entries = arg.attr("__entries"),
                                                              m;
                                                         for (auto kv : entries) {
                                                             m[kv.first] = kv.second[int_(0)];
                                                         }
                                                         return m;
                                                     },
                                                     name("__members__")),
                                                 none(),
                                                 none(),
                                                 "");

#define PYBIND11_ENUM_OP_STRICT(op, expr, strict_behavior)                                        \
self.m_base.attr(op) = cpp_function(                                                               \
    [](const object &a, const object &b) {                                                    \
        if (!type::handle_of(a).is(type::handle_of(b)))                                       \
            strict_behavior; /* NOLINT(bugprone-macro-parentheses) */                         \
        return expr;                                                                          \
    },                                                                                        \
    name(op),                                                                                 \
    is_method(self.m_base),                                                                        \
    arg("other"),                                                                             \
    pos_only())

#define PYBIND11_ENUM_OP_CONV(op, expr)                                                           \
self.m_base.attr(op) = cpp_function(                                                               \
    [](const object &a_, const object &b_) {                                                  \
        int_ a(a_), b(b_);                                                                    \
        return expr;                                                                          \
    },                                                                                        \
    name(op),                                                                                 \
    is_method(self.m_base),                                                                        \
    arg("other"),                                                                             \
    pos_only())

#define PYBIND11_ENUM_OP_CONV_LHS(op, expr)                                                       \
self.m_base.attr(op) = cpp_function(                                                               \
    [](const object &a_, const object &b) {                                                   \
        int_ a(a_);                                                                           \
        return expr;                                                                          \
    },                                                                                        \
    name(op),                                                                                 \
    is_method(self.m_base),                                                                        \
    arg("other"),                                                                             \
    pos_only())

    if (is_convertible) {
        PYBIND11_ENUM_OP_CONV_LHS("__eq__", !b.is_none() && a.equal(b));
        PYBIND11_ENUM_OP_CONV_LHS("__ne__", b.is_none() || !a.equal(b));

        if (is_arithmetic) {
            PYBIND11_ENUM_OP_CONV("__lt__", a < b);
            PYBIND11_ENUM_OP_CONV("__gt__", a > b);
            PYBIND11_ENUM_OP_CONV("__le__", a <= b);
            PYBIND11_ENUM_OP_CONV("__ge__", a >= b);
            PYBIND11_ENUM_OP_CONV("__and__", a & b);
            PYBIND11_ENUM_OP_CONV("__rand__", a & b);
            PYBIND11_ENUM_OP_CONV("__or__", a | b);
            PYBIND11_ENUM_OP_CONV("__ror__", a | b);
            PYBIND11_ENUM_OP_CONV("__xor__", a ^ b);
            PYBIND11_ENUM_OP_CONV("__rxor__", a ^ b);
            self.m_base.attr("__invert__")
                = cpp_function([](const object &arg) { return ~(int_(arg)); },
                               name("__invert__"),
                               is_method(self.m_base),
                               pos_only());
        }
    } else {
        PYBIND11_ENUM_OP_STRICT("__eq__", int_(a).equal(int_(b)), return false);
        PYBIND11_ENUM_OP_STRICT("__ne__", !int_(a).equal(int_(b)), return true);

        if (is_arithmetic) {
#define PYBIND11_THROW throw type_error("Expected an enumeration of matching type!");
            PYBIND11_ENUM_OP_STRICT("__lt__", int_(a) < int_(b), PYBIND11_THROW);
            PYBIND11_ENUM_OP_STRICT("__gt__", int_(a) > int_(b), PYBIND11_THROW);
            PYBIND11_ENUM_OP_STRICT("__le__", int_(a) <= int_(b), PYBIND11_THROW);
            PYBIND11_ENUM_OP_STRICT("__ge__", int_(a) >= int_(b), PYBIND11_THROW);
#undef PYBIND11_THROW
        }
    }

#undef PYBIND11_ENUM_OP_CONV_LHS
#undef PYBIND11_ENUM_OP_CONV
#undef PYBIND11_ENUM_OP_STRICT

    self.m_base.attr("__getstate__") = cpp_function([](const object &arg) { return int_(arg); },
                                               name("__getstate__"),
                                               is_method(self.m_base),
                                               pos_only());

    self.m_base.attr("__hash__") = cpp_function([](const object &arg) { return int_(arg); },
                                           name("__hash__"),
                                           is_method(self.m_base),
                                           pos_only());
}

void pybind11::non_limited_api::pybind11NLA_get_type_override(function &ret, const void *this_ptr, const type_info *this_type, const char *name) {
    handle self = get_object_handle(this_ptr, this_type);
    if (!self) {
        return function();
    }
    handle type = type::handle_of(self);
    auto key = std::make_pair(type.ptr(), name);

    /* Cache functions that aren't overridden in Python to avoid
       many costly Python dictionary lookups below */
    bool not_overridden = with_internals([&key](internals &internals) {
        auto &cache = internals.inactive_override_cache;
        return cache.find(key) != cache.end();
    });
    if (not_overridden) {
        return;
    }

    function override = getattr(self, name, function());
    if (override.is_cpp_function()) {
        with_internals([&](internals &internals) {
            internals.inactive_override_cache.insert(std::move(key));
        });
        return;
    }

    /* Don't call dispatch code if invoked from overridden function.
       Unfortunately this doesn't work on PyPy and GraalPy. */
#if !defined(PYPY_VERSION) && !defined(GRAALVM_PYTHON)
#    if PY_VERSION_HEX >= 0x03090000
    PyFrameObject *frame = PyThreadState_GetFrame(PyThreadState_Get());
    if (frame != nullptr) {
        PyCodeObject *f_code = PyFrame_GetCode(frame);
        // f_code is guaranteed to not be NULL
        if ((std::string) str(f_code->co_name) == name && f_code->co_argcount > 0) {
#        if PY_VERSION_HEX >= 0x030d0000
            PyObject *locals = PyEval_GetFrameLocals();
#        else
            PyObject *locals = PyEval_GetLocals();
            Py_XINCREF(locals);
#        endif
            if (locals != nullptr) {
#        if PY_VERSION_HEX >= 0x030b0000
                PyObject *co_varnames = PyCode_GetVarnames(f_code);
#        else
                PyObject *co_varnames = PyObject_GetAttrString((PyObject *) f_code, "co_varnames");
#        endif
                PyObject *self_arg = non_limited_api::PyTuple_GET_ITEM_(co_varnames, 0);
                Py_DECREF(co_varnames);
                PyObject *self_caller = dict_getitem(locals, self_arg);
                Py_DECREF(locals);
                if (self_caller == self.ptr()) {
                    Py_DECREF(f_code);
                    Py_DECREF(frame);
                    return;
                }
            }
        }
        Py_DECREF(f_code);
        Py_DECREF(frame);
    }
#    else
    PyFrameObject *frame = PyThreadState_Get()->frame;
    if (frame != nullptr && (std::string) str(frame->f_code->co_name) == name
        && frame->f_code->co_argcount > 0) {
        PyFrame_FastToLocals(frame);
        PyObject *self_caller
            = dict_getitem(frame->f_locals, non_limited_api::PyTuple_GET_ITEM_(frame->f_code->co_varnames, 0));
        if (self_caller == self.ptr()) {
            return;
        }
    }
#    endif

#else
    /* PyPy currently doesn't provide a detailed cpyext emulation of
       frame objects, so we have to emulate this using Python. This
       is going to be slow..*/
    dict d;
    d["self"] = self;
    d["name"] = pybind11::str(name);
    PyObject *result
        = PyRun_String("import inspect\n"
                       "frame = inspect.currentframe()\n"
                       "if frame is not None:\n"
                       "    frame = frame.f_back\n"
                       "    if frame is not None and str(frame.f_code.co_name) == name and "
                       "frame.f_code.co_argcount > 0:\n"
                       "        self_caller = frame.f_locals[frame.f_code.co_varnames[0]]\n"
                       "        if self_caller == self:\n"
                       "            self = None\n",
                       Py_file_input,
                       d.ptr(),
                       d.ptr());
    if (result == nullptr)
        throw error_already_set();
    Py_DECREF(result);
    if (d["self"].is_none())
        return;
#endif

    ret = override;
}

void pybind11::non_limited_api::pybind11NLA_initialize_interpreter(
    PyConfig *config,
    int argc,
    const char *const *argv,
    bool add_program_dir_to_path
)
{
    detail::precheck_interpreter();
    PyStatus status = ::PyConfig_SetBytesArgv(config, argc, const_cast<char *const *>(argv));
    if (::PyStatus_Exception(status) != 0) {
        // A failure here indicates a character-encoding failure or the python
        // interpreter out of memory. Give up.
        ::PyConfig_Clear(config);
        throw std::runtime_error(PyStatus_IsError(status) != 0 ? status.err_msg
                                                               : "Failed to prepare CPython");
    }
    status = ::Py_InitializeFromConfig(config);
    if (::PyStatus_Exception(status) != 0) {
        ::PyConfig_Clear(config);
        throw std::runtime_error(PyStatus_IsError(status) != 0 ? status.err_msg
                                                               : "Failed to init CPython");
    }
    if (add_program_dir_to_path) {
        PyRun_SimpleString("import sys, os.path; "
                           "sys.path.insert(0, "
                           "os.path.abspath(os.path.dirname(sys.argv[0])) "
                           "if sys.argv and os.path.exists(sys.argv[0]) else '')");
    }
    ::PyConfig_Clear(config);
}

void pybind11::non_limited_api::pybind11NLA_initialize_interpreter2(
    bool init_signal_handlers,
    int argc,
    const char *const *argv,
    bool add_program_dir_to_path)
{
#if PY_VERSION_HEX < PYBIND11_PYCONFIG_SUPPORT_PY_VERSION_HEX
    detail::initialize_interpreter_pre_pyconfig(
        init_signal_handlers, argc, argv, add_program_dir_to_path);
#else
    PyConfig config;
    ::PyConfig_InitPythonConfig(&config);
    // See PR #4473 for background
    config.parse_argv = 0;

    config.install_signal_handlers = init_signal_handlers ? 1 : 0;
    initialize_interpreter(&config, argc, argv, add_program_dir_to_path);
#endif
}

bool pybind11::non_limited_api::pybind11NLA_PyObjectIsInstanceWithOneOfTpNames(PyObject *obj,
                                               std::initializer_list<const char *> tp_names) {
    if (PyType_Check(obj)) {
        return false;
    }
    const char *obj_tp_name = Py_TYPE(obj)->tp_name;
    for (const auto *tp_name : tp_names) {
        if (std::strcmp(obj_tp_name, tp_name) == 0) {
            return true;
        }
    }
    return false;
}

PyInterpreterState *pybind11::non_limited_api::pybind11NLA_PyInterpreterState_Get() {
    #if PY_VERSION_HEX < 0x03090000
    return ::_PyInterpreterState_Get();
    #else
    return ::PyInterpreterState_Get();
    #endif
}
