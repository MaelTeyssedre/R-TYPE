/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** main
*/

#include <iostream>
#include "RoomManager.hpp"

int main(int argc, char **argv)
{
    std::string data = argv[1];
    Buffer buffIn(360);
    Buffer buffOut(360);
    RoomManager manager;
    std::vector<uint8_t> vec;

    vec.assign(data.begin(), data.end());
    buffIn.putInBuffer(vec.size(), vec);
    manager.manageRoom(buffIn, buffOut);
    return (0);
}