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

    #include "IElement.hpp"

    using allocClass = IElement*(*)();
    using deleteClass = void(*)(IElement*);

    class DlLoaderWindows {
        public:
            DlLoaderWindows() = default;
            ~DlLoaderWindows() = default;

            HMODULE loadLib(std::string path);
            allocClass loadFunc(std::string &function, HMODULE hDLL);
            void closeLib(HMODULE hDLL);
        protected:
        private:
    };

#endif /* !DLLOADERWINDOWS_HPP_ */
