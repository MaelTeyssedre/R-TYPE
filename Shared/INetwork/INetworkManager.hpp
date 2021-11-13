/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** INetworkManager
*/

#ifndef INETWORKMANAGER_HPP_
#define INETWORKMANAGER_HPP_

#include "ITCPClient.hpp"
#include "ITCPServer.hpp"
#include "IUDPSocket.hpp"
#include <vector>
#include <memory>

class INetworkManager {
    public:

        /**
         * @brief Destroy the INetworkManager object
         * 
         */
        virtual ~INetworkManager() {};

        /**
         * @brief start connection
         * 
         */
        virtual void start() = 0;

        /**
         * @brief stop connection
         * 
         */
        virtual void stop() = 0;

        /**
         * @brief create a TCP server
         * 
         * @return ITCPServer* 
         */
        virtual ITCPServer *createTCPServer(int port) =  0;

        /**
         * @brief create a TCP client
         * 
         * @return ITCPClient* 
         */
        virtual ITCPClient *createTCPClient(int port) = 0;

        /**
         * @brief Create a UDP connection
         * 
         * @return UDPSocket* 
         */ 
        virtual IUDPSocket *createSocketUDP(int port) = 0;

        /**
         * @brief delete a specified UDP connection
         * 
         * @param udp server to delete
         * 
         */
        virtual void deleteSocketUDP(IUDPSocket *socket) = 0;

        /**
         * @brief delete a specified TCP clie
         * 
         * @param tcp server to delete
         */
        virtual void deleteTCPServer(ITCPServer *tcp) = 0;

        /**
         * @brief delete tpc client
         * 
         * @param the tcp client to delete
         */
        virtual void deleteTCPClient(ITCPClient *tcp) = 0;
};

#endif /* !INETWORKMANAGER_HPP_ */