/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** main
*/

#include <iostream>
#include "RoomManager.hpp"
#include "Room.hpp"


// * debug main
int main(int argc, char **argv)
{
    (void)argc;
    std::cout << "Server" << std::endl;
    std::string data = argv[1];
    std::vector<PlayerData> playerData;
    std::shared_ptr<Buffer> buffIn(std::make_shared<Buffer>(Buffer(8192)));
    std::shared_ptr<Buffer> buffOut(std::make_shared<Buffer>(Buffer(8192)));
    std::shared_ptr<std::vector<std::vector<PlayerData>>> listRoom(std::make_shared<std::vector<std::vector<PlayerData>>>());

    //std::cout << "Second " << listRoom.get()->size() << std::endl;
    RoomManager manager(listRoom, buffIn, buffOut); // Penser a inverser buffin//buffout pour le PacketInterpreter
    std::vector<uint8_t> vec;


    vec.assign(data.begin(), data.end());
    buffIn->putInBuffer(vec.size(), vec);
    manager.manageRoom();
    return (0);
}
