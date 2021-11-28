#include <iostream>
#include "NetworkManager.hpp"
#include "RoomManager.hpp"
#include "PacketManager.hpp"
#include "Constants.hpp"

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
    for (;;)
    {
        server->receive();
        for (auto i : packetManager.getRequests())
            packetManager.managePacket(i);
        roomManager.manageRoom();
    }
}
