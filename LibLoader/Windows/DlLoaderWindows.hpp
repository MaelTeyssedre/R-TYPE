/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** DlLoaderWindows
*/

#ifndef DLLOADERWINDOWS_HPP_
    #define DLLOADERWINDOWS_HPP_


    #include <windows.h>
    #include <libloaderapi.h>
    #include <cstring>
    #include <iostream>
    #include <exception>

    class DlLoaderWindows {
        public:
            DlLoaderWindows() = default;
            ~DlLoaderWindows() = default;

            HMODULE _hDLL = NULL;
            void *_Proc;

            HMODULE loadLib(std::string path);
            void *loadFunc(std::string &function, HMODULE hDLL);
            void closeLib(HMODULE hDLL);
        protected:
        private:
    };

#endif /* !DLLOADERWINDOWS_HPP_ */
