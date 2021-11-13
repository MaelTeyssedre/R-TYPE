/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** tcpUser
*/

#include "tcpUser.hpp"
#include <iostream>

tcpUser::tcpUser(asio::ip::tcp::socket &&socket) : _socket(std::move(socket))
{}

void tcpUser::start()
{
    write();
    read();
}

void tcpUser::addToQueue(std::vector<uint8_t> message)
{
    _queue.push(message);
}


void tcpUser::read()
{
   asio::async_read(_socket, _input, std::bind(&tcpUser::doRead, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void tcpUser::doRead(const std::error_code &ec, size_t bytes)
{
    if (!ec) {
        std::istream stream(&_input);
        std::string line;
        std::getline(stream, line);
        _input.consume(bytes);
        read();
    } else
        std::cerr << ec.message() << std::endl;
}

void tcpUser::write()
{
    asio::async_write(_socket, asio::buffer(_queue.front()), std::bind(&tcpUser::doWrite, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void tcpUser::doWrite(const std::error_code &ec, size_t bytes)
{
    (void)bytes;
    if (!ec) {
      _queue.pop();
      if (!_queue.empty())
        write();
    } else {
        std::cerr << ec.message() << std::endl;
    }
}
