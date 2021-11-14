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

void PacketManager::createRoom(std::pair<size_t, std::vector<uint8_t>> packet)
{
    std::vector<uint8_t> vec;
    std::string str = "Create ";
    str.append(std::to_string(packet.first));
    str.append(";");
    vec.assign(str.begin(), str.end());
    _bufferOut->putInBuffer(vec.size(), vec);
}

void PacketManager::joinRoom(std::pair<size_t, std::vector<uint8_t>> packet)
{
    std::vector<uint8_t> vec;
    std::string  str = "Join ";
    str.append(std::to_string(packet.first));
    str.append(";");
    vec.assign(str.begin(), str.end());
    _bufferOut->putInBuffer(vec.size(), vec);
}


void PacketManager::managePacket(std::pair<size_t, std::vector<uint8_t>> packet)
{
  std::string str(packet.second.begin(), packet.second.end());

   for (int i = 0; i <= _roomList->size(); i++) {
       if (!std::find(_roomList->at(i).begin(), _roomList->at(i).end(), packet.first)) {
         if (packet.second.at(0) == 15)
          createRoom(packet);
        else if (packet.second.at(0) == 16)
          joinRoom(packet);
       }
   }
}
