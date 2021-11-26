/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

#include "cUDPSocket.hpp"

void UDPSocket::send(IPacket &data)
{
    _socket.async_send_to(asio::buffer(data.unpack()), _endpoint, std::bind(&UDPSocket::handleSend, this));
}

void UDPSocket::handleSend()
{
    _logger.logln(std::string{"UDP client send data"});
}

void UDPSocket::receive()
{
    _socket.async_receive_from(asio::buffer(_data, 9), _endpoint, [this](std::error_code ec, std::size_t bytes)
    {
      if (!ec) {
          std::istream stream(&_input);
          std::string line;
          std::getline(stream, line);
          _input.consume(bytes);
          _logger.log(std::string{"UDP client receive: "});
          _logger.log(std::to_string(bytes));
          _logger.logln(std::string{"bytes"});
          receive();
      }
    });
    std::cout << _data << std::endl;
}
