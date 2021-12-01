
#include "UpdateNetwork.hpp"
#include "Constants.hpp"

rtype::UpdateNetwork::UpdateNetwork(ITCPServer *server, IUDPSocket *socket)
    : _tcpServer(server), _socket(socket) {}

void rtype::UpdateNetwork::operator()(Registry &r, SparseArray<components::network_s> &networks)
{
    (void)r;
    (void)networks;
    // ! Commented while debuging
    (void)r;
    std::optional<components::network_s> &network = networks[rtype::constants::RESERVED_ID::NETWORK_UPDATE];
    std::uint8_t opCode = 0;
    std::vector<uint8_t> reply;
    if (!network)
        return;
    _tcpServer->receive();
    std::queue<IPacket *> packets = _tcpServer->getBuffer();
    _tcpServer->getBuffer().pop();
    opCode = packets.back()->unpack().at(0);
   // buffer->readFromBuffer(1, &opCode);
    switch (opCode)
    {
    case 5:
       // buffer->readFromBuffer(5, reply);
        if (network.value().request5.empty())
            network.value().request5.push_back(std::vector<uint8_t>());
        network.value().request5.back().push_back(opCode);
        network.value().request5.back().insert(network.value().request5.back().end(), reply.begin(), reply.end());
        break;
    case 6:
        if (network.value().request6.empty())
            network.value().request6.push_back(std::vector<uint8_t>());
        network.value().request6.back().push_back(opCode);
        break;
    case 16:
        if (network.value().request16.empty())
            network.value().request16.push_back(std::vector<uint8_t>());
        network.value().request16.back().push_back(opCode);
        break;
    case 17:
      //  buffer->readFromBuffer(8, reply);
        if (network.value().request17.empty())
            network.value().request17.push_back(std::vector<uint8_t>());
        network.value().request17.back().push_back(opCode);
        network.value().request17.back().insert(network.value().request17.back().end(), reply.begin(), reply.end());
        break;
    case 18:
        if (network.value().request18.empty())
            network.value().request18.push_back(std::vector<uint8_t>());
        network.value().request18.back().push_back(opCode);
        break;
    case 19:
        if (network.value().request19.empty())
            network.value().request19.push_back(std::vector<uint8_t>());
        network.value().request19.back().push_back(opCode);
        break;
    default:
        break;
    }
}
