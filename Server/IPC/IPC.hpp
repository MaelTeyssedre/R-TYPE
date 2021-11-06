/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IPC
*/

#ifndef IPC_HPP_
#define IPC_HPP_

#include <string>
#include <iostream>
#include <fstream>

class IPC {
    public:
        IPC() = default;
        IPC(std::string);
        IPC(IPC const &);
        void sendData(std::string);
        void replaceData(std::string);
        void cleanFile();
        std::string takeData(size_t);
        ~IPC() = default;
    protected:
    private:
    std::string _fileName;
};

#endif /* !IPC_HPP_ */
