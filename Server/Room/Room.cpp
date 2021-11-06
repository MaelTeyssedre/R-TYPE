/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Room
*/

#include "Room.hpp"

Room::Room(int id)
{
    _id = id;
}

Room::~Room()
{
}

void Room::addPlayer(Player &player)
{
    _playerList.push_back(player);
}

std::vector<Player> Room::getPlayerList() const
{
    return (_playerList);
}

int Room::getId() const
{
    return (_id);
}