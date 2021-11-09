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