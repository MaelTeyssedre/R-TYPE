/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** PacketManager
*/

#include "PacketManager.hpp"

PacketManager::PacketManager()
{
}

PacketManager::~PacketManager()
{
}

IPacket &PacketManager::serialise(std::shared_ptr<std::vector<int8_t>> rawData)
{
    Packet tmp;

    tmp.pack(rawData);
    return (tmp);
}

std::shared_ptr<std::vector<int8_t>> PacketManager::unserialise(IPacket &packet)
{
    return (packet.unpack());
}