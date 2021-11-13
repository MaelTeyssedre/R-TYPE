/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** PacketManager
*/

#ifndef PACKETMANAGER_HPP_
#define PACKETMANAGER_HPP_

#include "Packet.hpp"

class PacketManager {
    public:
        PacketManager(std::shared_ptr<Buffer> bufferIn,  std::shared_ptr<Buffer> bufferOut);
        ~PacketManager();
        void managePacket(std::pair<size_t, std::vector<uint8_t>> packet);
  
    protected:
    private:
        std::shared_ptr<std::vector<std::vector<playerData>>> _roomList;
        std::shared_ptr<Buffer> _bufferIn;
        std::shared_ptr<Buffer> _bufferOut;
};

#endif /* !PACKETMANAGER_HPP_ */
