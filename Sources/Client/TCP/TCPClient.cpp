/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPClient
*/

#include "TCPClient.hpp"

TCPClient::TCPClient(asio::io_context &context, std::shared_ptr<asio::ip::tcp::socket> socket, std::string host, std::string port) : _context(context), _resolver(context), _socket(socket), _logger("log.txt")
{
    std::string str = "Client connected to host: ";
    
    asio::connect(*_socket, _resolver.resolve(host, port));
    str.append(host);
    str.append(", and port: ");
    str.append(port);
    _logger.logln(str);
}

void TCPClient::receive()
{
    _socket->async_read_some(asio::buffer(_reply), std::bind(&TCPClient::doRead, this, std::placeholders::_1, std::placeholders::_2));
    for (size_t i = 0; i <= 9; i++) {
        std::cout << _reply[i];
    }
}

void TCPClient::doRead(const std::error_code &ec, size_t bytes)
{
    std::string str;

    if (!ec) {
        str = "receive: ";
        str.append(std::to_string(bytes));
        str.append("bytes");
        _logger.logln(str);
        _buffer->putInBuffer(bytes, _reply);
        receive();
    } else
        std::cerr << ec.message() << std::endl;
}

void TCPClient::send(IPacket &packet)
{
    std::vector<uint8_t> vec;

    vec.assign(.begin(), str.end());
    packet.pack(vec);
    _socket->async_write_some(asio::buffer(vec, vec.size()), std::bind(&TCPClient::doWrite, this, std::placeholders::_1, std::placeholders::_2));
}

void TCPClient::doWrite(const std::error_code &ec, size_t bytes)
{
    std::string str = "Send: ";

    if (!ec) {
        str.append(std::to_string(bytes));
        str.append("bytes");
        _logger.logln(str);
    } else
        std::cerr << ec.message() << std::endl;
}

std::shared_ptr<Buffer> TCPClient::getData()
{
    return (_buffer);
}

void TCPClient::disconnect()
{
    _socket->close();
    _logger.logln(std::string{"Client disconnect"});
}