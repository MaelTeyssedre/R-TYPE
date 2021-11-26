#include "NetworkManager.hpp"

ITCPServer *NetworkManager::createTCPServer(int port)
{
    (void)port;
    return nullptr;
}

void NetworkManager::deleteTCPServer(ITCPServer *tcp)
{
    (void)tcp;
}

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
    auto sock = std::make_shared<asio::ip::tcp::socket>(_context);
    ITCPClient *server = new TCPClient(_context, sock, "127.0.0.1", std::to_string(port));
    _tcpClients.push_back(server);
    return server;
}

void NetworkManager::deleteTCPClient(ITCPClient *client)
{
    (void)client;
}

IUDPSocket *NetworkManager::createSocketUDP(int port)
{
    auto sock = std::make_shared<asio::ip::udp::socket>(_context);
    IUDPSocket *server = new UDPSocket(this->_context, "127.0.0.1", std::to_string(port));
    _udpSockets.push_back(server);
    return server;
}

void NetworkManager::deleteSocketUDP(IUDPSocket *socket)
{
    (void)socket;
}
