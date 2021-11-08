/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** NetworkManager
*/

#ifndef NETWORKMANAGER_HPP_
#define NETWORKMANAGER_HPP_

#include "INetworkManager.hpp"
#include "IUDPSocket.hpp"
#include "ITCPClient.hpp"
#include "ITCPServer.hpp"
#include <asio.hpp>
#include <thread>

class NetworkManager : public INetworkManager{
    public:
        NetworkManager() = default;
        ~NetworkManager() override;
        void start() override;
        void stop() override;
        std::shared_ptr<ITCPServer> createTCPServer() override;
        std::shared_ptr<ITCPClient> createTCPClient() override;
        std::shared_ptr<IUDPSocket> createSocketUDP() override;
        void deleteTCPServer(std::shared_ptr<ITCPServer> tcp) override;
        void deleteTCPClient(std::shared_ptr<ITCPClient> tcp) override;
        void deleteSocketUDP(std::shared_ptr<IUDPSocket> socket) override;
        static void startNetworkThread(asio::io_context &io_context,  std::vector<std::shared_ptr<IUDPSocket>> udpSockets, std::vector<std::shared_ptr<ITCPClient>>  tcpClients,  std::vector<std::shared_ptr<ITCPServer>> tcpServer);

    private:
        asio::io_context _ioContext;
        std::vector<std::shared_ptr<IUDPSocket>> _udpSockets;
        std::vector<std::shared_ptr<ITCPClient>> _tcpClients;
        std::vector<std::shared_ptr<ITCPServer>> _tcpServers;
       // std::thread _thread;

        
};

#endif /* !NETWORKMANAGER_HPP_ */