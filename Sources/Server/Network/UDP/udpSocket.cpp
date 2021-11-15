/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

#include "udpSocket.hpp"

void UDPSocket::send(IPacket &data)
{ auto message = std::make_shared<std::string>("Hello, World\n");
std::cout << "here" << std::endl;
   _socket.async_send_to(asio::buffer(*message), _endpoint, std::bind(&UDPSocket::handleSend, this));
}

void UDPSocket::handleSend()
{
  std::cout << "send data via udp" << std::endl;
}

void UDPSocket::receive()
{
  _socket.async_receive_from(asio::buffer(_data, MAX_LENGTH), _endpoint, [this](std::error_code ec, std::size_t bytes)
  {
      std::istream stream(&_input);
      std::string line;
      std::getline(stream, line);
      _input.consume(bytes);
      receive();
  });
  std::cout << _data << std::endl;
}