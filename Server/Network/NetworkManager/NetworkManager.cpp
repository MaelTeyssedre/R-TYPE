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

NetworkManager::~NetworkManager()
{
}

NetworkManager::NetworkManager() : _context(), _worker(), _udpSockets(), _tcpClients(), _tcpServers(), _thread(), _started(false)
{
}


void NetworkManager::start()
{
      _thread = std::thread(&NetworkManager::startNetworkThread, this);
}

void NetworkManager::stop()
{
 /*   for (std::vector<std::shared_ptr<IUDPSocket>>::iterator it = _udpSockets.begin(); it != _udpSockets.end(); it++)
        _udpSockets.erase(it);
   for (std::vector<std::shared_ptr<ITCPClient>>::iterator it = _tcpClients.begin(); it != _tcpClients.end(); it++)
        _tcpClients.erase(it);
   for (std::vector<std::shared_ptr<ITCPServer>>::iterator it = _tcpServers.begin(); it != _tcpServers.end(); it++)
        _tcpServers.erase(it);*/
    _thread.join();
}

void NetworkManager::startNetworkThread(NetworkManager *netManager)
{
    netManager->_context.run();
}

ITCPClient *NetworkManager::createTCPClient()
{
 //   TCPClient *client = new TCPClient(_context, 1342);
  //  _tcpClients.push_back(client);
   // return (client);
}

TCPServer *NetworkManager::createTCPServer()
{
    TCPServer *server = new TCPServer(_context, 1342);
    _tcpServers.push_back(server);
    return (server);
}

IUDPSocket *NetworkManager::createSocketUDP()
{
   // UDPSocket *socket = new UDPSocket(_context, 1342);
   // _udpSockets.push_back(socket);
   // return (socket);
}

void NetworkManager::deleteSocketUDP(IUDPSocket *socket)
{
 //   auto it = std::find(_udpSockets.begin(), _udpSockets.end(), socket);

  //  _udpSockets.erase(it);
}

void NetworkManager::deleteTCPClient(ITCPClient *tcp)
{
   // auto it = std::find(_tcpClients.begin(), _tcpClients.end(), tcp);

 //   _tcpClients.erase(it);
}

void NetworkManager::deleteTCPServer(ITCPServer *tcp)
{
 //   auto it = std::find(_tcpServers.begin(), _tcpServers.end(), tcp);

   // _tcpServers.erase(it);
}