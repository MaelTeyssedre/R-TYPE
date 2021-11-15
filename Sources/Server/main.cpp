<<<<<<< Updated upstream
void main() {}
=======
#include <iostream>
#include "NetworkManager.hpp"
#include "tcpServer.hpp"

int main()
{
 //   NetworkManager net;
  //  TCPServer *server;
  //  Packet packet;

  /*  server = net.createTCPServer(1342);
    net.start();
    while (1) {
      server->startAccept();
      std::shared_ptr<std::vector<uint8_t>> vec;
      std::string str = "hello from server";

      if (server->getUsers().size() == 1) {
        server->send(1, packet);
        std::cout << "help" << std::endl;
      }
      std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    }*/
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
>>>>>>> Stashed changes
