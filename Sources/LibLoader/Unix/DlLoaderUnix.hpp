/**
 * \file DlLoaderUnix.hpp
 *
 * \brief file DynLibs are load on linux
 */

#ifndef DLLOADERUNIX_HPP_
    #define DLLOADERUNIX_HPP_

    #include <exception>
    #include <dlfcn.h>

    #include "IElement.hpp"

    /**
     * \class DlLoaderUnix DlLoaderUnix.hpp
     * 
     * \brief Class that load unix .so
     */
    class DlLoaderUnix {
        public:
            using allocClass = rtype::IElement*(*)();
            using deleteClass = void(*)(rtype::IElement*);

        public:
            /**
             * \fn DlLoaderUnix() = default
             * 
             * \brief Default ctor
             */
            explicit DlLoaderUnix() = default;

            /**
             * \fn DlLoaderUnix(const DlLoaderUnix&) = default
             * 
             * \brief Default copy ctor
             */
            explicit DlLoaderUnix(const DlLoaderUnix&) = default;

            /**
             * \fn ~DlLoaderUnix() = default
             * 
             * \brief Default dtor
             */
            virtual ~DlLoaderUnix() = default;

            /**
             * \fn DlLoaderUnix& operator=(const DlLoaderUnix &other) = default
             * 
             * \brief Default operator= overload
             * 
             * \return reference tu the assigned object
             */
            DlLoaderUnix& operator=(const DlLoaderUnix &other) = default;

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

#endif /* !DLLOADERUNIX_HPP_ */
