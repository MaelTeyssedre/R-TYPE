#include "tcpUser.hpp"
#include <iostream>

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
    asio::async_read(*_socket, asio::buffer(_input, 1), std::bind(&tcpUser::doRead, this, std::placeholders::_1, std::placeholders::_2));
}

void tcpUser::doRead(const std::error_code &ec, size_t bytes)
{
    (void)bytes;
    if (!ec)
    {
        read();
        _sizeInput++;
    }
    else
        std::cerr << ec.message() << std::endl;
}

void tcpUser::write()
{
    if (_queue.empty())
    {
        std::cout << "IN WRITE EMPTY" << std::endl;
        return;
    }
    asio::async_write(*_socket, asio::buffer(_queue.front()), std::bind(&tcpUser::doWrite, this, std::placeholders::_1, std::placeholders::_2));
}

void tcpUser::doWrite(const std::error_code &ec, std::size_t bytes_transfered)
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

std::vector<uint8_t> &tcpUser::getInput()
{
    return (_input);
}


size_t &tcpUser::getSizeInput()
{
    return (_sizeInput);
}