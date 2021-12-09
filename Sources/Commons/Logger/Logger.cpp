#include "Logger.hpp"

Logger::Logger()
{
    static bool singleton = false;
    if (singleton == true)
        throw std::bad_alloc();
    file_name = "Log";
    time_t tt;
    struct tm *ti;
    time(&tt);
    ti = localtime(&tt);
    //file_name += asctime(ti);
    file_name += ".txt";
    _file.open(file_name);
    _file.close();
}

Logger::~Logger()
{
}

void Logger::log(std::string message)
{
    lock.lock();
    _file.open(file_name);
    _file << message;
    _file.flush();
    _file.close();
    lock.unlock();
}

void Logger::logln(std::string message)
{
    lock.lock();
    _file.open(file_name);
    _file << message << std::endl;
    _file.flush();
    _file.close();
    lock.unlock();
}

void Logger::operator<<(std::string buffer)
{
    lock.lock();
    _file.open(file_name);
    _file << buffer;
    _file.flush();
    _file.close();
    lock.unlock();
}
