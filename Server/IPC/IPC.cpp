/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IPC
*/

#include <sstream>
#include <fstream>
#include "IPC.hpp"

IPC::IPC(std::string fileName)
{
    std::ofstream file(fileName);
    
    _fileName = fileName;
    file.close();
}

IPC::IPC(IPC const &ipc)
{
    _fileName = ipc._fileName;
}

void IPC::sendData(std::string data)
{
    std::ofstream file(_fileName, std::ios_base::app);

    file << data;
    file.close();
}

void IPC::replaceData(std::string data)
{
    std::ofstream file(_fileName);

    file << data;
    file.close();
}

void IPC::cleanFile()
{
    std::ofstream file(_fileName);
    file.close();
}

std::string IPC::takeData(size_t size)
{
    std::string data;
    std::string tmp;
    std::ifstream file (_fileName);

    file >> tmp;

    file.close();
    for (int i = 0; i < size; i++) {
        data += tmp[0];
        tmp.erase(0, 1);
    }
    replaceData(tmp);
    return (data);
}