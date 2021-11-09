/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Player
*/

#include <iostream>
#include "PlayerData.hpp"

PlayerData::PlayerData(size_t id, std::shared_ptr<Buffer> buffIn, std::shared_ptr<Buffer> buffOut) 
: _id(id), _mutexIn(), _mutexOut(), _bufferIn(buffIn), _bufferOut(buffOut)
{
}

PlayerData::PlayerData(PlayerData &playerData)
{
    _id = playerData._id;
    _bufferIn = playerData._bufferIn;
    _bufferOut = playerData._bufferOut;
    _mutexIn = playerData._mutexIn;
    _mutexOut = playerData._mutexOut;
}

size_t PlayerData::getId(void) const
{
    return (_id);
}

PlayerData& PlayerData::operator=(PlayerData &PlayerData)
{
    return(*this);
}