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
        virtual ~IUDPSocket() = 0;

        /**
         * @brief send data
         * 
         * @param data to send
         */
        virtual void send(IPacket &data) = 0;

        /**
         * @brief 
         * 
         * @param data 
         */
        virtual void send(std::vector<size_t>, IPacket &data) = 0;

        /**
         * @brief 
         * 
         * @param data 
         */
        virtual void sendToAll(IPacket &data) = 0;

        /**
         * @brief receive data
         * 
         * @return return data in packet
         */
        virtual IPacket &receiver() = 0;

        /**
         * @brief start the connection
         * 
         * @param port to accept connection
         */
        virtual void start(std::uint16_t port) = 0;

        /**
         * @brief stop connection
         * 
         */
        virtual void stop() = 0;
};

#endif /* !IUDPSOCKET_HPP_ */