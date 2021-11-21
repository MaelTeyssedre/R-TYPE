#include "DlLoaderWindows.hpp"

HMODULE DlLoaderWindows::loadLib(const std::string &path)
{
    HMODULE lib = LoadLibrary(path.c_str());
    if (!lib)
        throw std::runtime_error("Cannot load lib");
    return (lib);
}

DlLoaderWindows::allocClass DlLoaderWindows::loadFunc(const std::string &function, HMODULE hDLL)
{
    allocClass func = (allocClass)GetProcAddress(hDLL, function.c_str());
    if (!func)
        throw std::runtime_error("Cannot load function");
    return (func);
}

void DlLoaderWindows::closeLib(HMODULE hDLL)
{
    if (FreeLibrary(hDLL) == 0)
        throw std::runtime_error("Library closure error");
}
