#include "tcpServer.hpp"
#include <functional>
#include "Constants.hpp"

TCPServer::TCPServer(asio::io_context &context, std::uint16_t port)
    : _context(context), _acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), _nbUsers(0)
{
    startAccept();
}

void TCPServer::send(size_t target, IPacket &data)
{
    _mapUser[target]->addToQueue(data.unpack());
}

void TCPServer::send(std::vector<size_t> targets, IPacket &data)
{
    for (auto j : targets)
        if (j < targets.size())
            _mapUser[j]->addToQueue(data.unpack());
}

void TCPServer::receive()
{
    for (size_t i = 0; i < _mapUser.size(); i++)
        _mapUser[i]->read();
}

void TCPServer::eject(size_t client)
{
    _mapUser.erase(_mapUser.begin() + client);
}

void TCPServer::startAccept()
{
    auto client = std::make_shared<asio::ip::tcp::socket>(_context);
    _acceptor.async_accept(*client, [this, client](const std::error_code &ec)
                           {
                               if (!ec)
                               {
                                   this->_mapUser.push_back(std::make_shared<tcpUser>(client));
                                   this->_mapUser.back()->start();
                                   this->_nbUsers++;
                               }
                               else
                                   std::cerr << "ERROR RECEIVED: " << ec << std::endl;
                               this->startAccept();
                           });
}

std::vector<std::shared_ptr<tcpUser>> TCPServer::getUsers()
{
    return (_mapUser);
}

std::queue<Packet> &TCPServer::getRequest()
{
    for (size_t i = 0; i < _mapUser.size(); i++)
    {
        Packet packetPtr;
        packetPtr.pack(_mapUser[i]->getInput());
        packetPtr.setId(i);
        _buffer.push(std::move(packetPtr));
    }
    return (_buffer);
}