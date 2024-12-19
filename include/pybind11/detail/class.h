/*
    pybind11/detail/class.h: Python C API implementation details for py::class_

    Copyright (c) 2017 Wenzel Jakob <wenzel.jakob@epfl.ch>

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE file.
*/

#pragma once

#include <pybind11/attr.h>
#include <pybind11/options.h>

#include "exception_translation.h"

PYBIND11_NAMESPACE_BEGIN(PYBIND11_NAMESPACE)
PYBIND11_NAMESPACE_BEGIN(detail)

#if !defined(PYPY_VERSION)
#    define PYBIND11_BUILTIN_QUALNAME
#    define PYBIND11_SET_OLDPY_QUALNAME(obj, nameobj)
#else
// In PyPy, we still set __qualname__ so that we can produce reliable function type
// signatures; in CPython this macro expands to nothing:
#    define PYBIND11_SET_OLDPY_QUALNAME(obj, nameobj)                                             \
        setattr((PyObject *) obj, "__qualname__", nameobj)
#endif

inline std::string get_fully_qualified_tp_name(PyTypeObject *type) {
    return non_limited_api::get_fully_qualified_tp_name(type);
}

inline PyTypeObject *type_incref(PyTypeObject *type) {
    Py_INCREF(type);
    return type;
}

/// For multiple inheritance types we need to recursively register/deregister base pointers for any
/// base classes with pointers that are difference from the instance value pointer so that we can
/// correctly recognize an offset base class pointer. This calls a function with any offset base
/// ptrs.
inline void traverse_offset_bases(void *valueptr,
                                  const detail::type_info *tinfo,
                                  instance *self,
                                  bool (*f)(void * /*parentptr*/, instance * /*self*/))
{
    non_limited_api::traverse_offset_bases(valueptr, tinfo, self, f);
}

inline bool register_instance_impl(void *ptr, instance *self) {
    with_instance_map(ptr, [&](instance_map &instances) { instances.emplace(ptr, self); });
    return true; // unused, but gives the same signature as the deregister func
}
inline bool deregister_instance_impl(void *ptr, instance *self) {
    return with_instance_map(ptr, [&](instance_map &instances) {
        auto range = instances.equal_range(ptr);
        for (auto it = range.first; it != range.second; ++it) {
            if (self == it->second) {
                instances.erase(it);
                return true;
            }
        }
        return false;
    });
}

inline void register_instance(instance *self, void *valptr, const type_info *tinfo) {
    register_instance_impl(valptr, self);
    if (!tinfo->simple_ancestors) {
        traverse_offset_bases(valptr, tinfo, self, register_instance_impl);
    }
}

inline bool deregister_instance(instance *self, void *valptr, const type_info *tinfo) {
    bool ret = deregister_instance_impl(valptr, self);
    if (!tinfo->simple_ancestors) {
        traverse_offset_bases(valptr, tinfo, self, deregister_instance_impl);
    }
    return ret;
}

/// Instance creation function for all pybind11 types. It allocates the internal instance layout
/// for holding C++ objects and holders.  Allocation is done lazily (the first time the instance is
/// cast to a reference or pointer), and initialization is done by an `__init__` function.
inline PyObject *make_new_instance(PyTypeObject *type)
{
    return non_limited_api::make_new_instance(type);
}

/// Instance creation function for all pybind11 types. It only allocates space for the
/// C++ object, but doesn't call the constructor -- an `__init__` function must do that.
extern "C" inline PyObject *pybind11_object_new(PyTypeObject *type, PyObject *, PyObject *) {
    return make_new_instance(type);
}

/// An `__init__` function constructs the C++ object. Users should provide at least one
/// of these using `py::init` or directly with `.def(__init__, ...)`. Otherwise, the
/// following default function will be used which simply throws an exception.
extern "C" inline int pybind11_object_init(PyObject *self, PyObject *, PyObject *) {
    PyTypeObject *type = Py_TYPE(self);
    std::string msg = get_fully_qualified_tp_name(type) + ": No constructor defined!";
    set_error(PyExc_TypeError, msg.c_str());
    return -1;
}

inline void add_patient(PyObject *nurse, PyObject *patient) {
    auto *instance = reinterpret_cast<detail::instance *>(nurse);
    instance->has_patients = true;
    Py_INCREF(patient);

    with_internals([&](internals &internals) { internals.patients[nurse].push_back(patient); });
}

inline void clear_patients(PyObject *self) {
    auto *instance = reinterpret_cast<detail::instance *>(self);
    std::vector<PyObject *> patients;

    with_internals([&](internals &internals) {
        auto pos = internals.patients.find(self);

        if (pos == internals.patients.end()) {
            pybind11_fail(
                "FATAL: Internal consistency check failed: Invalid clear_patients() call.");
        }

        // Clearing the patients can cause more Python code to run, which
        // can invalidate the iterator. Extract the vector of patients
        // from the unordered_map first.
        patients = std::move(pos->second);
        internals.patients.erase(pos);
    });

    instance->has_patients = false;
    for (PyObject *&patient : patients) {
        Py_CLEAR(patient);
    }
}

/// Clears all internal data from the instance and removes it from registered instances in
/// preparation for deallocation.
inline void clear_instance(PyObject *self) {
    auto *instance = reinterpret_cast<detail::instance *>(self);

    // Deallocate any values/holders, if present:
    for (auto &v_h : values_and_holders(instance)) {
        if (v_h) {

            // We have to deregister before we call dealloc because, for virtual MI types, we still
            // need to be able to get the parent pointers.
            if (v_h.instance_registered()
                && !deregister_instance(instance, v_h.value_ptr(), v_h.type)) {
                pybind11_fail(
                    "pybind11_object_dealloc(): Tried to deallocate unregistered instance!");
            }

            if (instance->owned || v_h.holder_constructed()) {
                v_h.type->dealloc(v_h);
            }
        }
    }
    // Deallocate the value/holder layout internals:
    instance->deallocate_layout();

    if (instance->weakrefs) {
        PyObject_ClearWeakRefs(self);
    }

    PyObject **dict_ptr = non_limited_api::_PyObject_GetDictPtr(self);
    if (dict_ptr) {
        Py_CLEAR(*dict_ptr);
    }

    if (instance->has_patients) {
        clear_patients(self);
    }
}

std::string error_string();

/// dynamic_attr: Allow the garbage collector to traverse the internal instance `__dict__`.
extern "C" inline int pybind11_traverse(PyObject *self, visitproc visit, void *arg) {
#if PY_VERSION_HEX >= 0x030D0000
    PyObject_VisitManagedDict(self, visit, arg);
#else
    PyObject *&dict = *non_limited_api::_PyObject_GetDictPtr(self);
    Py_VISIT(dict);
#endif
// https://docs.python.org/3/c-api/typeobj.html#c.PyTypeObject.tp_traverse
#if PY_VERSION_HEX >= 0x03090000
    Py_VISIT(Py_TYPE(self));
#endif
    return 0;
}

/// dynamic_attr: Allow the GC to clear the dictionary.
extern "C" inline int pybind11_clear(PyObject *self) {
#if PY_VERSION_HEX >= 0x030D0000
    PyObject_ClearManagedDict(self);
#else
    PyObject *&dict = *non_limited_api::_PyObject_GetDictPtr(self);
    Py_CLEAR(dict);
#endif
    return 0;
}

/** Create a brand new Python type according to the `type_record` specification.
    Return value: New reference. */
inline PyObject *make_new_python_type(const type_record &rec)
{
    return non_limited_api::make_new_python_type(rec);
}

PYBIND11_NAMESPACE_END(detail)
PYBIND11_NAMESPACE_END(PYBIND11_NAMESPACE)
