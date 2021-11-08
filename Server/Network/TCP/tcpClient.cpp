/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** tcpClient
*/

#include "tcpClient.hpp"
#include "IPacket.hpp"

TCPClient::TCPClient()
{}

TCPClient::~TCPClient()
{}

void TCPClient::send(IPacket &data)
{}

IPacket &TCPClient::receive()
{}

void TCPClient::connect(std::string &ip, std::uint16_t port)
{}

void TCPClient::disconnect()
{}