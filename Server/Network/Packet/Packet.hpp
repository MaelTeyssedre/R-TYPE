/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Packet
*/

/**
 * \file Packet.hpp
 * 
 * \brief file where Packet class is defined
 * 
 */
#ifndef PACKET_HPP_
#define PACKET_HPP_

#include "IPacket.hpp"

/**
 * \class Packet Packet.hpp 
 * 
 * \brief class that contain packet
 */
class Packet : public IPacket {
    public:

        /**
        * \fn Packet() = default
        *
        * \brief ctor packet
        */
        explicit Packet() = default;

        /**
        * \fn ~Packet() = default
        *
        * \brief dtor packet
        */
        virtual ~Packet() = default;

        /**
        * \fn size_t pack(std::vector<uint8_t> &data)
        *
        * \brief pack data
        * 
        * \param data to pack
        * 
        */
        size_t pack(std::vector<uint8_t> &data) override;

        /**
        * \fn std::shared_ptr<std::vector<uint8_t>> unpack()
        *
        * \brief unpack the data
        * 
        */
        std::shared_ptr<std::vector<uint8_t>> unpack() override;        

    protected:
    private:
        std::shared_ptr<std::vector<uint8_t>> _rawData; /*! data */
        size_t _packetSize; /*! size of the packet */
};

#endif /* !PACKET_HPP_ */