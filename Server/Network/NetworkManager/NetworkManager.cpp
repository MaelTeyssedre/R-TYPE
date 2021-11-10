/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** NetworkManager
*/

#include "NetworkManager.hpp"
#include "TCPClient.hpp"
//#include "tcpServer.hpp"
#include "udpSocket.hpp"

//TODO add loger

NetworkManager::~NetworkManager()
{
}

NetworkManager::NetworkManager(std::uint16_t port): _server(new TCPServer(_ioContext))
{
    std::cout << "create net manager" << std::endl;
    _ioContext.run();
}

/*
void NetworkManager::start()
{
  //  _thread = std::thread(NetworkManager::startNetworkThread, _ioContext, _udpSockets, _tcpClients, _tcpServers);
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

void NetworkManager::startNetworkThread(asio::io_context &ioContext,std::vector<std::shared_ptr<IUDPSocket>> udpSockets, std::vector<std::shared_ptr<ITCPClient>>  tcpClients,  std::vector<std::shared_ptr<ITCPServer>> tcpServer)
{
    ioContext.run();
}

std::shared_ptr<ITCPClient> NetworkManager::createTCPClient()
{
    std::shared_ptr<TCPClient> client;
    _tcpClients.push_back(client);
    return (client);
}

ITCPServer &NetworkManager::createTCPServer()
{
    asio::io_context context;

    TCPServer server(context);
  //  server.start();
    std::cout << "here" << std::endl;
    context.run();
   // _tcpServers.push_back(server);
   // return (server);
}

std::shared_ptr<IUDPSocket> NetworkManager::createSocketUDP()
{
    std::shared_ptr<UDPSocket> socket;
    _udpSockets.push_back(socket);
    return (socket);
}

void NetworkManager::deleteSocketUDP(std::shared_ptr<IUDPSocket> socket)
{
    auto it = std::find(_udpSockets.begin(), _udpSockets.end(), socket);

    _udpSockets.erase(it);
}

void NetworkManager::deleteTCPClient(std::shared_ptr<ITCPClient> tcp)
{
    auto it = std::find(_tcpClients.begin(), _tcpClients.end(), tcp);

    _tcpClients.erase(it);
}

void NetworkManager::deleteTCPServer(std::shared_ptr<ITCPServer> tcp)
{
    auto it = std::find(_tcpServers.begin(), _tcpServers.end(), tcp);

    _tcpServers.erase(it);
}*/