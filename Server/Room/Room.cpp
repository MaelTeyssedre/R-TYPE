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

Room::~Room()
{
}

int Room::getId() const
{
    return (_id);
}