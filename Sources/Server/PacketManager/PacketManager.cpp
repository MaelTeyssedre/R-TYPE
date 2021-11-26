#include "PacketManager.hpp"

PacketManager::PacketManager(std::shared_ptr<Buffer> bufferIn, std::shared_ptr<Buffer> bufferOut)
{
    _bufferIn = bufferIn;
    _bufferOut = bufferOut;
}

void PacketManager::createRoom(Packet packet)
{
    std::vector<uint8_t> vec;
    std::string str = "Create ";
    str.append(std::to_string(packet.getId()));
    str.append(";");
    vec.assign(str.begin(), str.end());
    _bufferOut->putInBuffer(vec.size(), vec);
}

void PacketManager::joinRoom(Packet packet)
{
    std::vector<uint8_t> vec;
    std::string str = "Join ";
    str.append(std::to_string(packet.getId()));
    str.append(";");
    vec.assign(str.begin(), str.end());
    _bufferOut->putInBuffer(vec.size(), vec);
}

void PacketManager::sendToClient(PlayerData &player, std::vector<uint8_t> request) {
    player._mutexOut->lock();
    player._bufferOut->putInBuffer(request.size(), request);
    player._mutexOut->unlock();
}

void PacketManager::managePacket(Packet packet)
{
    for (size_t i = 0; i < (*_roomList).size(); i++)
        for (size_t j = 0; j < (*_roomList)[i].size(); j++)
            if ((*_roomList)[i][j].getId() == packet.getId())
            {
                sendToClient((*_roomList)[i][j], packet.getData());
                return;
            }
    if (packet.getData().at(0) == 15)
        createRoom(packet);
    else if (packet.getData().at(0) == 16)
        joinRoom(packet);
    else
        std::cerr << "Packet received from " << packet.getId() << " is undefined" << std::endl;
}


void PacketManager::setBuffer(std::shared_ptr<Buffer> buffer)
{
    (void)buffer;
}

std::vector<Packet> PacketManager::getRequests()
{
    return _packets;
}