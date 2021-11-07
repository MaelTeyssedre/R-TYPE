/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IPacket
*/

#ifndef IPACKET_HPP_
#define IPACKET_HPP_

#include <iostream>
#include <vector>
#include <any>
#include "INetworkManager.hpp"

class IPacket {
    public:

        /**
         * @brief Destroy the IPacket object
         * 
         */
        virtual ~IPacket() = 0;

        /**
         * @brief Serialize data
         * 
         * @param data data to serialize
         * @param size size of data to serialize
         * @return size of data serialized
         */
        virtual size_t pack(std::vector<int8_t> &data) = 0;

        /**
         * @brief Serialize data
         * 
         * @param data to serialize
         * @param size of data to serialize
         * @return size_t 
         */
        virtual size_t pack(int8_t *data, size_t size) = 0;

        /**
         * @brief deserialize packet
         * 
         * @param size of packet to deserialize
         * @return data deserialised
         */
        virtual std::vector<int8_t> unpack() = 0;

        protected:
            friend class ITCPServer;
            friend class ITCPClient;
};

#endif /* !IPACKET_HPP_ */