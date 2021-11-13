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
    std::vector<uint8_t> vec;
    std::string str = "hello from server";

    vec.assign(str.begin(), str.end());
    std::cout << "Connection start" << std::endl;
    addToQueue(vec);
    write();
    read();
}

void tcpUser::addToQueue(std::vector<uint8_t> message)
{
    std::vector<uint8_t> vec;

     std::string str = "hello from server";

    vec.assign(str.begin(), str.end());
    std::cout << "Connection start" << std::endl;
    //addToQueue(vec);
    _queue.push(vec);
}


void tcpUser::read()
{
    std::cout << "bofore: " << std::endl;
   // asio::async_read(_socket, _input, std::bind(&tcpUser::doRead, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    std::cout << "after: " << std::endl;
}

void tcpUser::doRead(const std::error_code &ec, size_t bytes)
{
    std::cout << "in doread: " << std::endl;
    if (!ec) {
        std::istream stream(&_input);
        std::string line;
        std::getline(stream, line);
      //  std::cout << "receive: " << line << std::endl;
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
