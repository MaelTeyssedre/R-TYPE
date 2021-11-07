/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** NetworkManager
*/

#include "NetworkManager.hpp"

//TODO add loger

NetworkManager::NetworkManager()
{
}

NetworkManager::~NetworkManager()
{
}

void NetworkManager::start()
{
    _thread = std::thread(startNetworkThread, _ioContext, _udpSockets, _tcpClients, _tcpServers);
}

void NetworkManager::stop()
{
    for (std::vector<std::shared_ptr<IUDPSocket>>::iterator it = _udpSockets.begin(); it != _udpSockets.end(); it++)
        _udpSockets.erase(it);
   for (std::vector<std::shared_ptr<ITCPClient>>::iterator it = _tcpClients.begin(); it != _tcpClients.end(); it++)
        _tcpClients.erase(it);
   for (std::vector<std::shared_ptr<ITCPServer>>::iterator it = _tcpServers.begin(); it != _tcpServers.end(); it++)
        _tcpServers.erase(it);
    _thread.join();
}

void NetworkManager::startNetworkThread(asio::io_context &ioContext, std::vector<IUDPSocket> &udpSockets, std::vector<ITCPClient> &tcpClients, std::vector<ITCPServer> &tcpServer)
{
    ioContext.run();
}

ITCPClient &NetworkManager::createTCPClient()
{
    TCPClient client;
    _tcpClients.push_back(std::make_shared<TCPClient>(client));
    return (client);
}

ITCPServer &NetworkManager::createTCPServer()
{
    TCPServer server;
    _tcpServers.push_back(std::make_shared<TCPServer>(server));
    return (server);
}

IUDPSocket &NetworkManager::createSocketUDP()
{
    UDPSocket socket;
    _udpSockets.push_back(std::make_shared<UDPSocket>(socket));
    return (socket);
}

void NetworkManager::deleteSocketUDP(IUDPSocket &socket)
{
    auto it = std::find(_udpSockets.begin(), _udpSockets.end(), socket);

    _udpSockets.erase(it);
}

void NetworkManager::deleteTCPClient(ITCPClient &client)
{
    auto it = std::find(_tcpClients.begin(), _tcpClients.end(), socket);

    _tcpClients.erase(it);
}

void NetworkManager::deleteTCPServer(ITCPServer &server)
{
    auto it = std::find(_tcpServers.begin(), _tcpServers.end(), socket);

    _tcpServers.erase(it);
}