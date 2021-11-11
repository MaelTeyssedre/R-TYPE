/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** DlLoader
*/

#ifndef DLLOADER_HPP_
    #define DLLOADER_HPP_
    #ifdef __linux__
        #include <dlfcn.h>
    #endif
    #ifdef _WIN32
        #include <windows.h>
        #include <libloaderapi.h>
        #include <cstring>
    #endif

    #include <iostream>
    #include <exception>

    class DlLoader {
        public:
            DlLoader() = default;
            ~DlLoader() = default;
            #ifdef __linux__
                void *loadLib(std::string path);
                void *loadFunc(std::string &function, void *ptr);
                void closeLib(void *ptr);
            #endif
            #ifdef _WIN32
                HMODULE _hDLL = NULL;
                HANDLE  _Proc;

                HMODULE loadLib(std::string path);
                HANDLE loadFunc(std::string &function, HMODULE hDLL);
                void closeLib(HMODULE hDLL);
            #endif
    };

#endif /* !DLLOADER_HPP_ */