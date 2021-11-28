#include "LibLoader.hpp"

rtype::LibLoader::LibLoader()
{
    #ifdef _WIN32
        _dlLoaderWindows = DlLoaderWindows();
    #endif
    #ifdef __linux__
        _dlLoaderUnix = DlLoaderUnix();
    #endif
}

rtype::LibLoader::LibLoader(const LibLoader &other)
{
    _libs = other._libs;
    _libsfiles = other._libsfiles;
    #ifdef __linux__
        _dlLoaderUnix = other._dlLoaderUnix;
        _libsPtrUnix = other._libsPtrUnix;
    #endif
    #ifdef _WIN32
        _dlLoaderWindows = other._dlLoaderWindows;
        _libsPtrWindows = other._libsPtrWindows;
    #endif
}

rtype::LibLoader::~LibLoader() {
    #ifdef __linux__
        for (void *ptr : _libsPtrUnix)
            _dlLoaderUnix.closeLib(ptr);
    #endif
    #ifdef _WIN32
        for (HMODULE ptr : _libsPtrWindows)
            _dlLoaderWindows.closeLib(ptr);
    #endif
}

std::vector<std::shared_ptr<rtype::AMonster>> *rtype::LibLoader::getLibs() {
    return &_libs;
}

void rtype::LibLoader::loadLib() {
    try {
        for (size_t i = _libs.size(); i < _libsfiles.size(); i++) {
            #ifdef __linux__
                _libsPtrUnix.push_back(_dlLoaderUnix.loadLib(_libsfiles[i]));
                _libs.push_back(std::shared_ptr<rtype::AMonster>((rtype::AMonster*)_dlLoaderUnix.loadFunc(std::string("allocator"), _libsPtrUnix[i])()));
            #endif
            #ifdef _WIN32
                _libsPtrWindows.push_back(_dlLoaderWindows.loadLib(_libsfiles[i]));
                _libs.push_back(std::shared_ptr<rtype::AMonster>(_dlLoaderWindows.loadFunc(std::string("allocator"), _libsPtrWindows[i])()));
            #endif
        }
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}

void rtype::LibLoader::listLibDirectory(const std::string &path, const std::vector<std::string> &toLoad) {
    for (size_t i = 0; i < toLoad.size(); i++) {
        #ifdef WIN32
            _libsfiles.push_back(path + toLoad[i] + ".dll");
        #endif
        #ifdef __linux__
            _libsfiles.push_back(path + toLoad[i] + ".so");
        #endif
    }
}

void rtype::LibLoader::loadLibs(const std::vector<std::string> &toLoad)
{
    listLibDirectory(LIBS_PATH, toLoad);
    loadLib();
}
