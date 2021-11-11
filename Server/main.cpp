/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** main
*/

#include <iostream>
#include "NetworkManager.hpp"
#include "tcpServer.hpp"

int main()
{
    NetworkManager net;
    TCPServer *server;
    Packet packet;

    server = net.createTCPServer();
    net.start();
    while (1) {
    server->startAccept();
    if (server->getUsers().size() != 0) {
        //server->send(1, packet);
    }
    }


    return (0);
}