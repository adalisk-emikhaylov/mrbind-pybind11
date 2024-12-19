// Copyright (c) 2024 The pybind Community.

#pragma once

#include <pybind11/pytypes.h>

#include "common.h"
#include "internals.h"

#include <typeinfo>

PYBIND11_NAMESPACE_BEGIN(PYBIND11_NAMESPACE)
PYBIND11_NAMESPACE_BEGIN(detail)

// Forward declaration needed here: Refactoring opportunity.
extern "C" inline PyObject *pybind11_object_new(PyTypeObject *type, PyObject *, PyObject *);

inline bool type_is_managed_by_our_internals(PyTypeObject *type_obj) {
    return non_limited_api::type_is_managed_by_our_internals(type_obj);
}

inline bool is_instance_method_of_type(PyTypeObject *type_obj, PyObject *attr_name) {
    return non_limited_api::is_instance_method_of_type(type_obj, attr_name);
}

inline object try_get_cpp_conduit_method(PyObject *obj) {
    if (PyType_Check(obj)) {
        return object();
    }
    PyTypeObject *type_obj = Py_TYPE(obj);
    str attr_name("_pybind11_conduit_v1_");
    bool assumed_to_be_callable = false;
    if (type_is_managed_by_our_internals(type_obj)) {
        if (!is_instance_method_of_type(type_obj, attr_name.ptr())) {
            return object();
        }
        assumed_to_be_callable = true;
    }
    PyObject *method = PyObject_GetAttr(obj, attr_name.ptr());
    if (method == nullptr) {
        PyErr_Clear();
        return object();
    }
    if (!assumed_to_be_callable && PyCallable_Check(method) == 0) {
        Py_DECREF(method);
        return object();
    }
    return reinterpret_steal<object>(method);
}

inline void *try_raw_pointer_ephemeral_from_cpp_conduit(handle src,
                                                        const std::type_info *cpp_type_info) {
    object method = try_get_cpp_conduit_method(src.ptr());
    if (method) {
        capsule cpp_type_info_capsule(const_cast<void *>(static_cast<const void *>(cpp_type_info)),
                                      typeid(std::type_info).name());
        object cpp_conduit = method(bytes(PYBIND11_PLATFORM_ABI_ID),
                                    cpp_type_info_capsule,
                                    bytes("raw_pointer_ephemeral"));
        if (isinstance<capsule>(cpp_conduit)) {
            return reinterpret_borrow<capsule>(cpp_conduit).get_pointer();
        }
    }
    return nullptr;
}

#define PYBIND11_HAS_CPP_CONDUIT 1

PYBIND11_NAMESPACE_END(detail)
PYBIND11_NAMESPACE_END(PYBIND11_NAMESPACE)
