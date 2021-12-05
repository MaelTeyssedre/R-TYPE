/**
 * \file DlLoaderWindows.hpp
 * 
 * \brief file for DLLoader for windows
 */

#ifndef DLLOADERWINDOWS_HPP_
    #define DLLOADERWINDOWS_HPP_

    #include <windows.h>
    #include <libloaderapi.h>
    #include <cstring>
    #include <iostream>
    #include <exception>
    #include "AMonster.hpp"

    /**
     * \class DlLoaderWindows
     * 
     * \brief class for DlLoader for windows 
     */
    class DlLoaderWindows {
        public:
            using allocClass = rtype::AMonster*(*)();
            using deleteClass = void(*)(rtype::IElement*);

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
             * \fn auto operator=(const DlLoaderWindows &other) -> DlLoaderWindows& = default
             * 
             * \brief Default operator= overload
             */
            auto operator=(const DlLoaderWindows &other) -> DlLoaderWindows& = default;

            /**
             * \fn auto loadLib(const std::string &path) -> HMODULE
             * 
             * \param path dynlib to load
             * 
             * \brief load a dynlib
             * 
             * \return loaded lib
             */
            auto loadLib(const std::string &path) -> HMODULE;

            /**
             * \fn auto loadFunc(const std::string &function, HMODULE hDLL) -> allocClass
             * 
             * \param function to load
             * 
             * \param hDLL dynlib previously loaded
             * 
             * \brief load a function from a dynlib
             * 
             * \return loaded function
             */
            auto loadFunc(const std::string &function, HMODULE hDLL) -> allocClass;

            /**
             * \fn auto closeLib(HMODULE hDLL) -> void
             * 
             * \param hDLL dynlib previously loaded
             * 
             * \brief close a loaded dynlib
             */
            auto closeLib(HMODULE hDLL) -> void;
    };

#endif /* !DLLOADERWINDOWS_HPP_ */
