/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** ITCPServer
*/

#ifndef ITCPSERVER_HPP_
#define ITCPSERVER_HPP_

#include "IPacket.hpp"

class ITCPServer {
    public:

        /**
         * @brief Destroy the ITCPServer object
         * 
         */
        virtual ~ITCPServer() = default;

        /**
         * @brief 
         * 
         * @param targets 
         * @param data 
         */
        virtual void send(std::vector<size_t> targets, IPacket &data) = 0;

        /**
         * @brief 
         * 
         * @param target
         * @param data 
         */
        virtual void send(size_t target, IPacket &data) = 0;

        /**
         * @brief receive data
         * 
         * @return return data in packet
         */
        virtual std::vector<uint8_t> receive() = 0;

        /**
         * @brief 
         * 
         * @param client 
         */
        virtual void eject(size_t client) = 0;

};

#endif /* !ITCPSERVER_HPP_ */