/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPServer
*/

#include "tcpServer.hpp"
#include <functional>

TCPServer::TCPServer(asio::io_context &context, std::uint16_t port) : _context(context), _acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), _nbUsers(0)
{
    startAccept();
}

void TCPServer::send(size_t target, IPacket &data)
{
    _mapUser[target]->addToQueue(*data.unpack());
}

void TCPServer::send(std::vector<size_t> targets, IPacket &data)
{
    for (int i = 0; i <= targets.size(); i++)
        _mapUser[targets.at(i)]->addToQueue(*data.unpack());
}

void TCPServer::receive()
{
    for (int i = 0; i <= _mapUser.size(); i++) {
        //_mapUser[i]->read();
        
        std::cout << "test" << std::endl;
    }
}

void TCPServer::eject(size_t client)
{
    _mapUser.erase(client);
}

void TCPServer::startAccept()
{
    auto client = std::make_shared<asio::ip::tcp::socket>(_context);
    _acceptor.async_accept(*client, [this, client](const std::error_code &ec)
    {
        if (!ec) {
            auto [it, ok] = this->_mapUser.try_emplace(this->_nbUsers, std::make_shared<tcpUser>(client));
            it->second->start();
            this->_nbUsers++;
        } else {
            std::cerr << "ERROR RECEIVED: " << ec << std::endl;
        }
        this->startAccept();
    });
}

std::map<size_t, std::shared_ptr<tcpUser>> TCPServer::getUsers()
{
    return (_mapUser);
}