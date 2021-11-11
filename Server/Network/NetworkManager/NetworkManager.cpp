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

NetworkManager::~NetworkManager()
{
}

NetworkManager::NetworkManager() : _context(), _worker(), _udpSockets(), _tcpClients(), _tcpServers(), _thread(), _started(false)
{
}


void NetworkManager::start()
{
  
  //  _context.run();
  //  _thread = std::thread(&NetworkManager::startNetworkThread, this);
}

void NetworkManager::stop()
{
 /*   for (std::vector<std::shared_ptr<IUDPSocket>>::iterator it = _udpSockets.begin(); it != _udpSockets.end(); it++)
        _udpSockets.erase(it);
   for (std::vector<std::shared_ptr<ITCPClient>>::iterator it = _tcpClients.begin(); it != _tcpClients.end(); it++)
        _tcpClients.erase(it);
   for (std::vector<std::shared_ptr<ITCPServer>>::iterator it = _tcpServers.begin(); it != _tcpServers.end(); it++)
        _tcpServers.erase(it);*/
   // _thread.join();
}

void NetworkManager::startNetworkThread(NetworkManager *netManager)
{
    netManager->_context.run();
}

std::shared_ptr<ITCPClient> NetworkManager::createTCPClient()
{
 /*   std::shared_ptr<TCPClient> client;
    _tcpClients.push_back(client);
    return (client);*/
}

TCPServer *NetworkManager::createTCPServer()
{
    TCPServer *server = new TCPServer(_context, 1342);
    _tcpServers.push_back(server);
    return (server);
}

std::shared_ptr<IUDPSocket> NetworkManager::createSocketUDP()
{
    std::shared_ptr<UDPSocket> socket;
  //  _udpSockets.push_back(socket);
    return (socket);
}

void NetworkManager::deleteSocketUDP(std::shared_ptr<IUDPSocket> socket)
{
 //   auto it = std::find(_udpSockets.begin(), _udpSockets.end(), socket);

  //  _udpSockets.erase(it);
}

void NetworkManager::deleteTCPClient(std::shared_ptr<ITCPClient> tcp)
{
   // auto it = std::find(_tcpClients.begin(), _tcpClients.end(), tcp);

 //   _tcpClients.erase(it);
}

void NetworkManager::deleteTCPServer(std::shared_ptr<ITCPServer> tcp)
{
 //   auto it = std::find(_tcpServers.begin(), _tcpServers.end(), tcp);

   // _tcpServers.erase(it);
}