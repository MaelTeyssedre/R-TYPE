/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IUDPSocket
*/

#ifndef IUDPSOCKET_HPP_
#define IUDPSOCKET_HPP_

#include "IPacket.hpp"

class IUDPSocket {
    public:

        /**
         * @brief Destroy the IUDPSocket object
         * 
         */
        virtual ~IUDPSocket() {};

        /**
         * @brief 
         * 
         * @param data 
         */
        virtual void send(IPacket &data) = 0;

        /**
         * @brief 
         * 
         * @param data 
         */
        virtual std::vector<uint8_t> &receive() = 0;
};

#endif /* !IUDPSOCKET_HPP_ */