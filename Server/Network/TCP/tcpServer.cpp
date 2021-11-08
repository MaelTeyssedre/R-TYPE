/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPServer
*/

#include "tcpServer.hpp"
#include <asio.hpp>
#include <functional>

TCPServer::TCPServer(asio::io_context context, asio::ip::tcp::acceptor accept, asio::ip::tcp::socket sock) : _context(context), _acceptor(accept), _socket(sock)
{
}

TCPServer::~TCPServer()
{}

void TCPServer::accept()
{
    asio::ip::tcp::socket sock(_context);

    _acceptor.async_accept(sock, std::bind(&TCPServer::doAccept, this));
}

void TCPServer::doAccept()
{
    std::cout << "new Client" << std::endl;
}

void TCPServer::send(IPacket &data)
{

}

void TCPServer::send(tcpUser &user, IPacket &data)
{
    user.getSocket()->async_send(asio::buffer(data.unpack(), 10), std::bind(&TCPServer::doWrite, this, std::placeholders::_1, std::placeholders::_2));
}

void TCPServer::send(std::vector<size_t> target, IPacket &data)
{

}

void TCPServer::sendToAll(IPacket &data)
{
    for (int i = _users.begin()->first; _users.end()->first; i++) {
        send(_users.at(i), data);
    }
}

void TCPServer::doWrite(const std::error_code &ec, size_t bytes)
{
    std::cout << "send data" << std::endl;
}

std::shared_ptr<IPacket> TCPServer::receive()
{
    std::shared_ptr<Packet> packet;
    std::shared_ptr<std::vector<int8_t>> rawData;
    size_t size;

    asio::async_read(_socket, asio::buffer(&rawData->at(0), 10), std::bind(&TCPServer::doRead, this));
    size = packet->pack(rawData);
    return (packet);
}

void TCPServer::doRead()
{
    std::cout << "receive data" << std::endl;
} 

void TCPServer::start()
{
    _context.run();
    std::cout << "start" << std::endl;
}

void TCPServer::stop()
{
    _context.stop();
    std::cout << "stop" << std::endl;
}

void TCPServer::eject(size_t client)
{
    _users.erase(client);
    std::cout << "eject player" << std::endl;
}