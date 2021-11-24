#include "Logger.hpp"

Logger::Logger(std::string fileName)
{
    _file.open(fileName);
}

Logger::~Logger()
{
    _file.close();
}

void Logger::log(std::string message)
{
    std::cout << message << std::endl;
    _file << message;
    _file.flush();
}

void Logger::logln(std::string message)
{
    std::cout << message << std::endl;
    _file << message << std::endl;
    _file.flush();
}

void Logger::operator<<(std::string buffer)
{
    std::cout << buffer << std::endl;
    _file << buffer;
    _file.flush();
}
