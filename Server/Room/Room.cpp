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