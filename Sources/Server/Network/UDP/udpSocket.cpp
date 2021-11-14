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

std::vector<uint8_t> &UDPSocket::receive()
{
  _socket.async_receive_from(_input, _endpoint, [this](std::error_code ec, std::size_t bytes)
  {
      std::istream stream(&_input);
      std::string line;
      std::getline(stream, line);
      _input.consume(bytes);
      receive();
  });

}