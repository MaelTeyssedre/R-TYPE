#include <iostream>
#include "NetworkManager.hpp"
#include "RoomManager.hpp"
#include "PacketManager.hpp"
#include "Constants.hpp"
#include <csignal>

static bool status = true;

void signalHandler(int signum)
{
    (void)signum;
    status = false;
}

int main(int ac, char **av)
{
    (void)ac;
    std::shared_ptr<std::vector<std::vector<rtype::PlayerData>>> roomList;
    std::shared_ptr<Buffer> bufferIn{new Buffer(BUF_SIZE)};
    std::shared_ptr<Buffer> bufferOut{new Buffer(BUF_SIZE)};
    INetworkManager *netManager = new rtype::NetworkManager();
    rtype::RoomManager roomManager(roomList, bufferIn, bufferOut);
    rtype::PacketManager packetManager(bufferOut, bufferIn);
    ITCPServer *server = netManager->createTCPServer(std::stoi(av[1]));
    netManager->start();
    signal(SIGINT, signalHandler);
    while (status)
    {
        server->receive();
        std::queue<IPacket *> * ptr = nullptr;
        ptr = server->getBuffer();
        std::cout << "après get buf" << std::endl;
        packetManager.setBufferI(ptr);
        std::queue<IPacket *> *tmp {packetManager.getRequests()};
        if (((tmp) ? (!(tmp->empty()) ? true : false) : false)) {
            packetManager.managePacket(tmp->front());
        }
        auto vector = packetManager.getRequestsToSend();
        if (!vector.empty())
          for (auto i : vector)
            server->send(i);
        roomManager.manageRoom();
        std::this_thread::sleep_for(std::chrono::nanoseconds(1000000));
    }
}
