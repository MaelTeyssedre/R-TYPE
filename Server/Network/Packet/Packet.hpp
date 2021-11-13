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
        Packet();
        ~Packet() override;
        size_t pack(std::shared_ptr<std::vector<uint8_t>> data) override;
        size_t pack(uint8_t *data, size_t size) override;
        std::shared_ptr<std::vector<uint8_t>> unpack() override;        

    protected:
    private:
        std::shared_ptr<std::vector<uint8_t>> _rawData;
        std::string _data;
};

#endif /* !PACKET_HPP_ */