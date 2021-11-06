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
    std::string data;
    std::string bufferIn;
    std::string bufferOut;
    RoomManager manager(bufferIn, bufferOut);
    int nbConnect = atoi(argv[1]);

    for (int i = 0; i != nbConnect; i++)
        data.append("Connect");
    manager.fillBufferIn(data);
    manager.isRoomNeedeed();
    return (0);
}