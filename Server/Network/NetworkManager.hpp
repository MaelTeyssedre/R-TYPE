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
#include "ITCPClient.hpp"
#include "TCPServer.hpp"
#include "tcpUser.hpp"
#include <asio.hpp>
#include <thread>

class NetworkManager : public INetworkManager{
    public:
        NetworkManager();
        ~NetworkManager() override;
        void start() override;
        void stop() override;
        ITCPServer &createTCPServer() override;
        ITCPClient &createTCPClient() override;
        IUDPSocket &createSocketUDP() override;
        void deleteTCPServer(ITCPServer &) override;
        void deleteTCPClient(ITCPClient &) override;
        void deleteSocketUDP(IUDPSocket &) override;
        static void startNetworkThread(asio::io_context &io_context, std::vector<IUDPSocket> &udpSockets, std::vector<ITCPClient> &tcpClients, std::vector<ITCPServer> &tcpServer);

    private:
        asio::io_context _ioContext;
        std::vector<std::shared_ptr<IUDPSocket>> _udpSockets;
        std::vector<std::shared_ptr<ITCPClient>> _tcpClients;
        std::vector<std::shared_ptr<ITCPServer>> _tcpServers;
        std::thread _thread;

        
};

#endif /* !NETWORKMANAGER_HPP_ */