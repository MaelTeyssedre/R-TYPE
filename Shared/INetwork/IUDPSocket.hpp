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
         * @brief send data
         * 
         * @param data to send
         */
        virtual void send(std::vector<size_t> targets, IPacket &data) = 0;

        /**
         * @brief 
         * 
         * @param data 
         */
        virtual void send(size_t target, IPacket &data) = 0;

        /**
         * @brief 
         * 
         * @param data 
         */
        virtual std::vector<uint8_t> receive() = 0;

        /**
         * @brief receive data
         * 
         * @return return data in packet
         */

        /**
         * @brief start the connection
         * 
         * @param port to accept connection
         */
        virtual void start() = 0;

        /**
         * @brief stop connection
         * 
         */
        virtual void eject(size_t client) = 0;
        virtual void stop() = 0;

};

#endif /* !IUDPSOCKET_HPP_ */