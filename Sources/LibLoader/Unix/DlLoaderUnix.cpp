#include "DlLoaderUnix.hpp"
#include <iostream>

void *DlLoaderUnix::loadLib(std::string path)
{
    void *lib = dlopen(path.c_str(), RTLD_NOW | RTLD_LAZY);
    if (!lib)
        throw std::runtime_error(dlerror());
    return lib;
}

DlLoaderUnix::allocClass DlLoaderUnix::loadFunc(std::string function, void *ptr)
{
    allocClass fun = (allocClass)dlsym(ptr, function.c_str());
    if (!fun)
        throw std::runtime_error(dlerror());
    return (fun);
}

void DlLoaderUnix::closeLib(void *ptr)
{
    if (dlclose(ptr))
        throw std::runtime_error(dlerror());
}