/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** DlLoaderUnix
*/


/**
 * \file DlLoaderUnix.hpp
 *
 * \brief file DynLibs are load on linux
 */

#ifndef DLLOADERUNIX_HPP_
    #define DLLOADERUNIX_HPP_

    #include <iostream>
    #include <exception>
    #include <dlfcn.h>

    #include "IElement.hpp"

    using allocClass = IElement*(*)();
    using deleteClass = void(*)(IElement*);

    /**
     * \class DlLoaderUnix DlLoaderUnix.hpp
     * 
     * \brief Class that load unix .so
     */

    class DlLoaderUnix {
        public:
            /**
             * \fn DlLoaderUnix() = default
             * 
             * \brief Default ctor
             */
            DlLoaderUnix() = default;

            /**
             * \fn DlLoaderUnix(const DlLoaderUnix&) = default
             * 
             * \brief Default copy ctor
             */
            DlLoaderUnix(const DlLoaderUnix&) = default;

            /**
             * \fn ~DlLoaderUnix() = default
             * 
             * \brief Default dtor
             */
            ~DlLoaderUnix() = default;

            /**
             * \fn DlLoaderUnix& operator=(const DlLoaderUnix &other) = default
             * 
             * \brief Default operator= overload
             */
            DlLoaderUnix& operator=(const DlLoaderUnix &other) = default;

            /**
             * \fn void *loadLib(std::string path)
             *
             * \param path path to a dynlib
             * 
             * \brief open a dynlib
             */
            void *loadLib(std::string path);

            /**
             * \fn allocClass loadFunc(std::string function, void *ptr)
             *
             * \param function name of the function to load
             *
             * \param ptr previously open lib
             * 
             * \brief load a function from a dynlib
             */
            allocClass loadFunc(std::string function, void *ptr);

            /**
             * \fn void closeLib(void *ptr)
             *
             * \param ptr previously open lib
             * 
             * \brief close a dynlib
             */
            void closeLib(void *ptr);
    };

#endif /* !DLLOADERUNIX_HPP_ */
