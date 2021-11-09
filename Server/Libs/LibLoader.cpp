/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** LibLoader
*/

#include "LibLoader.hpp"

LibLoader::LibLoader(DlLoader loader)
    : _dlLoader()
{
    listLibDirectory(LIBS_PATH);
    loadLibs();
}

LibLoader::~LibLoader() {
    for (void *ptr : _libsPtr) {
        #ifdef __linux__
            _dlLoader.closelib(ptr);
        #endif
    }
}

std::vector<std::shared_ptr<ILib>> LibLoader::getLibs() const {
    return _libs;
}

void LibLoader::loadLibs() {
    for (size_t i = 0; i < _libsfiles.size(); i++) {
        #ifdef __linux__
            _libsPtr.push_back(_dlLoader.loadLib(LIBS_PATH + _libsfiles[i]));
            _libs.push_back((std::shared_ptr<ILib>)((ILib *(*)())_dlLoader("Creator", _libsPtr[i]))());
        #endif
    }
}

void LibLoader::listLibDirectory(std::string path) {
    #ifdef __linux__
        DIR *dir = opendir(path.c_str());
        struct dirent *dir_stats;
        if (!dir)
            throw std::runtime_error("incorrect folder path");
        while ((dir_stats = readdir(dir)))
            _libsfiles.push_back(std::string(dir_stats->d_name));
        closedir(dir);
    #endif
}