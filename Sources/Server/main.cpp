#include <iostream>
#include "NetworkManager.hpp"
#include "RoomManager.hpp"
#include "PacketManager.hpp"
#include "Constants.hpp"

int main(int ac, char **av)
{
    (void)ac;
    std::shared_ptr<std::vector<std::vector<PlayerData>>> roomList;
    std::shared_ptr<Buffer> bufferIn {new Buffer(BUF_SIZE)};
    std::shared_ptr<Buffer> bufferOut {new Buffer(BUF_SIZE)};
    INetworkManager *netManager = new NetworkManager();
    RoomManager roomManager(roomList, bufferIn, bufferOut);
    PacketManager packetManager(bufferOut, bufferIn);
    ITCPServer *server = netManager->createTCPServer(std::stoi(av[1]));
    netManager->start();
    for (;;) {
        server->receive();
        for (auto i : packetManager.getRequests())
            packetManager.managePacket(i);
        roomManager.manageRoom();
    }
}
