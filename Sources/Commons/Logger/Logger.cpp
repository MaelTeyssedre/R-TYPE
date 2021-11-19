/*
** EPITECH PROJECT, 2021
** B-CPP-500-NAN-5-1-babel-romain.gabet
** File description:
** Logger.cpp
*/

#include "Logger.hpp"

Logger::Logger(std::string &fileName)
{
    _file.open(fileName);
}

Logger::~Logger()
{
    _file.close();
}

void Logger::log(std::string &message)
{
    _file << message;
    _file.flush();
}

void Logger::logln(std::string &message)
{
    _file << message << std::endl;
    _file.flush();
}

void Logger::operator<<(std::string &buffer)
{
    _file << buffer << std::endl;
    _file.flush();
}