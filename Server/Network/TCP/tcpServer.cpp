/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPServer
*/

#include "tcpServer.hpp"
#include <asio.hpp>
#include <functional>

TCPServer::TCPServer(asio::io_context &context) : _context(context), _acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 1342))
{
    std::cout << "create tcp server" << std::endl;
  //  accept();
}

void TCPServer::accept()
{
    std::cout << "before accept" << std::endl;
    _acceptor.async_accept([this](std::error_code ec, asio::ip::tcp::socket socket)
    {
        std::cout << "inside accept" << std::endl;
        /*if (!ec) {
            std::make_shared<tcpUser>(std::move(socket))->start();
        }*/
        accept();
    });
    std::cout << "after accept" << std::endl;

}
/*
void TCPServer::doAccept()
{
    std::cout << "new Client" << std::endl;
   // accept();
}

void TCPServer::send(IPacket &data)
{

}

void TCPServer::send(tcpUser &user, IPacket &data)
{
   // user.getSocket()->async_send(asio::buffer(data.unpack(), 10), std::bind(&TCPServer::doWrite, this, std::placeholders::_1, std::placeholders::_2));
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

   // asio::async_read(_socket, asio::buffer(&rawData->at(0), 10), std::bind(&TCPServer::doRead, this));
   // size = packet->pack(rawData);
    return (packet);
}

void TCPServer::doRead()
{
    std::cout << "receive data" << std::endl;
} 

void TCPServer::start()
{
    std::cout << "start" << std::endl;
    accept();
  //  receive();
}

void TCPServer::stop()
{
    //_context.stop();
    std::cout << "stop" << std::endl;
}

void TCPServer::eject(size_t client)
{
    _users.erase(client);
    std::cout << "eject player" << std::endl;
}*/