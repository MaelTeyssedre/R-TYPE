
#include "UpdateNetwork.hpp"
#include "Constants.hpp"

rtype::UpdateNetwork::UpdateNetwork(ITCPClient *client, IUDPSocket *socket)
    : _tcpClient(client), _socket(socket) {}

void rtype::UpdateNetwork::operator()(Registry &r, SparseArray<components::network_s> &networks)
{
    (void)r;
    std::optional<components::network_s> &network = networks[rtype::constants::RESERVED_ID::NETWORK_UPDATE];
    std::uint8_t opCode = 0;
    std::vector<uint8_t> reply;
    if (!network)
    {
        return;
    }
    _tcpClient->receive();
    std::shared_ptr<Buffer> buffer{_tcpClient->getBuffer()};
    buffer->cleanBuffer();
    buffer->readFromBuffer(1, &opCode);
    switch (opCode)
    {
    case 1:
        std::cout << "requete 1 recue" << std::endl;
        buffer->readFromBuffer(15, reply);
        if (network.value().request1.empty())
            network.value().request1.push_back(std::vector<uint8_t>());
        network.value().request1.back().push_back(opCode);
        network.value().request1.back().insert(network.value().request1.back().end(), reply.begin(), reply.end());
        break;
    case 2:
        std::cout << "requete 2 recue" << std::endl;
        buffer->readFromBuffer(13, reply);
        if (network.value().request2.empty())
            network.value().request2.push_back(std::vector<uint8_t>());
        network.value().request2.back().push_back(opCode);
        network.value().request2.back().insert(network.value().request2.back().end(), reply.begin(), reply.end());
        break;
    case 3:
        std::cout << "requete 3 recue" << std::endl;
        network.value().request3.clear();
        std::cout << "size requests 3: " << network.value().request3.size() << std::endl; 
        buffer->readFromBuffer(12, reply);
        if (network.value().request3.empty())
            network.value().request3.push_back(std::vector<uint8_t>());
        network.value().request3.back().push_back(opCode);
        network.value().request3.back().insert(network.value().request3.back().end(), reply.begin(), reply.end());
        break;
    case 4:
        std::cout << "requete 4 recue" << std::endl;
        if (network.value().request4.empty())
            network.value().request4.push_back(std::vector<uint8_t>());
        network.value().request4.back().push_back(opCode);
        break;
    case 7:
        std::cout << "requete 7 recue" << std::endl;
        buffer->readFromBuffer(8, reply);
        if (network.value().request7.empty())
            network.value().request7.push_back(std::vector<uint8_t>());
        network.value().request7.back().push_back(opCode);
        network.value().request7.back().insert(network.value().request7.back().end(), reply.begin(), reply.end());
        break;
    case 8:
        std::cout << "requete 8 recue" << std::endl;
        buffer->readFromBuffer(17, reply);
        if (network.value().request8.empty())
            network.value().request8.push_back(std::vector<uint8_t>());
        network.value().request8.back().push_back(opCode);
        network.value().request8.back().insert(network.value().request8.back().end(), reply.begin(), reply.end());
        break;
    case 9:
        std::cout << "requete 9 recue" << std::endl;
        buffer->readFromBuffer(4, reply);
        if (network.value().request9.empty())
            network.value().request9.push_back(std::vector<uint8_t>());
        network.value().request9.back().push_back(opCode);
        network.value().request9.back().insert(network.value().request9.back().end(), reply.begin(), reply.end());
        break;
    case 10:
        std::cout << "requete 10 recue" << std::endl;
        if (network.value().request10.empty())
            network.value().request10.push_back(std::vector<uint8_t>());
        network.value().request10.back().push_back(opCode);
        break;
    case 11:
        std::cout << "requete 11 recue" << std::endl;
        if (network.value().request11.empty())
            network.value().request11.push_back(std::vector<uint8_t>());
        network.value().request11.back().push_back(opCode);
        break;
    case 12:
        std::cout << "requete 12 recue" << std::endl;
        buffer->readFromBuffer(8, reply);
        if (network.value().request12.empty())
            network.value().request12.push_back(std::vector<uint8_t>());
        network.value().request12.back().push_back(opCode);
        network.value().request12.back().insert(network.value().request12.back().end(), reply.begin(), reply.end());
        break;
    case 13:
        std::cout << "requete 13 recue" << std::endl;
        buffer->readFromBuffer(1, reply);
        if (network.value().request13.empty())
            network.value().request13.push_back(std::vector<uint8_t>());
        network.value().request13.back().push_back(opCode);
        network.value().request13.back().insert(network.value().request13.back().end(), reply.begin(), reply.end());
        break;
    case 14:
        std::cout << "requete 14 recue" << std::endl;
        buffer->readFromBuffer(1, reply);
        if (network.value().request14.empty())
            network.value().request14.push_back(std::vector<uint8_t>());
        network.value().request14.back().push_back(opCode);
        network.value().request14.back().insert(network.value().request14.back().end(), reply.begin(), reply.end());
        break;
    case 15:
        std::cout << "requete 15 recue" << std::endl;
        if (network.value().request15.empty())
            network.value().request15.push_back(std::vector<uint8_t>());
        network.value().request15.back().push_back(opCode);
        break;
    default:
        break;
    }
    if (!network.value().sendRequest.empty()) {
        IPacket *packet = new rtype::Packet;
        (*packet).pack(network.value().sendRequest.front());
        _tcpClient->send(*packet);
    }
}
