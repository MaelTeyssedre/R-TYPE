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
      std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    }
    return (0);
}