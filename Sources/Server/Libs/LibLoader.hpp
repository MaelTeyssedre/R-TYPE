/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** LibLoader
*/

/**
 * \file LibLoader.hpp
 *
 * \brief file where the LibLoader class is defined
 */
#ifndef LIBLOADER_HPP_
    #define LIBLOADER_HPP_

    #include <string>
    #include <vector>
    #include "AMonster.hpp"
    #include <memory>
    #include <filesystem>

    #ifdef __linux__
        #include "DlLoaderUnix.hpp"
    #endif
    #ifdef _WIN32
        #include "DlLoaderWindows.hpp"
    #endif

    #ifdef __linux__
        #define LIBS_PATH "./build/bin/dynlibsLinux/"
    #endif
    #ifdef _WIN32
        #define LIBS_PATH "./build/bin/"
    #endif

    /**
     * \class LibLoader LibLoader.hpp
     *
     * \brief Class that load libs
     */

    class LibLoader {
        public:
            /**
             * \fn LibLoader(std::vector<std::string>)
             * 
             * \param Vector of libs to load
             * 
             * \brief construct the class, load the .so/.dll and construct class inside
             */
            explicit LibLoader();

            /**
             * \fn LibLoader(const LibLoader&)
             * 
             * \brief copy constructor
             */
            explicit LibLoader(const LibLoader&);

            /**
             * \fn ~LibLoader()
             * 
             * \brief Destructor
             */
            virtual ~LibLoader();


            /**
             * \fn LibLoader& operator=(const LibLoader &other) = default
             * 
             * \brief default operator= overload
             */
            LibLoader& operator=(const LibLoader &other) = default;

            /**
             * \fn void loadMoreLib(std::vector<std::string>)
             * 
             * \param Vector of libs to load
             * 
             * \brief load the .so/.dll and construct class inside
             */
            void loadLibs(const std::vector<std::string>&);

            /**
             * \fn std::vector<AMonster *> getLibs() const
             * 
             * \brief getter for loaded and constructed Element
             * 
             * \return vector of const loaded and constructed Element
             */
            std::vector<std::shared_ptr<AMonster>> *getLibs();
        
        private:
            /**
             * \fn void loadLibs()
             * 
             * \brief load the .so/.dll contain in _libsfiles, construct the class inside and store them in _libs
             */
            void loadLib();

            /**
             * \fn void loadLibs()
             * 
             * \param path of libs to load
             * 
             * \param toLoad name of the libs to load
             * 
             * \brief put the path of libs to load in _libsfiles
             */
            void listLibDirectory(const std::string &path, const std::vector<std::string> &toLoad);

            std::vector<std::shared_ptr<AMonster>> _libs;
            //std::vector<AMonster *> _libs; /*! Vector of class load from shared lib */
            std::vector<std::string> _libsfiles; /*! Vector of name shared lib */
            #ifdef __linux__
                DlLoaderUnix _dlLoaderUnix; /*! Library loader on Linux */
                std::vector<void *> _libsPtrUnix; /*! Vector of open libraries */
            #endif
            #ifdef _WIN32
                DlLoaderWindows _dlLoaderWindows; /*! Library loader on Windows */
                std::vector<HMODULE> _libsPtrWindows; /*! Vector of open libraries */
            #endif
    };

#endif /* !LiBLOADER_HPP_ */
