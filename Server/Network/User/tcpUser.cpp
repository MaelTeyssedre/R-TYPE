/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** tcpUser
*/

#include "tcpUser.hpp"

tcpUser::tcpUser()
{}

tcpUser::~tcpUser()
{}

asio::ip::tcp::socket tcpUser::getSocket()
{
    return (_socket);
}