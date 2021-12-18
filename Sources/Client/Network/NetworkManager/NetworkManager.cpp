#include "NetworkManager.hpp"

ITCPServer* rtype::NetworkManager::createTCPServer(int port)
{
	(void)port;
	return nullptr;
}

void rtype::NetworkManager::deleteTCPServer(ITCPServer* tcp)
{
	(void)tcp;
}

void rtype::NetworkManager::start()
{
	_context.run();
}

void rtype::NetworkManager::stop()
{
	for (std::vector<ITCPClient*>::iterator it = _tcpClients.begin(); it != _tcpClients.end(); it++)
		_tcpClients.erase(it);
	_thread.join();
}

void rtype::NetworkManager::startNetworkThread(NetworkManager* netManager)
{
	netManager->_context.run();
}

ITCPClient* rtype::NetworkManager::createTCPClient(std::string host, int port)
{
	auto sock = std::make_shared<asio::ip::tcp::socket>(_context);
	ITCPClient* server = new TCPClient(_context, sock, host, std::to_string(port));
	_tcpClients.push_back(server);
	return server;
}

void rtype::NetworkManager::deleteTCPClient(ITCPClient* client)
{
	(void)client;
}

IUDPSocket* rtype::NetworkManager::createSocketUDP(std::string host, int port)
{
	auto sock = std::make_shared<asio::ip::udp::socket>(_context);
	IUDPSocket* server = new UDPSocket(this->_context, host, std::to_string(port));
	_udpSockets.push_back(server);
	return server;
}

void rtype::NetworkManager::deleteSocketUDP(IUDPSocket* socket)
{
	(void)socket;
}
