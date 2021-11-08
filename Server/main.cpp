/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** main
*/

#include <iostream>
#include "RoomManager.hpp"
#include "Room.hpp"

int main(int argc, char **argv)
{
    std::cout << "Server" << std::endl;
    std::string data = argv[1];
    std::vector<PlayerData> playerData;
    RoomData roomData;
    //Buffer buffIn(360);
    //Buffer buffOut(360);
    std::shared_ptr<Buffer> buffIn(std::make_shared<Buffer>(Buffer(8192)));
    std::shared_ptr<Buffer> buffOut(std::make_shared<Buffer>(Buffer(8192)));
    std::shared_ptr<std::vector<std::pair<std::thread, RoomData>>> listRoom(std::make_shared<std::vector<std::pair<std::thread, RoomData>>>());
    std::cout << "Second " << listRoom.get()->size() << std::endl;
    RoomManager manager(listRoom, buffIn, buffOut); // Penser a inverser buffin//buffout pour le PacketInterpreter
    std::vector<uint8_t> vec;


    vec.assign(data.begin(), data.end());
    buffIn->putInBuffer(vec.size(), vec);
    manager.manageRoom();
    return (0);
}