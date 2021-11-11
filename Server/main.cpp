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
      std::shared_ptr<std::vector<uint8_t>> vec;
      std::string str = "hello from server";

    //  vec.assign(str.begin(), str.end());
     // addToQueue(vec);
     // packet.unpack(vec);
     if (server->getUsers().size() == 1)
        server->send(1, packet);
      std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    }
    return (0);
}