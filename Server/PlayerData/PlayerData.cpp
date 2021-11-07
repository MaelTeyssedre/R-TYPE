/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Player
*/

#include <iostream>
#include "PlayerData.hpp"

PlayerData::PlayerData(size_t id, std::shared_ptr<Buffer> buffIn, std::shared_ptr<Buffer> buffOut) 
: _id(id),/* _mutexIn(), _mutexOut(),*/_bufferIn(buffIn), _bufferOut(buffOut)
{
}


size_t PlayerData::getId(void) const
{
    return (_id);
}