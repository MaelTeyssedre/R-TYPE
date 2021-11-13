/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** LibLoader
*/


#include "LibLoader.hpp"

LibLoader::LibLoader()
{
    #ifdef _WIN32
        _dlLoaderWindows = DlLoaderWindows();
    #endif
    #ifdef __linux__
        _dlLoaderUnix = DlLoaderUnix();
    #endif

    listLibDirectory(LIBS_PATH);
    loadLibs();
}

LibLoader::~LibLoader() {
    #ifdef __linux__
        for (void *ptr : _libsPtrUnix)
            _dlLoaderUnix.closeLib(ptr);
    #endif
    #ifdef _WIN32
        for (HMODULE ptr : _libsPtrWindows)
            _dlLoaderWindows.closeLib(ptr);
    #endif
}

std::vector<IElement *> LibLoader::getLibs() const {
    return _libs;
}

void LibLoader::loadLibs() {
    for (size_t i = 0; i < _libsfiles.size(); i++) {
        #ifdef __linux__
            _libsPtrUnix.push_back(_dlLoaderUnix.loadLib(_libsfiles[i]));
            _libs.push_back((IElement*)_dlLoaderUnix.loadFunc(std::string("allocator"), _libsPtrUnix[i])());
        #endif
        #ifdef _WIN32
            _libsPtrWindows.push_back(_dlLoaderWindows.loadLib(_libsfiles[i]));
            _libs.push_back(_dlLoaderWindows.loadFunc(std::string("allocator"), _libsPtrWindows[i])());
        #endif
    }
}

void LibLoader::listLibDirectory(std::string path) {
    for (const auto entry : std::filesystem::directory_iterator(path))
        _libsfiles.push_back(entry.path().string());
}