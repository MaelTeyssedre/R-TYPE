/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** tcpUser
*/

#include "tcpUser.hpp"
#include <iostream>

void tcpUser::start()
{
     std::cout << "in new user" << std::endl;
    write();
    read();
    std::cout << "out new user" << std::endl;
}

void tcpUser::addToQueue(std::vector<uint8_t> message)
{
    _queue.push(message);
}


void tcpUser::read()
{
    std::cout << "BEFORE READ" << std::endl;
   asio::async_read(*_socket, _input, std::bind(&tcpUser::doRead, this, std::placeholders::_1, std::placeholders::_2));
    std::cout << "AFTER READ" << std::endl;
}

void tcpUser::doRead(const std::error_code &ec, size_t bytes)
{
    std::cout << "DO READ" << std::endl;
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
    std::cout << "BEFORE WRITE" << std::endl;
    asio::async_write(*_socket, asio::buffer(_queue.front()), std::bind(&tcpUser::doWrite, this, std::placeholders::_1));
    std::cout << "AFTER WRITE" << std::endl;
}

void tcpUser::doWrite(const std::error_code &ec)
{
    std::cout << "DO WRITE" << std::endl;
    if (!ec) {
      _queue.pop();
      if (!_queue.empty())
        write();
    } else
        std::cerr << ec.message() << std::endl;
}
