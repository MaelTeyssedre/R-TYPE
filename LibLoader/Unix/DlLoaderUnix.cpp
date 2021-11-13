/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** DlLoaderUnix
*/

#include "DlLoaderUnix.hpp"

void *DlLoaderUnix::loadLib(std::string path) {
    void *lib = dlopen(path.c_str(), RTLD_NOW | RTLD_LAZY);
    if (!lib)
        throw std::invalid_argument("Cannot open lib");
    return lib;
}

allocClass DlLoaderUnix::loadFunc(std::string function, void *ptr) {
    return (IElement *(*)())dlsym(ptr, function.c_str());
}

void DlLoaderUnix::closeLib(void *ptr) {
    dlclose(ptr);
}