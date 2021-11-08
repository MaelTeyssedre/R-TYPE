/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Packet
*/

#ifndef PACKET_HPP_
#define PACKET_HPP_

#include "IPacket.hpp"

class Packet : public IPacket{
    public:
        Packet();
        ~Packet() override;
        size_t pack(std::shared_ptr<std::vector<int8_t>> data) override;
        size_t pack(int8_t *data, size_t size) override;
        std::vector<int8_t> unpack() override;        

    protected:
    private:
        std::vector<int8_t> _rawData;
        std::string _data;
};

#endif /* !PACKET_HPP_ */