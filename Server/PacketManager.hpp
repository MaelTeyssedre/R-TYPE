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
        PacketManager();
        ~PacketManager();
        IPacket &serialise(std::shared_ptr<std::vector<int8_t>> data);
        std::shared_ptr<std::vector<int8_t>> unserialise(IPacket &packet);

    protected:
    private:
       // std::shared_ptr<std::vector<std::vector</*playerData*/int>>>> _players;
};

#endif /* !PACKETMANAGER_HPP_ */
