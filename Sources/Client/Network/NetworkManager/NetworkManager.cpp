#include "NetworkManager.hpp"

ITCPServer *rtype::NetworkManager::createTCPServer(int port)
{
    (void)port;
    return nullptr;
}

void rtype::NetworkManager::deleteTCPServer(ITCPServer *tcp)
{
    (void)tcp;
}

void rtype::NetworkManager::start()
{
    // _worker = new asio::io_context::work(_context);
    _context.run();
   // _thread = std::thread(&rtype::NetworkManager::startNetworkThread, this);
}

void rtype::NetworkManager::stop()
{
    for (std::vector<ITCPClient *>::iterator it = _tcpClients.begin(); it != _tcpClients.end(); it++)
        _tcpClients.erase(it);
    _thread.join();
}

void rtype::NetworkManager::startNetworkThread(NetworkManager *netManager)
{
    netManager->_context.run();
}

ITCPClient *rtype::NetworkManager::createTCPClient(int port)
{
    auto sock = std::make_shared<asio::ip::tcp::socket>(_context);
    ITCPClient *server = new TCPClient(_context, sock, "127.0.0.1", std::to_string(port));
    _tcpClients.push_back(server);
    return server;
}

void rtype::NetworkManager::deleteTCPClient(ITCPClient *client)
{
    (void)client;
}

IUDPSocket *rtype::NetworkManager::createSocketUDP(int port)
{
    auto sock = std::make_shared<asio::ip::udp::socket>(_context);
    IUDPSocket *server = new UDPSocket(this->_context, "127.0.0.1", std::to_string(port));
    _udpSockets.push_back(server);
    return server;
}

void rtype::NetworkManager::deleteSocketUDP(IUDPSocket *socket)
{
    (void)socket;
}
