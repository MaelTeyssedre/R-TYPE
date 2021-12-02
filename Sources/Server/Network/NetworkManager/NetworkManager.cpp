#include "NetworkManager.hpp"

void rtype::NetworkManager::start()
{
    _thread = std::thread(&rtype::NetworkManager::startNetworkThread, this);
}

void rtype::NetworkManager::stop()
{
    for (std::vector<IUDPSocket *>::iterator it = _udpSockets.begin(); it != _udpSockets.end(); it++)
        _udpSockets.erase(it);
    for (std::vector<ITCPServer *>::iterator it = _tcpServers.begin(); it != _tcpServers.end(); it++)
        _tcpServers.erase(it);
    _thread.join();
}

void rtype::NetworkManager::startNetworkThread(NetworkManager *netManager)
{
    netManager->_context.run();
}

ITCPServer *rtype::NetworkManager::createTCPServer(int port)
{
    TCPServer *server = new TCPServer(_context, port);
    _tcpServers.push_back(server);
    return (server);
}

IUDPSocket *rtype::NetworkManager::createSocketUDP(std::string host, int port)
{
    (void)host;
    UDPSocket *socket = new UDPSocket(_context, port);
    _udpSockets.push_back(socket);
    return (socket);
}

void rtype::NetworkManager::deleteSocketUDP(IUDPSocket *socket)
{
    auto it = std::find(_udpSockets.begin(), _udpSockets.end(), socket);
    _udpSockets.erase(it);
}

void rtype::NetworkManager::deleteTCPServer(ITCPServer *tcp)
{
    auto it = std::find(_tcpServers.begin(), _tcpServers.end(), tcp);
    _tcpServers.erase(it);
}

ITCPClient *rtype::NetworkManager::createTCPClient(int port)
{
    (void)port;
    return nullptr;
}

void rtype::NetworkManager::deleteTCPClient(ITCPClient *tcp)
{
    (void)tcp;
}
