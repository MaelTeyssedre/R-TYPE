/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

#include "UDPSocket.hpp"

UDPSocket::UDPSocket()
{
}

UDPSocket::~UDPSocket()
{
}

void UDPSocket::send(IPacket &data)
{}

void UDPSocket::send(std::vector<size_t>, IPacket &data)
{}

void UDPSocket::sendToAll(IPacket &data)
{}

IPacket &UDPSocket::receiver()
{}

void UDPSocket::start(std::uint16_t port)
{}

void UDPSocket::stop()
{}