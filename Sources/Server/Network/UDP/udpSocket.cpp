/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

#include "udpSocket.hpp"

void UDPSocket::send(IPacket &data)
{
   _socket.async_send_to(asio::buffer(*data.unpack()), _endpoint, std::bind(&UDPSocket::handleSend, this));
}

void UDPSocket::handleSend()
{
  std::cout << "send data via udp" << std::endl;
}

void UDPSocket::receive()
{
  _socket.async_receive_from(asio::buffer(_data, MAX_LENGTH), _endpoint, [this](std::error_code ec, std::size_t bytes)
  {
    if (!ec) {
      std::istream stream(&_input);
      std::string line;
      std::getline(stream, line);
      _input.consume(bytes);
      receive();
    }
  });
  std::cout << _data << std::endl;
}