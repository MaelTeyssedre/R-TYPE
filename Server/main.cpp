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
    UDPSocket *server;

    std::cout << "1" << std::endl;
    server = net.createSocketUDP(1342);
    net.start();
    while (1) {
     // server->startAccept();
      server->receive();
      std::shared_ptr<std::vector<uint8_t>> vec;
      std::string str = "hello from server";

    //  vec.assign(str.begin(), str.end());
     // addToQueue(vec);
     // packet.unpack(vec);
  
      Packet packet;
      server->send(packet);
      std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    }
    return (0);
}