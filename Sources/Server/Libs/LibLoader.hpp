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
        #define LIBS_PATH "./build/bin/"
    #endif
    #ifdef _WIN32
        #define LIBS_PATH "./build/bin/"
    #endif

    /**
     * \namespace rtype
     * 
     * \brief global namespace for the rtype project
     * 
     */
    namespace rtype {
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
                 * \fn auto operator=(const LibLoader &other) -> LibLoader&  = default
                 * 
                 * \brief default operator= overload
                 * 
                 * \return LibLoader& the assigned libLoader
                 */
                auto operator=(const LibLoader &other) -> LibLoader&  = default;

                /**
                 * \fn auto loadLibs(const std::vector<std::string>&) -> void
                 * 
                 * \param Vector of libs to load
                 * 
                 * \brief load the .so/.dll and construct class inside
                 */
                auto loadLibs(const std::vector<std::string>&) -> void;

                /**
                 * \fn auto getLibs() -> std::vector<std::shared_ptr<AMonster>> *
                 * 
                 * \brief getter for loaded and constructed Element
                 * 
                 * \return vector of const loaded and constructed Element
                 */
                auto getLibs() -> std::vector<std::shared_ptr<AMonster>> *;
            
            private:
                /**
                 * \fn auto loadLib() -> void
                 * 
                 * \brief load the .so/.dll contain in _libsfiles, construct the class inside and store them in _libs
                 */
                auto loadLib() -> void;

                /**
                 * \fn auto listLibDirectory(const std::string &path, const std::vector<std::string> &toLoad) -> void
                 * 
                 * \param path of libs to load
                 * 
                 * \param toLoad name of the libs to load
                 * 
                 * \brief put the path of libs to load in _libsfiles
                 */
                auto listLibDirectory(const std::string &path, const std::vector<std::string> &toLoad) -> void;

                std::vector<std::shared_ptr<AMonster>> _libs; /*! List of shared pointer to AMonsters */
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
    }

#endif /* !LiBLOADER_HPP_ */
