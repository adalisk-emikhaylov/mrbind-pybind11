#define PYBIND11_NONLIMITEDAPI_API PYBIND11_NONLIMITEDAPI_EXPORT

#include "pybind11/pybind11.h"

#ifdef _WIN32
#define PYBIND11_NONLIMITEDAPI_DLOPEN(dir, file) LoadLibraryW((dir + std::wstring(file.begin(), file.end()) + L".dll").c_str())
#define PYBIND11_NONLIMITEDAPI_DLOPEN_ERROR std::to_string(GetLastError()).c_str()
#else
#ifdef __APPLE__
#define PYBIND11_NONLIMITEDAPI_SHLIB_SUFFIX ".dylib"
#else
#define PYBIND11_NONLIMITEDAPI_SHLIB_SUFFIX ".so"
#endif
#include <dlfcn.h> // For `dlopen` and friends.
#define PYBIND11_NONLIMITEDAPI_DLOPEN(dir, file) dlopen((dir + "lib" + file + PYBIND11_NONLIMITEDAPI_SHLIB_SUFFIX).c_str(), RTLD_NOW | RTLD_GLOBAL)
#define PYBIND11_NONLIMITEDAPI_DLOPEN_ERROR dlerror()
#endif

static void *&SharedLibraryHandle()
{
    static void *ret = nullptr;
    return ret;
}

void pybind11::non_limited_api::EnsureSharedLibraryIsLoaded(bool use_version_specific_lib, const char *app_suffix, std::filesystem::path library_dir, std::vector<std::filesystem::path> library_dir_suffixes)
{
    void *&handle = SharedLibraryHandle();
    if (handle)
        return; // Already loaded.

    std::string file = "pybind11nonlimitedapi";
    if (app_suffix)
    {
        file += '_';
        file += app_suffix;
    }

    if (use_version_specific_lib)
    {
        std::string_view ver = Py_GetVersion();

        // Get `X.Y` from the beginning of the version string.
        if (auto sep = ver.find_first_of('.'); sep != std::string_view::npos)
        {
            sep = ver.find_first_of(". ", sep + 1);
            if (sep != std::string_view::npos)
            {
                file += '_';
                file += ver.substr(0, sep);
            }
        }
    }

    if (library_dir_suffixes.empty())
        library_dir_suffixes.push_back(".");

    for (const auto &suffix : library_dir_suffixes)
    {
        // Get a path to this library.
        #ifdef _WIN32
        std::wstring dir;
        #else
        std::string dir;
        #endif
        if (!library_dir.empty())
        {
            dir += library_dir.native();
            dir += '/';
        }
        if (suffix != ".")
        {
            dir += suffix.native();
            dir += '/';
        }

        handle = PYBIND11_NONLIMITEDAPI_DLOPEN(dir, file);
        if (handle)
            break;
    }
    if (!handle)
    {
        std::fprintf(stderr, "pybind11 non-limited-api: Failed to load library `%s` with error `%s`.\n", file.c_str(), PYBIND11_NONLIMITEDAPI_DLOPEN_ERROR);
        std::exit(1);
    }
}

// Some pybind functions that have static variables and therefore must be defined out of line:
pybind11::detail::internals **&pybind11::detail::get_internals_pp() {
    static internals **internals_pp = nullptr;
    return internals_pp;
}
pybind11::detail::local_internals &pybind11::detail::get_local_internals() {
    // Current static can be created in the interpreter finalization routine. If the later will be
    // destroyed in another static variable destructor, creation of this static there will cause
    // static deinitialization fiasco. In order to avoid it we avoid destruction of the
    // local_internals static. One can read more about the problem and current solution here:
    // https://google.github.io/styleguide/cppguide.html#Static_and_Global_Variables
    static auto *locals = new local_internals();
    return *locals;
}

#ifdef _WIN32
#define PYBIND11_NONLIMITEDAPI_LOAD_SYMBOL(name_) (void *)GetProcAddress((HMODULE)SharedLibraryHandle(), name_)
#else
#define PYBIND11_NONLIMITEDAPI_LOAD_SYMBOL(name_) dlsym(SharedLibraryHandle(), name_)
#endif

#undef PYBIND11_NONLIMITEDAPI_FUNC
#define PYBIND11_NONLIMITEDAPI_FUNC(ret_, func_, params_, param_uses_) \
    ret_ func_ params_ \
    { \
        using F_ = ret_ (*) params_; \
        static F_ f_ = (F_)PYBIND11_NONLIMITEDAPI_LOAD_SYMBOL("pybind11NLA_" #func_); \
        return f_ param_uses_; \
    }

// `non_limited_api.h` is already a part of `pybind11.h`, but here we undefine its include guard and include it again!
#undef PYBIND11_NONLIMITEDAPI_H_
#include "pybind11/detail/non_limited_api.h"
