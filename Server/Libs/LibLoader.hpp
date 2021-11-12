/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** LibLoader
*/

#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

//#include "DlLoader.hpp"
#include <string>
#include <vector>

#ifdef __linux__
    #include "dirent.h"
    #include "LibLoaderUnix.hpp"
#endif
#ifdef _WIN32
    //#include "DlLoaderWindows.hpp"
    #include "../../LibLoader/Windows/DlLoaderWindows.hpp"
#endif

#include <memory>
#include <filesystem>

class ILib;

#ifdef __linux__
    #define LIBS_PATH "./dynlibsLinux/"
#endif
#ifdef _WIN32
    #define LIBS_PATH "./dynlibsWindows/"
#endif


class LibLoader {
    public:
        /*#ifdef __linux__
            LibLoader(DlLoaderUnix loader);
        #endif
        #ifdef _WIN32
            LibLoader(DlLoaderWindows loader);
        #endif*/

        LibLoader();
        ~LibLoader();
        
        std::vector<std::shared_ptr<ILib>> getLibs() const;
    
    private:
        void loadLibs();
        void listLibDirectory(std::string path);

        std::vector<std::shared_ptr<ILib>> _libs;
        std::vector<std::string> _libsfiles;
        #ifdef __linux__
            DlLoaderUnix _dlLoaderUnix;
            std::vector<void *> _libsPtrUnix;
        #endif
        #ifdef _WIN32
            DlLoaderWindows _dlLoaderWindows;
            std::vector<HMODULE> _libsPtrWindows;
        #endif

        // ? wtf le target
        int _target;
};

#endif /* !LiBLOADER_HPP_ */
