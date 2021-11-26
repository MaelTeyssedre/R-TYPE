
#include "UpdateNetwork.hpp"
#include "Constants.hpp"
#include "tamereuh.hpp"

UpdateNetwork::UpdateNetwork(ITCPClient *client, IUDPSocket *socket)
    : _tcpClient(client), _socket(socket) {}

void UpdateNetwork::operator()(Registry &r, SparseArray<components::network_s> &networks)
{
    std::cout << "le netoueurkeuh" << std::endl;
    (void)r;

  //  for (auto &&[network] : Zipper(networks))
   // {
        std::optional<components::network_s> &network = networks[rtype::constants::RESERVED_ID::NETWORK_UPDATE];
        std::uint8_t opCode;
        std::vector<uint8_t> reply;
        std::cout << "le ifeuh" << std::endl;
        if (!network)
        {
            return;
        }
        // for (auto &&[network] : Zipper(networks)) {
        std::cout << "la boucleuh" << std::endl;
        if (!_clienteuh)
            std::cout << "Pas de tehcpClienteuh" << std::endl;
        if (_clienteuh)
            std::cout << "tehcpClienteuh" << std::endl;
        std::cout << "receiveuh udp" << std::endl;
        Packet packet;

        _socketeuh->send(packet);
        std::cout << "receiveuh tcp" << std::endl;
        _clienteuh->receive();
        std::shared_ptr<Buffer> buffer{_clienteuh->getBuffer()};
        buffer->readFromBuffer(1, &opCode);
        std::cout << "switcheuh" << std::endl;
        switch (opCode)
        {
        case 1:
            buffer->readFromBuffer(15, reply);
            if (network.value().request1.empty())
                network.value().request1.push_back(std::vector<uint8_t>());
            network.value().request1.back().push_back(opCode);
            network.value().request1.back().insert(network.value().request1.back().end(), reply.begin(), reply.end());
            break;
        case 2:
            buffer->readFromBuffer(13, reply);
            if (network.value().request2.empty())
                network.value().request2.push_back(std::vector<uint8_t>());
            network.value().request2.back().push_back(opCode);
            network.value().request2.back().insert(network.value().request2.back().end(), reply.begin(), reply.end());
            break;
        case 3:
            buffer->readFromBuffer(12, reply);
            if (network.value().request3.empty())
                network.value().request3.push_back(std::vector<uint8_t>());
            network.value().request3.back().push_back(opCode);
            network.value().request3.back().insert(network.value().request3.back().end(), reply.begin(), reply.end());
            break;
        case 4:
            if (network.value().request4.empty())
                network.value().request4.push_back(std::vector<uint8_t>());
            network.value().request4.back().push_back(opCode);
            break;
        case 7:
            buffer->readFromBuffer(8, reply);
            if (network.value().request7.empty())
                network.value().request7.push_back(std::vector<uint8_t>());
            network.value().request7.back().push_back(opCode);
            network.value().request7.back().insert(network.value().request7.back().end(), reply.begin(), reply.end());
            break;
        case 8:
            buffer->readFromBuffer(17, reply);
            if (network.value().request8.empty())
                network.value().request8.push_back(std::vector<uint8_t>());
            network.value().request8.back().push_back(opCode);
            network.value().request8.back().insert(network.value().request8.back().end(), reply.begin(), reply.end());
            break;
        case 9:
            buffer->readFromBuffer(4, reply);
            if (network.value().request9.empty())
                network.value().request9.push_back(std::vector<uint8_t>());
            network.value().request9.back().push_back(opCode);
            network.value().request9.back().insert(network.value().request9.back().end(), reply.begin(), reply.end());
            break;
        case 10:
            if (network.value().request10.empty())
                network.value().request10.push_back(std::vector<uint8_t>());
            network.value().request10.back().push_back(opCode);
            break;
        case 11:
            if (network.value().request11.empty())
                network.value().request11.push_back(std::vector<uint8_t>());
            network.value().request11.back().push_back(opCode);
            break;
        case 12:
            buffer->readFromBuffer(8, reply);
            if (network.value().request12.empty())
                network.value().request12.push_back(std::vector<uint8_t>());
            network.value().request12.back().push_back(opCode);
            network.value().request12.back().insert(network.value().request12.back().end(), reply.begin(), reply.end());
            break;
        case 13:
            buffer->readFromBuffer(1, reply);
            if (network.value().request13.empty())
                network.value().request13.push_back(std::vector<uint8_t>());
            network.value().request13.back().push_back(opCode);
            network.value().request13.back().insert(network.value().request13.back().end(), reply.begin(), reply.end());
            break;
        case 14:
            buffer->readFromBuffer(1, reply);
            if (network.value().request14.empty())
                network.value().request14.push_back(std::vector<uint8_t>());
            network.value().request14.back().push_back(opCode);
            network.value().request14.back().insert(network.value().request14.back().end(), reply.begin(), reply.end());
            break;
        case 15:
            if (network.value().request15.empty())
                network.value().request15.push_back(std::vector<uint8_t>());
            network.value().request15.back().push_back(opCode);
            break;
        default:
            break;
            //  }
        }
    //}
        std::cout << "end networkeuh" << std::endl;
}