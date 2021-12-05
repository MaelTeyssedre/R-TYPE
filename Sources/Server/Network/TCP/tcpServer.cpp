#include "tcpServer.hpp"
#include <functional>
#include "Constants.hpp"

rtype::TCPServer::TCPServer(asio::io_context &context, std::uint16_t port)
    : _context(context), _acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), _nbUsers(0)
{
    startAccept();
}

void rtype::TCPServer::send(IPacket *data)
{
    _mapUser[data->getId()]->addToQueue(data->unpack());
    _mapUser[data->getId()]->write();
}

void rtype::TCPServer::send(std::vector<size_t> targets, IPacket *data)
{
    for (auto j : targets)
        if (j < targets.size())
            _mapUser[j]->addToQueue(data->unpack());
}

void rtype::TCPServer::receive()
{
    for (size_t i = 0; i < _mapUser.size(); i++) {
        _mapUser[i]->read();
    }
}

void rtype::TCPServer::eject(size_t client)
{
    _mapUser.erase(_mapUser.begin() + client);
}

void rtype::TCPServer::startAccept()
{
    auto client = std::make_shared<asio::ip::tcp::socket>(_context);
    _acceptor.async_accept(*client, [this, client](const std::error_code &ec)
                           {
                               if (!ec)
                               {
                                   this->_mapUser.push_back(std::make_shared<rtype::tcpUser>(client));
                                   this->_mapUser.back()->start();
                                   this->_nbUsers++;
                               }
                               else
                                   std::cerr << "ERROR RECEIVED: " << ec << std::endl;
                               this->startAccept();
                           });
}

std::vector<std::shared_ptr<rtype::tcpUser>> rtype::TCPServer::getUsers()
{
    return (_mapUser);
}

std::queue<IPacket *> *rtype::TCPServer::getBuffer()
{
    
    for (size_t i = 0; i < _mapUser.size(); i++)
    {
        IPacket *packetPtr = new rtype::Packet;
        auto tmp = _mapUser[i]->getInput();
        _mapUser[i]->delInput(packetPtr->pack(tmp)),
        tmp.clear();
        packetPtr->setId(i);
        if (packetPtr->unpack().size())
            _buffers.emplace(packetPtr);
        _mapUser[i]->clearInput();
    }
    return (&_buffers);
}
