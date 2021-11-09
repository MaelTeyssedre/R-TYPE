/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Player
*/

#include <iostream>
#include "PlayerData.hpp"

PlayerData::PlayerData(size_t id, std::shared_ptr<Buffer> buffIn, std::shared_ptr<Buffer> buffOut, std::shared_ptr<std::mutex> mutexIn,std::shared_ptr<std::mutex> mutexOut) 
: _id(id), mutexIn(mutexIn), mutexOut(mutexOut), bufferIn(buffIn), bufferOut(buffOut)
{
}

size_t PlayerData::getId(void) const
{
    return (_id);
}