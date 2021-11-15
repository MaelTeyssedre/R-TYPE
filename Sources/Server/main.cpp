#include <iostream>
#include "NetworkManager.hpp"
#include "tcpServer.hpp"

int main()
{
    asio::io_context context;
    Packet packet;
    std::vector<uint8_t> vec;
    std::string str = "Create ";
    vec.assign(str.begin(), str.end());
    packet.pack(vec);
    TCPServer server(context, 1342);
    std::cout << "BEFORE RUN" << std::endl;
    context.run();
    std::cout << "After run" << std::endl;
    while (1) {
      server.send(0, packet);
    }
    std::cout << "Exit main" << std::endl;

    return (0);
}
