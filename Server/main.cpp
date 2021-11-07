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
    std::cout << "Server" << std::endl;
    std::string data = argv[1];
    //Buffer buffIn(360);
    //Buffer buffOut(360);
    std::shared_ptr<Buffer> buffIn(new Buffer(8192));
    std::shared_ptr<Buffer> buffOut(new Buffer(8192));
    std::vector<std::pair<std::thread, RoomData>> listRoom;
    RoomManager manager(listRoom, buffIn, buffOut); // Penser a inverser buffin//buffout pour le PacketInterpreter
    std::vector<uint8_t> vec;

    vec.assign(data.begin(), data.end());
    buffIn->putInBuffer(vec.size(), vec);
    manager.manageRoom();
    return (0);
}