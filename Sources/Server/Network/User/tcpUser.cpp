#include "tcpUser.hpp"
#include <iostream>
#include <memory>


void rtype::tcpUser::start()
{
    write();
    read();
}

void rtype::tcpUser::addToQueue(std::vector<uint8_t> message)
{
    _queue.push(message);
}

void rtype::tcpUser::read()
{
    _socket->async_read_some(asio::buffer(_data, 1), std::bind(&rtype::tcpUser::doRead, this, std::placeholders::_1, std::placeholders::_2));
    //for (auto i : _data)
    //    std::cout << (uint8_t)i << std::endl;
  //  asio::async_read(*_socket, asio::buffer(_input), std::bind(&rtype::tcpUser::doRead, this, std::placeholders::_1, std::placeholders::_2));
}

void rtype::tcpUser::doRead(const std::error_code &ec, size_t bytes)
{
    (void)bytes;
    if (!ec)
    {
        std::cout << _data[0] << std::endl;
        read();
        _sizeInput++;
    }
    else
        std::cerr << ec.message() << std::endl;
  //  std::memset(_data, 0, sizeof(_data));
}

void rtype::tcpUser::write()
{
    if (_queue.empty())
    {
        return;
    }
    asio::async_write(*_socket, asio::buffer(_queue.front()), std::bind(&rtype::tcpUser::doWrite, this, std::placeholders::_1, std::placeholders::_2));
}

void rtype::tcpUser::doWrite(const std::error_code &ec, std::size_t bytes_transfered)
{
    (void)bytes_transfered;
    if (!ec)
    {
        _queue.pop();
        if (!_queue.empty())
            write();
    }
    else
        std::cerr << ec.message() << std::endl;
}

std::vector<uint8_t> &rtype::tcpUser::getInput()
{
    return (_input);
}


size_t &rtype::tcpUser::getSizeInput()
{
    return (_sizeInput);
}
