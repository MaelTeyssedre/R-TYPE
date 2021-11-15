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
    std::cout << "start accept" << std::endl;
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

std::vector<uint8_t> TCPServer::receive()
{
    for (int i = 0; i <= _mapUser.size(); i++)
        _mapUser[i]->read();
}

void TCPServer::eject(size_t client)
{
    _mapUser.erase(client);
}

void TCPServer::startAccept()
{
    std::cout << "in accept" << std::endl;
    auto client = std::make_shared<asio::ip::tcp::socket>(_context);
    _acceptor.async_accept(*client, [this, &client](const std::error_code &ec)
    {
        std::cout << "async_accept" << std::endl;
        if (!ec) {
            std::cout << "new user" << std::endl;
            auto &[it, ok] = this->_mapUser.try_emplace(this->_nbUsers, std::make_shared<tcpUser>(client));
            std::cout << "try emplace result: " << ok << std::endl;
            std::cout << "AFTER INSERT" << std::endl;
            this->_mapUser[_nbUsers]->start();
            std::cout << "AFTER START" << std::endl;
            this->_nbUsers++;
            std::cout << "AFTER ADD" << std::endl;
        } else {
            std::cerr << "ERROR RECEIVED: " << ec << std::endl;
        }
        std::cout << "size: " << std::endl;
        std::cout << this->_mapUser.size() << std::endl;
        this->startAccept();
    });
}

std::map<size_t, std::shared_ptr<tcpUser>> TCPServer::getUsers()
{
    return (_mapUser);
}