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

asio::ip::tcp::socket tcpUser::getSocket()
{
   // return (_socket);
}

void tcpUser::start()
{
    std::cout << "hello" << std::endl;
    asio::async_write(_socket, asio::buffer("test"), std::bind(&tcpUser::handleWrite, this));
}

void tcpUser::handleWrite()
{
    std::cout << "write somethinf" << std::endl;
}