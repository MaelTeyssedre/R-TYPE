/**
 * \file DlLoaderOSX.hpp
 *
 * \brief file DynLibs are load on linux
 */

#ifndef DLLOADEROSX_HPP_
    #define DLLOADEROSX_HPP_

    #include <iostream>
    #include <exception>
    #include <dlfcn.h>

    #include "IElement.hpp"

    /**
     * \class DlLoaderOSX DlLoaderOSX.hpp
     * 
     * \brief Class that load OSX .so
     */
    class DlLoaderOSX {
        public:
            using allocClass = rtype::IElement*(*)();
            using deleteClass = void(*)(rtype::IElement*);

        public:
            /**
             * \fn DlLoaderOSX() = default
             * 
             * \brief Default ctor
             */
            explicit DlLoaderOSX() = default;

            /**
             * \fn DlLoaderOSX(const DlLoaderOSX&) = default
             * 
             * \brief Default copy ctor
             */
            explicit DlLoaderOSX(const DlLoaderOSX&) = default;

            /**
             * \fn ~DlLoaderOSX() = default
             * 
             * \brief Default dtor
             */
            virtual ~DlLoaderOSX() = default;

            /**
             * \fn DlLoaderOSX& operator=(const DlLoaderOSX &other) = default
             * 
             * \brief Default operator= overload
             * 
             * \return reference tu the assigned object
             */
            DlLoaderOSX& operator=(const DlLoaderOSX &other) = default;

            /**
             * \fn void *loadLib(std::string path)
             *
             * \param path path to a dynlib
             * 
             * \brief open a dynlib
             * 
             * \fn pointer to the loaded lib
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
             * 
             * \return loaded function
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

#endif /* !DLLOADEROSX_HPP_ */

