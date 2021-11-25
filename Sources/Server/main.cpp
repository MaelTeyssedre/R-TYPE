#include <iostream>
#include "NetworkManager.hpp"
#include "RtypeServer.hpp"
#include "tcpServer.hpp"

int main(int ac, char **av)
{
    RtypeServer server(std::stoi(av[1]));
}