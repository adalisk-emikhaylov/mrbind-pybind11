// Intentionally not using `#pragma once` because sometimes we need to include this more than once.
#ifndef PYBIND11_NONLIMITEDAPI_H_
#define PYBIND11_NONLIMITEDAPI_H_

#include "common.h"

#include <filesystem>
#if !defined(__APPLE__) && !defined(_WIN32)
#include <dlfcn.h> // For `dlopen` and friends.
#endif

#ifdef Py_LIMITED_API
typedef struct _heaptypeobject PyHeapTypeObject;
typedef struct _typeobject PyTypeObject;
typedef struct { double real; double imag; } Py_complex;
typedef struct PyConfig PyConfig;

// We must not use this in our own API below, because the definitions are different in different Python versions.
// Instead we provide our own type `Py_buffer_` below for use in our own API.
// This one is defined solely for the rest of the Pybind.
typedef void Py_buffer;
#endif

PYBIND11_NAMESPACE_BEGIN(PYBIND11_NAMESPACE)

// --- Forward declarations: [
class buffer;
class cpp_function;
class function;
class gil_scoped_acquire;
class handle;
class memoryview;
struct buffer_info;
struct InitializingFunctionRecordDeleter;

PYBIND11_NAMESPACE_BEGIN(detail)
class generic_type;
struct enum_base;
struct error_fetch_and_normalize;
struct function_record;
struct internals;
struct type_record;
template <typename type, typename SFINAE /*= void // can't redefine default argument*/> class type_caster;
template <> class type_caster<bool, void/*see above*/>;
PYBIND11_NAMESPACE_END(detail)
// --- ] End forward declarations.

PYBIND11_NAMESPACE_BEGIN(non_limited_api)

// This is separate from the rest of the forward declarations, because the target struct is unnamed and I can't find a good way to forward-declare it.
typedef struct PyStatus_ PyStatus_;
// This is separate from the rest of the forward declarations because different Python versions define the original `Py_buffer` differently,
//   leading to mangling mismatches. So we can't use that in the interface and have to use our own type.
// It's always used as a pointer, so `Py_buffer_ *` becomes `void *`.
typedef void Py_buffer_;

using namespace detail;

#if defined(__clang__)
// warning: 'X' has C-linkage specified, but returns user-defined type 'std::string' (aka 'basic_string<char>') which is incompatible with C [-Wreturn-type-c-linkage]
#define PYBIND11_NONLIMITEDAPI_SILENCE_EXTERN_C_WARNING(...) _Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Wreturn-type-c-linkage\"") __VA_ARGS__ _Pragma("clang diagnostic pop")
#elif defined(_MSC_VER)
// 'X' has C-linkage specified, but returns UDT 'std::basic_string<char,std::char_traits<char>,std::allocator<char>>' which is incompatible with C
#define PYBIND11_NONLIMITEDAPI_SILENCE_EXTERN_C_WARNING(...) _Pragma("warning(push)") _Pragma("warning(disable: 4190)") __VA_ARGS__ _Pragma("warning(pop)")
#else
#define PYBIND11_NONLIMITEDAPI_SILENCE_EXTERN_C_WARNING(...) __VA_ARGS__
#endif

#ifndef PYBIND11_NONLIMITEDAPI_IMPORT
#ifdef _WIN32
#define PYBIND11_NONLIMITEDAPI_IMPORT __declspec(dllimport)
#define PYBIND11_NONLIMITEDAPI_EXPORT __declspec(dllexport)
#else
#define PYBIND11_NONLIMITEDAPI_IMPORT __attribute__((__visibility__("default")))
#define PYBIND11_NONLIMITEDAPI_EXPORT __attribute__((__visibility__("default")))
#endif
#endif
#ifndef PYBIND11_NONLIMITEDAPI_API
#define PYBIND11_NONLIMITEDAPI_API PYBIND11_NONLIMITEDAPI_IMPORT
#endif
#ifndef PYBIND11_NONLIMITEDAPI_API_IMPL
#define PYBIND11_NONLIMITEDAPI_API_IMPL
#endif

// `app_suffix` can be null.
// `library_dir` can be empty, then it's ignored.
PYBIND11_NONLIMITEDAPI_API void EnsureSharedLibraryIsLoaded(bool use_version_specific_lib, const char *app_suffix, std::filesystem::path library_dir);

#ifndef PYBIND11_NONLIMITEDAPI_FUNC
#define PYBIND11_NONLIMITEDAPI_FUNC(ret_, func_, params_, param_uses_) \
    PYBIND11_NONLIMITEDAPI_API ret_ func_ params_; \
    PYBIND11_NONLIMITEDAPI_SILENCE_EXTERN_C_WARNING( \
        extern "C" PYBIND11_NONLIMITEDAPI_API_IMPL ret_ pybind11NLA_##func_ params_; \
    )
#endif

// Trailing `_` in some functions below to avoid conflicts with macros with the same names.
// The macros are present even in the limited API, but they are broken.

PYBIND11_NONLIMITEDAPI_FUNC(void, PyBuffer_Release, (Py_buffer_ *buf), (buf))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyBuffer_delete, (Py_buffer_ *buf), (buf))
PYBIND11_NONLIMITEDAPI_FUNC(int, PyGILState_Check, (), ())
PYBIND11_NONLIMITEDAPI_FUNC(PyObject **, PySequence_Fast_ITEMS_, (PyObject *obj), (obj))
PYBIND11_NONLIMITEDAPI_FUNC(char *, PyByteArray_AS_STRING_, (PyObject *obj), (obj))
PYBIND11_NONLIMITEDAPI_FUNC(ssize_t, PyByteArray_GET_SIZE_, (PyObject *obj), (obj))
PYBIND11_NONLIMITEDAPI_FUNC(ssize_t, PyTuple_GET_SIZE_, (PyObject *obj), (obj))
PYBIND11_NONLIMITEDAPI_FUNC(PyObject *, PyTuple_GET_ITEM_, (PyObject *obj, ssize_t i), (obj, i))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyTuple_SET_ITEM_, (PyObject *obj, ssize_t i, PyObject *value), (obj, i, value))
PYBIND11_NONLIMITEDAPI_FUNC(ssize_t, PyList_GET_SIZE_, (PyObject *obj), (obj))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyList_SET_ITEM_, (PyObject *obj, ssize_t i, PyObject *value), (obj, i, value))
PYBIND11_NONLIMITEDAPI_FUNC(PyObject *, PyStaticMethod_New, (PyObject *obj), (obj))
PYBIND11_NONLIMITEDAPI_FUNC(int, PyObject_CheckBuffer_, (PyObject *obj), (obj)) // This is a macro only in Python 3.8, not in the latter versions. So we have to use a different name here.
PYBIND11_NONLIMITEDAPI_FUNC(ssize_t, PyObject_LengthHint, (PyObject *obj, ssize_t i), (obj, i))
PYBIND11_NONLIMITEDAPI_FUNC(PyObject **, _PyObject_GetDictPtr, (PyObject *obj), (obj))
PYBIND11_NONLIMITEDAPI_FUNC(PyObject *, PyCFunction_GET_SELF_, (PyObject *obj), (obj))

PYBIND11_NONLIMITEDAPI_FUNC(const char *, obj_class_name, (PyObject *obj), (obj))
PYBIND11_NONLIMITEDAPI_FUNC(std::string, error_fetch_and_normalize_format_value_and_trace, (const error_fetch_and_normalize &self), (self))
PYBIND11_NONLIMITEDAPI_FUNC(void, get_function, (handle &ret, handle value), (ret, value))
PYBIND11_NONLIMITEDAPI_FUNC(bool, PyStaticMethod_Check, (PyObject *o), (o))
PYBIND11_NONLIMITEDAPI_FUNC(void, buffer_info_ctor, (buffer_info &self, Py_buffer_ *view, bool ownview), (self, view, ownview))
PYBIND11_NONLIMITEDAPI_FUNC(void, handle_throw_gilstate_error, (const handle &self, const std::string &function_name), (self, function_name))
PYBIND11_NONLIMITEDAPI_FUNC(void, buffer_request, (buffer_info &ret, const buffer &self, bool writable), (ret, self, writable))
PYBIND11_NONLIMITEDAPI_FUNC(void, memoryview_ctor, (memoryview &self, const buffer_info &info), (self, info))
PYBIND11_NONLIMITEDAPI_FUNC(void, memoryview_from_memory, (memoryview &ret, void *mem, ssize_t size, bool readonly), (ret, mem, size, readonly))
PYBIND11_NONLIMITEDAPI_FUNC(void, memoryview_from_buffer, (memoryview &ret, void *ptr, ssize_t itemsize, const char *format, any_container<ssize_t> shape, any_container<ssize_t> strides, bool readonly), (ret, ptr, itemsize, format, std::move(shape), std::move(strides), readonly))
PYBIND11_NONLIMITEDAPI_FUNC(internals &, get_internals, (), ())
PYBIND11_NONLIMITEDAPI_FUNC(bool, type_is_managed_by_our_internals, (PyTypeObject *type_obj), (type_obj))
PYBIND11_NONLIMITEDAPI_FUNC(bool, is_instance_method_of_type, (PyTypeObject *type_obj, PyObject *attr_name), (type_obj, attr_name))
PYBIND11_NONLIMITEDAPI_FUNC(void, all_type_info_populate, (PyTypeObject *t, std::vector<type_info *> &bases), (t, bases))
PYBIND11_NONLIMITEDAPI_FUNC(bool, type_caster_bool_load, (type_caster<bool, void> &self, handle src, bool convert), (self, src, convert))
PYBIND11_NONLIMITEDAPI_FUNC(bool, type_caster_bool_is_numpy_bool, (handle object), (object))
PYBIND11_NONLIMITEDAPI_FUNC(void, type_record_add_base, (type_record &self, const std::type_info &base, void *(*caster)(void *) ), (self, base, caster))
PYBIND11_NONLIMITEDAPI_FUNC(std::string, get_fully_qualified_tp_name, (PyTypeObject *type), (type))
PYBIND11_NONLIMITEDAPI_FUNC(void, traverse_offset_bases, (void *valueptr, const type_info *tinfo, instance *self, bool (*f)(void *, instance *)), (valueptr, tinfo, self, f))
PYBIND11_NONLIMITEDAPI_FUNC(PyObject *, make_new_instance, (PyTypeObject *type), (type))
PYBIND11_NONLIMITEDAPI_FUNC(PyObject *, make_new_python_type, (const type_record &rec), (rec))
PYBIND11_NONLIMITEDAPI_FUNC(void, gil_scoped_acquire_ctor, (gil_scoped_acquire &self), (self))
PYBIND11_NONLIMITEDAPI_FUNC(void, gil_scoped_acquire_inc_ref, (gil_scoped_acquire &self), (self))
PYBIND11_NONLIMITEDAPI_FUNC(void, gil_scoped_acquire_dec_ref, (gil_scoped_acquire &self), (self))
PYBIND11_NONLIMITEDAPI_FUNC(void, cpp_function_initialize_generic, (cpp_function &self, std::unique_ptr<detail::function_record, InitializingFunctionRecordDeleter> &&unique_rec, const char *text, const std::type_info *const *types, size_t args), (self, std::move(unique_rec), text, types, args))
PYBIND11_NONLIMITEDAPI_FUNC(void, generic_type_mark_parents_nonsimple, (generic_type &self, PyTypeObject *value), (self, value))
PYBIND11_NONLIMITEDAPI_FUNC(void, generic_type_install_buffer_funcs, (generic_type &self, buffer_info *(*get_buffer)(PyObject *, void *), void *get_buffer_data), (self, get_buffer, get_buffer_data))
PYBIND11_NONLIMITEDAPI_FUNC(void, enum_base_init, (enum_base &self, bool is_arithmetic, bool is_convertible), (self, is_arithmetic, is_convertible))
PYBIND11_NONLIMITEDAPI_FUNC(void, get_type_override, (function &ret, const void *this_ptr, const type_info *this_type, const char *name), (ret, this_ptr, this_type, name))
PYBIND11_NONLIMITEDAPI_FUNC(Py_complex, PyComplex_AsCComplex, (PyObject *obj), (obj))
PYBIND11_NONLIMITEDAPI_FUNC(const char *, PyUnicode_AsUTF8AndSize, (PyObject *unicode, ssize_t *size), (unicode, size))
PYBIND11_NONLIMITEDAPI_FUNC(PyObject *, PyRun_String_, (const char *str, int s, PyObject *g, PyObject *l), (str, s, g, l))
PYBIND11_NONLIMITEDAPI_FUNC(FILE *, _Py_fopen_obj, (PyObject *path, const char *mode), (path, mode))
PYBIND11_NONLIMITEDAPI_FUNC(PyObject *, PyRun_FileEx_, (FILE *fp, const char *p, int s, PyObject *g, PyObject *l, int c), (fp, p, s, g, l, c))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyMem_RawFree, (void *ptr), (ptr))
PYBIND11_NONLIMITEDAPI_FUNC(void, initialize_interpreter, (PyConfig *config, int argc, const char *const *argv, bool add_program_dir_to_path), (config, argc, argv, add_program_dir_to_path))
PYBIND11_NONLIMITEDAPI_FUNC(void, initialize_interpreter2, (bool init_signal_handlers, int argc, const char *const *argv, bool add_program_dir_to_path), (init_signal_handlers, argc, argv, add_program_dir_to_path))
PYBIND11_NONLIMITEDAPI_FUNC(PyConfig *, PyConfig_new, (), ())
PYBIND11_NONLIMITEDAPI_FUNC(void, PyConfig_delete, (PyConfig *c), (c))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyConfig_InitPythonConfig, (PyConfig *c), (c))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyConfig_Clear, (PyConfig *c), (c))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyConfig_set_site_import, (PyConfig *c, int value), (c, value))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyConfig_set_parse_argv, (PyConfig *c, int value), (c, value))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyConfig_set_install_signal_handlers, (PyConfig *c, int value), (c, value))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyConfig_set_isolated, (PyConfig *c, int value), (c, value))
PYBIND11_NONLIMITEDAPI_FUNC(wchar_t **, PyConfig_home_ptr, (PyConfig *c), (c))
PYBIND11_NONLIMITEDAPI_FUNC(void, PyStatus_delete, (PyStatus_ *ptr), (ptr))
PYBIND11_NONLIMITEDAPI_FUNC(PyStatus_ *, PyConfig_SetString, (PyConfig *config, wchar_t **config_str, const wchar_t *str), (config, config_str, str))
PYBIND11_NONLIMITEDAPI_FUNC(PyStatus_ *, PyConfig_SetBytesArgv, (PyConfig *config, ssize_t argc, char *const *argv), (config, argc, argv))
PYBIND11_NONLIMITEDAPI_FUNC(int, PyStatus_Exception, (const PyStatus_ *err), (err))
PYBIND11_NONLIMITEDAPI_FUNC(const char *, PyStatus_get_err_msg, (const PyStatus_ *s), (s))
PYBIND11_NONLIMITEDAPI_FUNC(PyStatus_ *, Py_InitializeFromConfig, (const PyConfig *config), (config))
PYBIND11_NONLIMITEDAPI_FUNC(bool, PyObjectIsInstanceWithOneOfTpNames, (PyObject *obj, std::initializer_list<const char *> tp_names), (obj, tp_names))
PYBIND11_NONLIMITEDAPI_FUNC(int, PyGen_Check_, (PyObject *obj), (obj))
PYBIND11_NONLIMITEDAPI_FUNC(PyInterpreterState *, PyInterpreterState_Get, (), ())

PYBIND11_NAMESPACE_END(non_limited_api)
PYBIND11_NAMESPACE_END(PYBIND11_NAMESPACE)

#ifndef PYBIND11_NONLIMITEDAPI_LIB_SUFFIX_FOR_MODULE
#define PYBIND11_NONLIMITEDAPI_LIB_SUFFIX_FOR_MODULE nullptr
#endif

#ifdef PYBIND11_NONLIMITEDAPI_LIB_PATH_RELATIVE_TO_PARENT_LIB
#define PYBIND11_NONLIMITEDAPI_LIB_PATH_RELATIVE_TO_PARENT_LIB_WITH_SLASH / PYBIND11_NONLIMITEDAPI_LIB_PATH_RELATIVE_TO_PARENT_LIB
#else
#define PYBIND11_NONLIMITEDAPI_LIB_PATH_RELATIVE_TO_PARENT_LIB_WITH_SLASH
#endif

#ifdef _WIN32
#define PYBIND11_NONLIMITEDAPI_GET_SHARED_LIBRARY_DIR(module_) \
    []{ \
        HMODULE module_handle = NULL; \
        if (!GetModuleHandleExW( \
            GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, \
            (LPCTSTR)PYBIND11_CONCAT(PyInit_, module_), \
            &module_handle \
        )) \
        { \
            throw std::runtime_error( "pybind11 non-limited-api: Failed to get the self library path." ); \
        } \
        \
        wchar_t path[MAX_PATH]; \
        if (auto size = GetModuleFileNameW( module_handle, path, MAX_PATH ); size == 0) \
            throw std::runtime_error( "pybind11 non-limited-api: Failed to get the self library path." ); \
        else if (size == MAX_PATH) \
            throw std::runtime_error( "pybind11 non-limited-api: The self library path is too long." ); \
        \
        return std::filesystem::path(path).parent_path() PYBIND11_NONLIMITEDAPI_LIB_PATH_RELATIVE_TO_PARENT_LIB_WITH_SLASH; \
    }()
#else
#define PYBIND11_NONLIMITEDAPI_GET_SHARED_LIBRARY_DIR(module_) \
    []{ \
        Dl_info info; \
        if (!dladdr((void*)PYBIND11_CONCAT(PyInit_, module_), &info)) \
            throw std::runtime_error( "pybind11 non-limited-api: Failed to get the self library path." ); \
        return std::filesystem::path(info.dli_fname).parent_path() PYBIND11_NONLIMITEDAPI_LIB_PATH_RELATIVE_TO_PARENT_LIB_WITH_SLASH; \
    }()
#endif

#define PYBIND11_MODULE(name, variable, ...)                                                      \
    static ::pybind11::module_::module_def PYBIND11_CONCAT(pybind11_module_def_, name)            \
        PYBIND11_MAYBE_UNUSED;                                                                    \
    PYBIND11_MAYBE_UNUSED                                                                         \
    static void PYBIND11_CONCAT(pybind11_init_, name)(::pybind11::module_ &);                     \
    PYBIND11_PLUGIN_IMPL(name) {                                                                  \
        pybind11::non_limited_api::EnsureSharedLibraryIsLoaded(true, PYBIND11_NONLIMITEDAPI_LIB_SUFFIX_FOR_MODULE, PYBIND11_NONLIMITEDAPI_GET_SHARED_LIBRARY_DIR(name)); \
        PYBIND11_ENSURE_INTERNALS_READY                                                           \
        auto m = ::pybind11::module_::create_extension_module(                                    \
            PYBIND11_TOSTRING(name),                                                              \
            nullptr,                                                                              \
            &PYBIND11_CONCAT(pybind11_module_def_, name),                                         \
            ##__VA_ARGS__);                                                                       \
        try {                                                                                     \
            PYBIND11_CONCAT(pybind11_init_, name)(m);                                             \
            return m.ptr();                                                                       \
        }                                                                                         \
        PYBIND11_CATCH_INIT_EXCEPTIONS                                                            \
    }                                                                                             \
    void PYBIND11_CONCAT(pybind11_init_, name)(::pybind11::module_ & (variable))

#endif // PYBIND11_NONLIMITEDAPI_H_
