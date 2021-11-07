/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** NetworkManager
*/

#include "NetworkManager.hpp"
#include "TCPClient.hpp"
#include "tcpServer.hpp"
#include "udpSocket.hpp"

//TODO add loger

NetworkManager::NetworkManager()
{
}

NetworkManager::~NetworkManager()
{
}

void NetworkManager::start()
{
 //   _thread = std::thread(startNetworkThread, _ioContext, _udpSockets, _tcpClients, _tcpServers);
}

void NetworkManager::stop()
{
    for (std::vector<std::shared_ptr<IUDPSocket>>::iterator it = _udpSockets.begin(); it != _udpSockets.end(); it++)
        _udpSockets.erase(it);
   for (std::vector<std::shared_ptr<ITCPClient>>::iterator it = _tcpClients.begin(); it != _tcpClients.end(); it++)
        _tcpClients.erase(it);
   for (std::vector<std::shared_ptr<ITCPServer>>::iterator it = _tcpServers.begin(); it != _tcpServers.end(); it++)
        _tcpServers.erase(it);
   // _thread.join();
}

void NetworkManager::startNetworkThread(asio::io_context &ioContext,std::vector<std::shared_ptr<IUDPSocket>> &udpSockets, std::vector<std::shared_ptr<ITCPClient>>  &tcpClients,  std::vector<std::shared_ptr<ITCPServer>> &tcpServer)
{
    ioContext.run();
}

std::shared_ptr<ITCPClient> NetworkManager::createTCPClient()
{
    std::shared_ptr<TCPClient> client;
    _tcpClients.push_back(std::make_shared<TCPClient>(client));
    return (client);
}

std::shared_ptr<ITCPServer> NetworkManager::createTCPServer()
{
    std::shared_ptr<TCPServer> server;
    _tcpServers.push_back(std::make_shared<TCPServer>(server));
    return (server);
}

std::shared_ptr<IUDPSocket> NetworkManager::createSocketUDP()
{
    std::shared_ptr<UDPSocket> socket;
    _udpSockets.push_back(std::make_shared<UDPSocket>(socket));
    return (socket);
}

void NetworkManager::deleteSocketUDP(std::shared_ptr<IUDPSocket> tcp)
{
    auto it = std::find(_udpSockets.begin(), _udpSockets.end(), socket);

    _udpSockets.erase(it);
}

void NetworkManager::deleteTCPClient(std::shared_ptr<ITCPClient> tcp)
{
    auto it = std::find(_tcpClients.begin(), _tcpClients.end(), socket);

    _tcpClients.erase(it);
}

void NetworkManager::deleteTCPServer(std::shared_ptr<ITCPServer> tcp)
{
    auto it = std::find(_tcpServers.begin(), _tcpServers.end(), socket);

    _tcpServers.erase(it);
}