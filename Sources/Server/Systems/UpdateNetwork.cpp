
#include "UpdateNetwork.hpp"
#include "Constants.hpp"

rtype::UpdateNetwork::UpdateNetwork(ITCPServer *server, IUDPSocket *socket)
    : _tcpServer(server), _socket(socket) {}

void rtype::UpdateNetwork::operator()(Registry &r, SparseArray<components::network_s> &networks)
{
    std::cout << "help" << std::endl;
    (void)r;
    (void)networks;
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
    std::cout << "receive opCode" << opCode << std::endl;
    switch (opCode)
    {
    case 5:
        if (network.value().request5.empty())
            network.value().request5.push_back(std::vector<uint8_t>());
        network.value().request5.back().push_back(opCode);
        network.value().request5.back().insert(network.value().request5.back().end(), packets.back()->unpack().at(0), packets.back()->unpack().at(5));
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
        if (network.value().request17.empty())
            network.value().request17.push_back(std::vector<uint8_t>());
        network.value().request17.back().push_back(opCode);
        network.value().request17.back().insert(network.value().request17.back().end(), packets.back()->unpack().at(0), packets.back()->unpack().at(8));
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
