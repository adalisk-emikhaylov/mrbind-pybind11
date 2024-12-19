cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 17) # For `std::filesystem::weakly_canonical()`.


find_package(Python COMPONENTS Interpreter Development)

project(pybind11nonlimitedapi_stubs)
add_library(pybind11nonlimitedapi_stubs SHARED non_limited_api_stubs.cpp)
target_include_directories(pybind11nonlimitedapi_stubs PUBLIC ../../include)
target_include_directories(pybind11nonlimitedapi_stubs PUBLIC ${Python_INCLUDE_DIRS})

install(TARGETS pybind11nonlimitedapi_stubs
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

set(PYBIND11_NONLIMITEDAPI_PYTHON_HEX_VERSION "" CACHE STRING "A hex Python version to bake into the library, e.g. `0x030800f0` for 3.8 (the `f0` suffix is always there and means a release version).")
set(PYBIND11_NONLIMITEDAPI_SUFFIX "" CACHE STRING "A custom suffix to append to the built library name. Should normally be `[_AppName][_X.Y]`, where X,Y is the Python version.")
if (PYBIND11_NONLIMITEDAPI_PYTHON_HEX_VERSION STREQUAL "")
  message("Not building pybind11nonlimitedapi because no Python version is specified.")
else()
  set(PYBIND11_NONLIMITEDAPI_LIBNAME "pybind11nonlimitedapi${PYBIND11_NONLIMITEDAPI_SUFFIX}")
  project(${PYBIND11_NONLIMITEDAPI_LIBNAME})
  add_library(${PYBIND11_NONLIMITEDAPI_LIBNAME} SHARED non_limited_api.cpp)
  target_include_directories(${PYBIND11_NONLIMITEDAPI_LIBNAME} PUBLIC ../../include)
  target_include_directories(${PYBIND11_NONLIMITEDAPI_LIBNAME} PUBLIC ${Python_INCLUDE_DIRS})
  target_link_libraries(${PYBIND11_NONLIMITEDAPI_LIBNAME} PUBLIC pybind11nonlimitedapi_stubs)
  target_link_libraries(${PYBIND11_NONLIMITEDAPI_LIBNAME} PUBLIC Python::Python)

  install(TARGETS ${PYBIND11_NONLIMITEDAPI_LIBNAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
  )
endif()
