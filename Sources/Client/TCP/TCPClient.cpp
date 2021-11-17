/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPClient
*/

#include "TCPClient.hpp"

TCPClient::TCPClient(asio::io_context &context, std::shared_ptr<asio::ip::tcp::socket> socket, std::string host, std::string port) : _context(context), _resolver(context), _socket(socket)
{
    std::cout << "here" << std::endl;
    asio::connect(*_socket, _resolver.resolve(host, port));
  std::cout << "here2" << std::endl;
}

/*void TCPClient::connect(std::string &ip, std::uint16_t port)
{
  //  asio::ip::udp::resolver resolv(_context);
   // asio::ip::tcp::endpoint ep(asio::ip::address::from_string(ip), port);
    //asio::ip::tcp::socket sock(_context, ep.protocol());
}*/

IPacket &TCPClient::receive()
{
    Packet packet;
    asio::error_code ec;
    _socket->read_some(asio::buffer(_reply), ec);
    for (size_t i = 0; i <= 9; i++) {
        std::cout << _reply[i];
    }
    //packet.pack(_reply);
    memset(_reply, 0, 9);
    return (packet);
}

void TCPClient::send(IPacket &packet)
{
//    asio::async_write(*_socket, asio::buffer(packet.unpack()), std::bind(&tcpUser::doWrite, this, std::placeholders::_1, std::placeholders::_2));
      std::string str = "hello from server";
  std::vector<uint8_t> vec;

  vec.assign(str.begin(), str.end());
  packet.pack(vec);
    _socket->write_some(asio::buffer(vec, vec.size()));
  //   asio::write(_socket, asio::buffer(_reply, 9));
}

void TCPClient::disconnect()
{}