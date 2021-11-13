/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** PacketManager
*/

#include "PacketManager.hpp"

PacketManager::PacketManager(std::shared_ptr<Buffer> bufferIn,  std::shared_ptr<Buffer> bufferOut)
{
    _bufferIn = bufferIn;
    _bufferOut = bufferOut;
}

PacketManager::~PacketManager()
{
}

void PacketManager::managePacket(std::pair<size_t, std::vector<uint8_t>> packet)
{
   for (int i = 0; i <= _roomList->size(); i++) {
       if (std::find(_roomList->at(i).begin(), _roomList->at(i).end(), packet.first)) {

        return;
       }
   } 
  _bufferOut->putInBuffer(static_cast<uint16_t>(packet.second.size()), packet.second);
}
