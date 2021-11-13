/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** NetworkManager
*/

#include "NetworkManager.hpp"
#include "tcpClient.hpp"
#include "tcpServer.hpp"
#include "udpSocket.hpp"

void NetworkManager::start()
{
      _thread = std::thread(&NetworkManager::startNetworkThread, this);
}

void NetworkManager::stop()
{
    for (std::vector<IUDPSocket *>::iterator it = _udpSockets.begin(); it != _udpSockets.end(); it++)
        _udpSockets.erase(it);
    for (std::vector<ITCPClient *>::iterator it = _tcpClients.begin(); it != _tcpClients.end(); it++)
        _tcpClients.erase(it);
    for (std::vector<ITCPServer *>::iterator it = _tcpServers.begin(); it != _tcpServers.end(); it++)
        _tcpServers.erase(it);
    _thread.join();
}

void NetworkManager::startNetworkThread(NetworkManager *netManager)
{
    netManager->_context.run();
}

ITCPClient *NetworkManager::createTCPClient(int port)
{}

TCPServer *NetworkManager::createTCPServer(int port)
{
    TCPServer *server = new TCPServer(_context, port);
    _tcpServers.push_back(server);
    return (server);
}

UDPSocket *NetworkManager::createSocketUDP(int port)
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

void NetworkManager::deleteTCPClient(ITCPClient *tcp)
{
    auto it = std::find(_tcpClients.begin(), _tcpClients.end(), tcp);

    _tcpClients.erase(it);
}

void NetworkManager::deleteTCPServer(ITCPServer *tcp)
{
    auto it = std::find(_tcpServers.begin(), _tcpServers.end(), tcp);

    _tcpServers.erase(it);
}