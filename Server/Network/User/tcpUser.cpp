/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** tcpUser
*/

#include "tcpUser.hpp"

tcpUser::tcpUser()
{
}

std::shared_ptr<asio::ip::tcp::socket> tcpUser::getSocket()
{
    return (_socket);
}