/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPServer
*/

#include "TCPServer.hpp"
#include <asio.hpp>

TCPServer::TCPServer()
{}

void TCPServer::accept()
{
    
}

void TCPServer::send(IPacket &data)
{}

void TCPServer::send(std::vector<size_t> target, IPacket &data)
{
}

void TCPServer::sendToAll(IPacket &data)
{}

void TCPServer::doWrite()
{}

IPacket &receive()
{}

void TCPServer::doRead()
{} 

void TCPServer::start()
{}

void TCPServer::stop()
{}

void TCPServer::eject(size_t client)
{}