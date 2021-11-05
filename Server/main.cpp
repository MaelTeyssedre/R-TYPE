/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** main
*/

#include <iostream>
#include "RoomManager.hpp"

int main()
{
    std::string data;
    std::string bufferIn;
    std::string bufferOut;
    RoomManager manager(bufferIn, bufferOut);

    while (1) {
        std::cin >> data;
        manager.fillBufferIn(data);
        manager.isRoomNeedeed();
    }
    return (0);
}