cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 17) # For `std::filesystem::weakly_canonical()`.


if (DEFINED PYBIND11_NONLIMITEDAPI_PYTHON_HEADERS_VERSION)
  find_package(Python ${PYBIND11_NONLIMITEDAPI_PYTHON_HEADERS_VERSION} EXACT REQUIRED COMPONENTS Interpreter Development)
else()
  find_package(Python REQUIRED COMPONENTS Interpreter Development)
endif()

option(PYBIND11_NONLIMITEDAPI_BUILD_STUBS "" ON)

if (${PYBIND11_NONLIMITEDAPI_BUILD_STUBS})
  project(pybind11nonlimitedapi_stubs)
  add_library(pybind11nonlimitedapi_stubs SHARED non_limited_api_stubs.cpp)
  target_include_directories(pybind11nonlimitedapi_stubs PUBLIC ../../include)
  target_include_directories(pybind11nonlimitedapi_stubs PUBLIC ${Python_INCLUDE_DIRS})

  install(TARGETS pybind11nonlimitedapi_stubs
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
  )
endif()

set(PYBIND11_NONLIMITEDAPI_PYTHON_MIN_VERSION_HEX "" CACHE STRING "A hex Python version to bake into the library, e.g. `0x030800f0` for 3.8 (the `f0` suffix is always there and means a release version).")
set(PYBIND11_NONLIMITEDAPI_SUFFIX "" CACHE STRING "A custom suffix to append to the built library name. Should normally be `[_AppName][_X.Y]`, where X,Y is the Python version.")
set(PYBIND11_NONLIMITEDAPI_LIBRARY_OUTPUT_DIR "" CACHE PATH "Replaces the library installation path for the shim.")
if (PYBIND11_NONLIMITEDAPI_PYTHON_MIN_VERSION_HEX STREQUAL "")
  message("Not building pybind11nonlimitedapi because no Python version is specified.")
else()
  set(PYBIND11_NONLIMITEDAPI_LIBNAME "pybind11nonlimitedapi${PYBIND11_NONLIMITEDAPI_SUFFIX}_${Python_VERSION_MAJOR}.${Python_VERSION_MINOR}")
  project(${PYBIND11_NONLIMITEDAPI_LIBNAME})
  add_library(${PYBIND11_NONLIMITEDAPI_LIBNAME} SHARED non_limited_api.cpp)
  target_include_directories(${PYBIND11_NONLIMITEDAPI_LIBNAME} PUBLIC ../../include)
  target_include_directories(${PYBIND11_NONLIMITEDAPI_LIBNAME} PUBLIC ${Python_INCLUDE_DIRS})
  target_link_libraries(${PYBIND11_NONLIMITEDAPI_LIBNAME} PUBLIC pybind11nonlimitedapi_stubs)
  target_link_libraries(${PYBIND11_NONLIMITEDAPI_LIBNAME} PUBLIC Python::Python)

  if (NOT(${PYBIND11_NONLIMITEDAPI_LIBRARY_OUTPUT_DIR} STREQUAL ""))
    set_target_properties(${PYBIND11_NONLIMITEDAPI_LIBNAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PYBIND11_NONLIMITEDAPI_LIBRARY_OUTPUT_DIR})
  endif()

  install(TARGETS ${PYBIND11_NONLIMITEDAPI_LIBNAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
  )
endif()
