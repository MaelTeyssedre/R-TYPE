/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Room
*/

#include "Room.hpp"

Room::Room(size_t id)
{
    _id = id;
}

Room::Room(Room &room)
{
    _id = room._id;
    _roomBuffers = room._roomBuffers;
}

size_t Room::getId() const
{
    return (_id);
}

std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> Room::getRoomBuffer() const
{
    return (_roomBuffers);
}

void Room::setRoomBuffer(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer)
{
    _roomBuffers = roomBuffer;
}

Room& Room::operator=(Room &room)
{
    _id = room._id;
    _roomBuffers = room._roomBuffers;
    return *this;
}