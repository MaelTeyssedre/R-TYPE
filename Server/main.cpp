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
   // NetworkManager net(1342);


   // net.createTCPServer();

    asio::io_context context;
    TCPServer server(context);
    server.accept();
   // server.start();
    context.run();
    return (0);
}