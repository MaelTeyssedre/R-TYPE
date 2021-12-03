#include "PacketManager.hpp"

rtype::PacketManager::PacketManager(std::shared_ptr<Buffer> bufferIn, std::shared_ptr<Buffer> bufferOut)
    : _packets(new std::queue<IPacket *>), _packetsOut(new std::vector<IPacket *>), _roomList(new std::vector<std::vector<rtype::PlayerData>>{})
{
    _bufferIn = bufferIn;
    _bufferOut = bufferOut;
}

void rtype::PacketManager::createRoom(IPacket *packet)
{
    std::cout << "In create room" << std::endl;
    std::vector<uint8_t> vec;
    std::string str = "Create ";
    str.append(std::to_string(packet->getId()));
    str.append(";");
    vec.assign(str.begin(), str.end());
    _bufferOut->putInBuffer(vec.size(), vec);
}

void rtype::PacketManager::joinRoom(IPacket *packet)
{
    std::vector<uint8_t> vec;
    std::string str = "Join ";
    str.append(std::to_string(packet->getId()));
    str.append(";");
    vec.assign(str.begin(), str.end());
    _bufferOut->putInBuffer(vec.size(), vec);
}

void rtype::PacketManager::sendToClient(rtype::PlayerData &player, std::vector<uint8_t> request)
{
    player._mutexOut->lock();
    player._bufferOut->putInBuffer(request.size(), request);
    player._mutexOut->unlock();
}

void rtype::PacketManager::managePacket(IPacket *packet)
{
    for (size_t i = 0; i < (*_roomList).size(); i++)
        for (size_t j = 0; j < (*_roomList)[i].size(); j++)
            if ((*_roomList)[i][j].getId() == packet->getId())
            {
                sendToClient((*_roomList)[i][j], packet->unpack());
                return;
            }
    if (packet)
    {
        auto tmp = packet->unpack();
        if (!tmp.empty())
        {
            if (tmp.at(0) == 18)
            {
                std::cout << "getted request 18" << std::endl;
                createRoom(packet);
            }
            else if (tmp.at(0) == 16)
            {
                std::cout << "getted request 18 but not 18" << std::endl;
                joinRoom(packet);
            }
            else
            {
                std::cerr << "Packet received from " << packet->getId() << " is undefined" << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "Packet null" << std::endl;
    }
}

auto rtype::PacketManager::setBufferI(std::queue<IPacket *> *buffer) -> void
{
    for (; buffer && !buffer->empty();)
    {
        _packets->push(buffer->front());
        buffer->pop();
    }
}

auto rtype::PacketManager::getRequests() -> std::queue<IPacket *> *
{
    return _packets;
}

auto rtype::PacketManager::getRequestsToSend() -> std::vector<IPacket *>
{
    if (!_packetsOut)
        return std::vector<IPacket *>{};
    return *_packetsOut;
}