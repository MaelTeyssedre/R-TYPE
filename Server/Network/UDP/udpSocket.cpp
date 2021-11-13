/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

#include "udpSocket.hpp"

UDPSocket::UDPSocket(asio::io_context &context, std::uint16_t port) : _context(context), _socket(context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port))
{
}

void UDPSocket::send(size_t target, IPacket &data)
{
  std::vector<uint8_t> vec;
  std::string str;

  str = "test from udp server";
  vec.assign(str.begin(), str.end());

  _socket.async_send_to(asio::buffer(vec), _endpoint, std::bind(&UDPSocket::handleSend, this));

}

void UDPSocket::handleSend()
{
}

void UDPSocket::send(std::vector<size_t> targets, IPacket &data)
{
   // for (int i = 0; i <= targets.size(); i++) {
     //   mapUser[targets.at(i)]->addToQueue(data);
    //}
}

std::vector<uint8_t> &UDPSocket::receive()
{
  char data[1024];

  _socket.async_receive_from(asio::buffer(data, 1024), _endpoint, [this](std::error_code ec, std::size_t bytes_recvd)
        {
          receive();
        });


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
}