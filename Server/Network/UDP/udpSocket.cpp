/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

#include "udpSocket.hpp"

UDPSocket::UDPSocket(asio::io_context &context, std::uint16_t port) : _context(context), _socket(context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port))
{}

void UDPSocket::send(IPacket &data)
{
  _socket.async_send_to(asio::buffer(*data.unpack()), _endpoint, std::bind(&UDPSocket::handleSend, this));
}

void UDPSocket::handleSend()
{
  std::cout << "send data via udp" << std::endl;
}

std::vector<uint8_t> &UDPSocket::receive()
{
  char data[1024];

  _socket.async_receive_from(asio::buffer(data, 1024), _endpoint, [this](std::error_code ec, std::size_t bytes_recvd)
  {
    receive();
  });
}