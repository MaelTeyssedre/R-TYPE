#include "tcpUser.hpp"
#include <iostream>
#include <memory>


void rtype::tcpUser::start()
{}

void rtype::tcpUser::addToQueue(std::vector<uint8_t> message)
{
    std::cout << "in addToQueue, value is: " << ((int)message[0]) << std::endl; 
    _queue.push(message);
}

void rtype::tcpUser::read()
{
    std::memset(_data, 0, sizeof(_data));
    _socket->async_read_some(asio::buffer(_data, 1), std::bind(&rtype::tcpUser::doRead, this, std::placeholders::_1, std::placeholders::_2));
    
    //for (auto i : _data)
  //  asio::async_read(*_socket, asio::buffer(_input), std::bind(&rtype::tcpUser::doRead, this, std::placeholders::_1, std::placeholders::_2));
}

void rtype::tcpUser::doRead(const std::error_code &ec, size_t bytes)
{
    if (!ec)
    { 
        uint8_t tmp = (uint8_t)_data[0];
        _input->push_back(std::move(tmp));
        std::cout << "input size : " << _input->size() << std::endl;
        _sizeInput += bytes;
        read();
        std::cout << (int)_input->back() << std::endl;
    }
}

void rtype::tcpUser::write()
{
    if (_queue.empty())
        return;
    asio::async_write(*_socket, asio::buffer(_queue.front(), _queue.front().size()), std::bind(&rtype::tcpUser::doWrite, this, std::placeholders::_1, std::placeholders::_2));
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
}

std::vector<uint8_t> *rtype::tcpUser::getInput()
{
    if (_input)
        return (_input);
    else
        return new std::vector<uint8_t>{};
}


size_t &rtype::tcpUser::getSizeInput()
{
    return (_sizeInput);
}
