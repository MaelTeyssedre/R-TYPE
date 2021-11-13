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
    for (int i = 0; i <= targets.size(); i++) {
        _mapUser[targets.at(i)]->addToQueue(*data.unpack());
    }
}

std::vector<uint8_t> TCPServer::receive()
{
    for (int i = 0; i <= _mapUser.size(); i++) {
        _mapUser[i]->read();
    }
}

void TCPServer::eject(size_t client)
{
    _mapUser.erase(client);
}

void TCPServer::startAccept()
{
    _acceptor.async_accept([this](std::error_code ec,  asio::ip::tcp::socket socket)
    {
        if (!ec) {
            _mapUser.insert(std::make_pair(_nbUsers,
            std::make_shared<tcpUser>(std::move(socket))
            ));
            _mapUser[_nbUsers]->start();
            _nbUsers++;
        }
        startAccept();
    });
    std::cout << "in start accept" << std::endl;
    if (_mapUser.size() != 0)
        receive();
    std::cout << "after start accept" << std::endl;

}

void TCPServer::handleAccept(std::shared_ptr<tcpUser> newUser)
{
    std::cout << "hello f,k," << std::endl;
}