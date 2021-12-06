#include "tcpUser.hpp"
#include <iostream>
#include <memory>


void rtype::tcpUser::start()
{}

void rtype::tcpUser::addToQueue(std::vector<uint8_t> message)
{
    _queue.push(message);
}

void rtype::tcpUser::read()
{
    _socket->async_read_some(asio::buffer(_data, sizeof(_data)), std::bind(&rtype::tcpUser::doRead, this, std::placeholders::_1, std::placeholders::_2));
}

void rtype::tcpUser::doRead(const std::error_code &ec, size_t bytes)
{
    std::cout << "doRead ec=" << ec << " nbBytes=" << bytes << std::endl;
    if (!ec)
    {
        for (int i = 0; i < bytes; i++) {
            uint8_t tmp = (uint8_t)_data[i];
            std::cout << "data[" << i << "] = " << (int)tmp << std::endl;
            _input->push_back(std::move(tmp));
        }
        _sizeInput += bytes;
        std::memset(_data, 0, bytes);
    }
    read();
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
    }
    write();
}

auto rtype::tcpUser::getInput()->std::vector<uint8_t>
{
    if (_input)
        return (*_input);
    else
        return std::vector<uint8_t>{};
}

auto rtype::tcpUser::clearInput() -> void
{
    _input->clear();
}

size_t &rtype::tcpUser::getSizeInput()
{
    return (_sizeInput);
}


void rtype::tcpUser::delInput(size_t length)
{
    _input->erase(_input->begin(), _input->begin() + length);
    _sizeInput -= length;
}