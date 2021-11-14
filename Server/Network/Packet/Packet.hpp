/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Packet
*/

#ifndef PACKET_HPP_
#define PACKET_HPP_

#include "IPacket.hpp"

class Packet : public IPacket {
    public:
        Packet() = default;
        ~Packet() = default;
        size_t pack(std::vector<uint8_t> &data) override;
        std::shared_ptr<std::vector<uint8_t>> unpack() override;        

    protected:
    private:
        std::shared_ptr<std::vector<uint8_t>> _rawData;
        size_t _packetSize;
};

#endif /* !PACKET_HPP_ */