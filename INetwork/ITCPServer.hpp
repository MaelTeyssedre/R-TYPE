/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** ITCPServer
*/

#ifndef ITCPSERVER_HPP_
#define ITCPSERVER_HPP_

#include "INetworkManager.hpp"

class ITCPServer {
    public:

        /**
         * @brief Destroy the ITCPServer object
         * 
         */
        virtual ~ITCPServer() = 0;

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
        virtual void sendToAll(IPacket &data) = 0;

        /**
         * @brief 
         * 
         * @param targets 
         * @param data 
         */
        virtual void send(std::vector<size_t> targets, IPacket &data) = 0;

        /**
         * @brief receive data
         * 
         * @return return data in packet
         */
        virtual IPacket &receive() = 0;

        /**
         * @brief start the server and accept incoming connection
         * 
         * @param port to accept connection
         */
        virtual void start() = 0;

        /**
         * @brief 
         * 
         * @param client 
         */
        virtual void eject(size_t client) = 0;

        /**
         * @brief stop the server
         * 
         */
        virtual void stop() = 0;
};

#endif /* !ITCPSERVER_HPP_ */