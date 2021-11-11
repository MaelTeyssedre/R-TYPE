/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** NetworkManager
*/

#ifndef NETWORKMANAGER_HPP_
#define NETWORKMANAGER_HPP_

#include "INetworkManager.hpp"
#include "UDPSocket.hpp"
#include "TCPClient.hpp"
#include "TCPServer.hpp"
#include <asio.hpp>
#include <thread>

class NetworkManager : public INetworkManager{
    public:
        NetworkManager();
        ~NetworkManager();
        void start() override;
        void stop() override;
        TCPServer *createTCPServer() override;
        ITCPClient *createTCPClient() override;
       IUDPSocket *createSocketUDP() override;
        void deleteTCPServer(ITCPServer *tcp) override;
        void deleteTCPClient(ITCPClient *tcp) override;
        void deleteSocketUDP(IUDPSocket *socket) override;
        static void startNetworkThread(NetworkManager *netManager);

    private:
        asio::io_context _context;
        asio::io_context::work *_worker;
        std::vector<IUDPSocket *> _udpSockets;
        std::vector<ITCPClient *> _tcpClients;
        std::vector<ITCPServer *> _tcpServers;
        std::thread _thread;
        bool _started;

        
};

#endif /* !NETWORKMANAGER_HPP_ */