/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** DlLoaderUnix
*/

#ifndef DLLOADERUNIX_HPP_
    #define DLLOADERUNIX_HPP_

    #include <iostream>
    #include <exception>
    #include <dlfcn.h>

    #include "IElement.hpp"

    using allocClass = IElement*(*)();
    using deleteClass = void(*)(IElement*);

    class DlLoaderUnix {
        public:
            DlLoaderUnix() = default;
            ~DlLoaderUnix() = default;

            void *loadLib(std::string path);
            allocClass loadFunc(std::string function, void *ptr);
            void closeLib(void *ptr);
        protected:
        private:
    };

#endif /* !DLLOADERUNIX_HPP_ */
