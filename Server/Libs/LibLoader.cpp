/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** LibLoader
*/


#include "LibLoader.hpp"

LibLoader::LibLoader(std::vector<std::string> toLoad)
{
    #ifdef _WIN32
        _dlLoaderWindows = DlLoaderWindows();
    #endif
    #ifdef __linux__
        _dlLoaderUnix = DlLoaderUnix();
    #endif

    listLibDirectory(LIBS_PATH, toLoad);
    loadLibs();
}

LibLoader::LibLoader(const LibLoader &other)
{
    _libs = other._libs;
    _libsfiles = other._libsfiles;
    #ifdef __linux__
        _dlLoaderUnix = other._dlLoaderUnix;
        _libsPtrUnix = other._libsPtrUnix;
    #endif
    #ifdef _WIN32
        _dlLoaderWindows = other._dlLoaderWindows;
        _libsPtrWindows = other._libsPtrWindows;
    #endif
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
    try {
        for (size_t i = _libs.size(); i < _libsfiles.size(); i++) {
            #ifdef __linux__
                _libsPtrUnix.push_back(_dlLoaderUnix.loadLib(_libsfiles[i]));
                _libs.push_back((IElement*)_dlLoaderUnix.loadFunc(std::string("allocator"), _libsPtrUnix[i])());
            #endif
            #ifdef _WIN32
                _libsPtrWindows.push_back(_dlLoaderWindows.loadLib(_libsfiles[i]));
                _libs.push_back(_dlLoaderWindows.loadFunc(std::string("allocator"), _libsPtrWindows[i])());
            #endif
        }
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
}

void LibLoader::listLibDirectory(std::string path, std::vector<std::string> toLoad) {
    for (size_t i = 0; i < toLoad.size(); i++) {
        #ifdef WIN32
            _libsfiles.push_back(path + toLoad[i] + ".dll");
        #endif
        #ifdef __linux__
            _libsfiles.push_back(path + toLoad[i] + ".so");
        #endif
    }
    /*for (const auto entry : std::filesystem::directory_iterator(path))
        _libsfiles.push_back(entry.path().string());*/
}

void LibLoader::loadMoreLib(std::vector<std::string> toLoad)
{
    listLibDirectory(LIBS_PATH, toLoad);
    loadLibs();
}