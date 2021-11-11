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
    mapUser[target]->addToQueue(*data.unpack());
}

void TCPServer::send(std::vector<size_t> targets, IPacket &data)
{
    for (int i = 0; i <= targets.size(); i++) {
        mapUser[targets.at(i)]->addToQueue(*data.unpack());
    }
}

std::vector<uint8_t> TCPServer::receive()
{
}

void TCPServer::start()
{

}

void TCPServer::stop()
{

}

void TCPServer::eject(size_t client)
{
}

void TCPServer::startAccept()
{
    _acceptor.async_accept([this](std::error_code ec,  asio::ip::tcp::socket socket)
    {
        if (!ec) {
            mapUser.insert(std::make_pair(_nbUsers,
            std::make_shared<tcpUser>(std::move(socket))
            ));
            mapUser[_nbUsers]->start();
            _nbUsers++;
        }
        startAccept();
    });
}

void TCPServer::handleAccept(std::shared_ptr<tcpUser> newUser)
{
    std::cout << "hello f,k," << std::endl;
}