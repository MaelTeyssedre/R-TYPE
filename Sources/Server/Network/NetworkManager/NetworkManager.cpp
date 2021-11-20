/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** NetworkManager
*/

#include "NetworkManager.hpp"

void NetworkManager::start()
{
    _thread = std::thread(&NetworkManager::startNetworkThread, this);
}

void NetworkManager::stop()
{
    for (std::vector<IUDPSocket *>::iterator it = _udpSockets.begin(); it != _udpSockets.end(); it++)
        _udpSockets.erase(it);
    for (std::vector<ITCPServer *>::iterator it = _tcpServers.begin(); it != _tcpServers.end(); it++)
        _tcpServers.erase(it);
    _thread.join();
}

void NetworkManager::startNetworkThread(NetworkManager *netManager)
{
    netManager->_context.run();
}

TCPServer *NetworkManager::createTCPServer(int port)
{
    TCPServer *server = new TCPServer(_context, port);
    _tcpServers.push_back(server);
    return (server);
}

IUDPSocket *NetworkManager::createSocketUDP(int port)
{
    UDPSocket *socket = new UDPSocket(_context, port);
    _udpSockets.push_back(socket);
    return (socket);
}

void NetworkManager::deleteSocketUDP(IUDPSocket *socket)
{
    auto it = std::find(_udpSockets.begin(), _udpSockets.end(), socket);

    _udpSockets.erase(it);
}

void NetworkManager::deleteTCPServer(ITCPServer *tcp)
{
    auto it = std::find(_tcpServers.begin(), _tcpServers.end(), tcp);

    _tcpServers.erase(it);
}