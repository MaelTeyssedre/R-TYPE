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

    class DlLoaderUnix {
        public:
            DlLoaderUnix();
            ~DlLoaderUnix();

            void *loadLib(std::string path);
            void *loadFunc(std::string &function, void *ptr);
            void closeLib(void *ptr);
        protected:
        private:
    };

#endif /* !DLLOADERUNIX_HPP_ */
