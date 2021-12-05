#include <iostream>
#include <csignal>
#include "RoomManager.hpp"
#include "PacketManager.hpp"
#include "NetworkManager.hpp"

static bool status = true;

void signalHandler(int signum)
{
    (void)signum;
    status = false;
}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int main(int ac, char **av)
{
    if (ac != 2 || !is_number(av[1])) {
        std::cout << HELPER << std::endl;
        return 0;
    }
    (void)ac;
    std::shared_ptr<std::vector<std::pair<std::vector<rtype::PlayerData>, size_t>>> roomList {new std::vector<std::pair<std::vector<rtype::PlayerData>, size_t>>()};
    std::shared_ptr<std::vector<size_t>> idCreator{ new std::vector<size_t> {} };
    std::shared_ptr<std::vector<std::pair<size_t, size_t>>> idJoiner{ new std::vector<std::pair<size_t, size_t>> {} };
    INetworkManager *netManager = new rtype::NetworkManager();
    rtype::RoomManager roomManager(roomList, idCreator, idJoiner);
    rtype::PacketManager packetManager(idCreator, idJoiner, roomList);
    ITCPServer *server = netManager->createTCPServer(std::stoi(av[1]));
    netManager->start();
    signal(SIGINT, signalHandler);
    while (status)
    {
        server->receive();
        std::queue<IPacket *> *ptr = nullptr;
        packetManager.setBufferI(server->getBuffer());
        packetManager.managePacket();
        auto &toSend = packetManager.getRequestsToSend();
        for (auto i : toSend) {
            server->send(i);
        }
        toSend.clear();
        roomManager.manageRoom();
        packetManager.manageResponse();
        std::this_thread::sleep_for(std::chrono::nanoseconds(1000000));
    }
}
