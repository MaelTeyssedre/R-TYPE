/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** LibLoader
*/

#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

#include "DlLoader.hpp"
#include <string>
#include <vector>

#ifdef __linux__
    #include "dirent.h"
#endif

#include <memory>

class ILib;

#ifdef __linux__
    #define LIBS_PATH "./dynlibsLinux/"
#endif
#ifdef _WIN32
    #define LIBS_PATH "./dynlibsWindows/"
#endif

class LibLoader {
    public:
        LibLoader(DlLoader loader);
        ~LibLoader();
        std::vector<std::shared_ptr<ILib>> getLibs() const;
    
    private:
        void loadLibs();
        void listLibDirectory(std::string path);

        std::vector<std::shared_ptr<ILib>> _libs;
        std::vector<void *> _libsPtr;
        std::vector<std::string> _libsfiles;
        DlLoader _dlLoader;
        int _target;
};

#endif /* !LiBLOADER_HPP_ */
