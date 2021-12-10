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
    file_name += "_";
    file_name += std::to_string(ti->tm_mday);
    file_name += "-"; 
    file_name += std::to_string(ti->tm_mon);
    file_name += "_";
    file_name += std::to_string(ti->tm_hour);
    file_name += "-";
    file_name += std::to_string(ti->tm_min);
    file_name += "-";
    file_name += std::to_string(ti->tm_sec);
    file_name += ".txt";
    std::cout << file_name << std::endl;
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
