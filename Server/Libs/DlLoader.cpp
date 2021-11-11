/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** DlLoader
*/

#include "DlLoader.hpp"

#ifdef __linux__
    void *DlLoader::loadLib(std::string &path) {
        void *lib = dlopen(path.c_str(), RTLD_NOW);
        if (!lib)
            throw std::invalid_argument;
        return lib;
    }

    void *DlLoader::loadFunc(std::string &function, void *ptr) {
        return dlsym(ptr, function.c_str());
    }

    void DlLoader::closeLib(void *ptr) {
        dlclose(ptr);
    }
#endif

#ifdef _WIN32
    HMODULE DlLoader::loadLib(std::string path)
    {
        std::wstring widestr = std::wstring(path.begin(), path.end());
        return (_hDLL = LoadLibrary(widestr.c_str()));
    }

    HANDLE DlLoader::loadFunc(std::string &function, HMODULE hDLL)
    {
        return (_Proc = GetProcAddress(hDLL, function.c_str()));
    }

    void DlLoader::closeLib(HMODULE hDLL)
    {
        FreeLibrary(hDLL);
    }
#endif