#define PYBIND11_NONLIMITEDAPI_API PYBIND11_NONLIMITEDAPI_EXPORT

#include "pybind11/pybind11.h"

#ifdef _WIN32
#define PYBIND11_NONLIMITEDAPI_DLOPEN(dir, file) LoadLibraryW((dir + L'/' + std::wstring(file.begin(), file.end()) + ".dll").c_str())
#else
#define PYBIND11_NONLIMITEDAPI_DLOPEN(dir, file) dlopen((dir + '/' + file + ".so").c_str(), RTLD_NOW | RTLD_GLOBAL)
#endif

static void *&SharedLibraryHandle()
{
    static void *ret = nullptr;
    return ret;
}

void pybind11::non_limited_api::EnsureSharedLibraryIsLoaded(bool use_version_specific_lib, const char *app_suffix)
{
    void *&handle = SharedLibraryHandle();
    if (handle)
        return; // Already loaded.

    // Determine the executable directory.
    #if defined(__APPLE__)
    std::string dir = []{
        std::string ret(PATH_MAX);
        std::uint32_t size = std::uint32_t(ret.size() + 1);
        if (_NSGetExecutablePath(path, &size))
        {
            ret.resize(size - 1);
            if (_NSGetExecutablePath(path, &size))
                throw std::runtime_error( "Executable path is too long." );
        }
        if (auto sep = ret.find_last_of('/'); sep != std::string::npos)
            ret.resize(sep);
        return ret;
    }();
    #elif defined(_WIN32)
    #define PYBIND11_NONLIMITEDAPI_EXE_DIR
    std::wstring dir = []{
        std::wstring ret(MAX_PATH, '\0');
        if (auto out_size = GetModuleFileNameW(NULL, ret.data(), ret.size()); out_size == 0)
            throw std::runtime_error( "Failed to get executable path." );
        else if (size == ret.size())
            throw std::runtime_error( "Executable path is too long." );
        if (auto sep = ret.find_last_of('/'); sep != std::string::npos)
            ret.resize(sep);
        return ret;
    }()
    #else
    std::string dir = std::filesystem::weakly_canonical("/proc/self/exe").parent_path().string();
    #endif

    std::string file = "pybind11nonlimitedapi";
    if (app_suffix)
    {
        file += '_';
        file += app_suffix;
    }

    if (use_version_specific_lib)
    {
        std::string_view ver = Py_GetVersion();
        if (auto sep = ver.find_first_of(' '); sep != std::string_view::npos)
            ver = ver.substr(0, sep);

        file += '_';
        file += ver;
    }

    handle = PYBIND11_NONLIMITEDAPI_DLOPEN(dir, file);
    if (!handle)
    {
        std::fprintf(stderr, "pybind11 non-limited-api: Failed to load library: %s\n", file.c_str());
        std::exit(1);
    }
}

#ifdef _WIN32
#define PYBIND11_NONLIMITEDAPI_LOAD_SYMBOL(name_) GetProcAddress(SharedLibraryHandle(), name_)
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
