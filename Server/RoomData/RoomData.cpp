/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** RoomData
*/

#include "RoomData.hpp"

RoomData::RoomData()
{
}

RoomData &RoomData::operator=(RoomData &)
{
    return (*this);
}

RoomData::RoomData(RoomData &roomData)
{
}


std::pair<size_t, std::vector<PlayerData>> &RoomData::getRoomData()
{
    return (_roomData);
}

void RoomData::setRoomData(std::pair<size_t, std::vector<PlayerData>> roomData)
{
    _roomData = roomData;
}