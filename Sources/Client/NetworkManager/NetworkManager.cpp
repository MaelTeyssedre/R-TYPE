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
    for (std::vector<ITCPClient *>::iterator it = _tcpClients.begin(); it != _tcpClients.end(); it++)
        _tcpClients.erase(it);
    _thread.join();
}

void NetworkManager::startNetworkThread(NetworkManager *netManager)
{
    netManager->_context.run();
}

ITCPClient *NetworkManager::createTCPClient(int port)
{
    std::cout << "1" << std::endl;
    auto sock = std::make_shared<asio::ip::tcp::socket>(_context);
  std::cout << "2" << std::endl;

    TCPClient *server = new TCPClient(_context, sock, "127.0.0.1", std::to_string(port));
  std::cout << "3" << std::endl;
    _tcpClients.push_back(server);
      std::cout << "4" << std::endl;
    return (server);
}

void NetworkManager::deleteTCPClient(ITCPClient *client)
{
  (void)client;
}