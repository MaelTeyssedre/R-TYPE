#include "NetworkManager.hpp"
#include <sstream>
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "USAGE:" << std::endl << "\twindows: .\\rtype_server.exe [port]" << std::endl << "\tlinux: ./rtype_server [port]" << std::endl;
        return 1;
    }
    int port;
    std::stringstream ss;
    ss << av[1];
    ss >> port;
    NetworkManager netManager;
    ITCPServer *server = netManager.createTCPServer(port);
    netManager.deleteTCPServer(server);
    return 0;
}