/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** DlLoaderUnix
*/

#include "DlLoaderUnix.hpp"

void *DlLoaderUnix::loadLib(std::string &path) {
    void *lib = dlopen(path.c_str(), RTLD_NOW);
    if (!lib)
        throw std::invalid_argument;
    return lib;
}

void *DlLoaderUnix::loadFunc(std::string &function, void *ptr) {
    return dlsym(ptr, function.c_str());
}

void DlLoaderUnix::closeLib(void *ptr) {
    dlclose(ptr);
}