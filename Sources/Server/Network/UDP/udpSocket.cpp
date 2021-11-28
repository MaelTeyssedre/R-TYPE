#include "udpSocket.hpp"

void rtype::UDPSocket::send(IPacket &data)
{
    _socket.async_send_to(asio::buffer(data.unpack()), _endpoint, std::bind(&rtype::UDPSocket::handleSend, this));
}

void rtype::UDPSocket::handleSend()
{
    std::cout << "send data via udp" << std::endl;
}

void rtype::UDPSocket::receive()
{
    _socket.async_receive_from(asio::buffer(_data, MAX_LENGTH), _endpoint, [this](std::error_code ec, std::size_t bytes)
                               {
                                   if (!ec)
                                   {
                                       std::istream stream(&_input);
                                       std::string line;
                                       std::getline(stream, line);
                                       _input.consume(bytes);
                                       receive();
                                   }
                               });
    std::cout << _data << std::endl;
}
