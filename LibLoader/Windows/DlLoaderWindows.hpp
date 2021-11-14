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
            /**
             * \fn DlLoaderWindows() = default
             * 
             * \brief Default ctor
             */
            explicit DlLoaderWindows() = default;

            /**
             * \fn DlLoaderWindows(const DlLoaderWindows&) = default
             * 
             * \brief Default copy ctor
             */
            explicit DlLoaderWindows(const DlLoaderWindows&) = default;

            /**
             * \fn ~DlLoaderWindows() = default
             * 
             * \brief Default dtor
             */
            virtual ~DlLoaderWindows() = default;

            /**
             * \fn DlLoaderWindows& operator=(const DlLoaderWindows &other) = default
             * 
             * \brief Default operator= overload
             */
            DlLoaderWindows& operator=(const DlLoaderWindows &other) = default;

            /**
             * \fn HMODULE loadLib(std::string path)
             * 
             * \param path dynlib to load
             * 
             * \brief load a dynlib
             * 
             * \return loaded lib
             */
            HMODULE loadLib(const std::string path&);

            /**
             * \fn allocClass loadFunc(std::string &function, HMODULE hDLL)
             * 
             * \param function to load
             * 
             * \param hDLL dynlib previously loaded
             * 
             * \brief load a function from a dynlib
             * 
             * \return loaded function
             */
            allocClass loadFunc(const std::string &function, HMODULE hDLL);

            /**
             * \fn void closeLib(HMODULE hDLL)
             * 
             * \param hDLL dynlib previously loaded
             * 
             * \brief close a loaded dynlib
             */
            void closeLib(HMODULE hDLL);
    };

#endif /* !DLLOADERWINDOWS_HPP_ */
