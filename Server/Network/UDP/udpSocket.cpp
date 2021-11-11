/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

#include "udpSocket.hpp"
/*
UDPSocket::UDPSocket(asio::io_context &context, std::uint16_t port) : _context(context)
{
    startAccept();
}*/

void UDPSocket::send(size_t target, IPacket &data)
{
   // mapUser[target]->addToQueue(*data.unpack());
  // _socket.asyn_send_to()
}

void UDPSocket::send(std::vector<size_t> targets, IPacket &data)
{
   // for (int i = 0; i <= targets.size(); i++) {
     //   mapUser[targets.at(i)]->addToQueue(data);
    //}
}

std::vector<uint8_t> UDPSocket::receive()
{
}

void UDPSocket::start()
{

}

void UDPSocket::stop()
{

}

void UDPSocket::eject(size_t client)
{
}

void UDPSocket::startAccept()
{
  /*  _acceptor.async_accept([this](std::error_code ec,  asio::ip::tcp::socket socket)
    {
        if (!ec) {
            mapUser.insert(std::make_pair(_nbUsers,
            std::make_shared<tcpUser>(std::move(socket))
            ));
            mapUser[_nbUsers]->start();
            _nbUsers++;
        }
        startAccept();
    });*/
}