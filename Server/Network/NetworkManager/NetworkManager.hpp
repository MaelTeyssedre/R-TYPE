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
        std::shared_ptr<ITCPClient> createTCPClient() override;
        std::shared_ptr<IUDPSocket> createSocketUDP() override;
        void deleteTCPServer(std::shared_ptr<ITCPServer> tcp) override;
        void deleteTCPClient(std::shared_ptr<ITCPClient> tcp) override;
        void deleteSocketUDP(std::shared_ptr<IUDPSocket> socket) override;
        static void startNetworkThread(NetworkManager *netManager);

    private:
        asio::io_context _context;
        asio::io_context::work *_worker;
        std::vector<std::shared_ptr<IUDPSocket>> _udpSockets;
        std::vector<std::shared_ptr<ITCPClient>> _tcpClients;
        std::vector<ITCPServer *> _tcpServers;
        std::thread _thread;
        bool _started;

        
};

#endif /* !NETWORKMANAGER_HPP_ */