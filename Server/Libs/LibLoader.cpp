/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** LibLoader
*/


#include "LibLoader.hpp"

#ifdef __linux__
    LibLoader::LibLoader(DlLoaderUnix loader)
        : _dlLoaderUnix()
    {
        listLibDirectory(LIBS_PATH);
        loadLibs();
    }
#endif
#ifdef _WIN32
    LibLoader::LibLoader(DlLoaderWindows loader)
        : _dlLoaderWindows()
    {
        listLibDirectory(LIBS_PATH);
        loadLibs();
    }
#endif

LibLoader::~LibLoader() {
    #ifdef __linux__
        for (void *ptr : _libsPtrUnix) {
            _dlLoaderUnix.closeLib(ptr);
        }
    #endif
    #ifdef _WIN32
        for (HMODULE ptr : _libsPtrWindows) {
            _dlLoaderWindows.closeLib(ptr);
        }
    #endif
}

std::vector<std::shared_ptr<ILib>> LibLoader::getLibs() const {
    return _libs;
}

void LibLoader::loadLibs() {
    for (size_t i = 0; i < _libsfiles.size(); i++) {
        #ifdef __linux__
            _libsPtrUnix.push_back(_dlLoaderUnix.loadLib(LIBS_PATH + _libsfiles[i]));
            _libs.push_back((std::shared_ptr<ILib>)((ILib *(*)())_dlLoaderUnix.loadFunc("Creator", _libsPtrUnix[i]))());
        #endif
        #ifdef _WIN32
            _libsPtrWindows.push_back(_dlLoaderWindows.loadLib(LIBS_PATH + _libsfiles[i]));
            //_libs.push_back((std::shared_ptr<ILib>)((ILib *(*)())_dlLoaderWindows.loadFunc("Creator", _libsPtrWindows[i]))());
            // ! Upline, Pakonpri
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
    #ifdef _WIN32
        // ? Work on linux?
        //std::string path = "/path/to/directory";
        for (const auto & entry : std::filesystem::directory_iterator(path))
            _libsfiles.push_back(entry.path().string());
            //std::cout << entry.path().string() << std::endl;
    #endif
}