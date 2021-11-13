/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** LibLoader
*/

#ifndef LIBLOADER_HPP_
    #define LIBLOADER_HPP_

    #include <string>
    #include <vector>
    #include <memory>
    #include <filesystem>

    #ifdef __linux__
        #include "DlLoaderUnix.hpp"
    #endif
    #ifdef _WIN32
        #include "DlLoaderWindows.hpp"
    #endif

    #ifdef __linux__
        #define LIBS_PATH "./build/bin/dynlibsLinux/"
    #endif
    #ifdef _WIN32
        #define LIBS_PATH "./build/Release/dynlibsWindows"
    #endif


    class LibLoader {
        public:
            LibLoader();
            ~LibLoader();
            
            std::vector<IElement *> getLibs() const;
        
        private:
            void loadLibs();
            void listLibDirectory(std::string path);

            std::vector<IElement *> _libs;
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
