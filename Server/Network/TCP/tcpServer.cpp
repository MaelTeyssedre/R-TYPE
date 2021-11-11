/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPServer
*/

#include "tcpServer.hpp"
#include <functional>

TCPServer::TCPServer(asio::io_context &context, std::uint16_t port) : _context(context), _acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
{
 //   context.run();
    startAccept();
}

void TCPServer::send(size_t target, IPacket &data)
{
    std::vector<uint8_t> vec;
    std::string str = "Dog";

    vec.assign(str.begin(), str.end());
    mapUser[1]->addToQueue(vec);
}

void TCPServer::send(std::vector<size_t> targets, IPacket &data)
{
   /* for (int i = 0; i <= targets.size(); i++) {
        mapUser[targets.at(i)]->write(data);
    }*/
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
   // std::shared_ptr<tcpUser> newUser(_context);

   // _acceptor.async_accept(/socket, std::bind(&TCPServer::handleAccept, this, newUser));
    _acceptor.async_accept([this](std::error_code ec,  asio::ip::tcp::socket socket)
    {
        if (!ec) {
          //  newUser->start();
            mapUser.insert(std::make_pair(1,
            std::make_shared<tcpUser>(std::move(socket))
            ));
            mapUser[1]->start();
           // std::make_shared<tcpUser>(std::move(socket))->start()
        }
        Packet packet;

      // send(1, packet);
        startAccept();
    });
}

void TCPServer::handleAccept(std::shared_ptr<tcpUser> newUser)
{
    std::cout << "hello f,k," << std::endl;
}