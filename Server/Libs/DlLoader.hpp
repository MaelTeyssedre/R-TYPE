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
        #include <libloaderapi.h>
    #endif

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
    };
#endif /* !DLLOADER_HPP_ */
