/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Player
*/

#include <iostream>
#include "PlayerData.hpp"

PlayerData::PlayerData(size_t id) : _id(id),/* _mutexIn(), _mutexOut(),*/_bufferIn(360), _bufferOut(360) 
{

}


size_t PlayerData::getId(void) const
{
    return (_id);
}