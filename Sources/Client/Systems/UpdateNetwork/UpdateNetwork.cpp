
#include "UpdateNetwork.hpp"
#include "Constants.hpp"

rtype::UpdateNetwork::UpdateNetwork(ITCPClient *client, IUDPSocket *socket)
    : _tcpClient(client), _socket(socket) {}

void rtype::UpdateNetwork::operator()(Registry &r, SparseArray<components::network_s> &networks)
{
    (void)r;
    for (auto &&[network] : Zipper(networks)) {
        std::uint8_t opCode = 0;
        std::vector<uint8_t> reply;
        _tcpClient->receive();
        std::shared_ptr<Buffer> buffer{_tcpClient->getBuffer()};
        buffer->cleanBuffer();
        buffer->readFromBuffer(1, &opCode);
        switch (opCode)
        {
        case 1:
            std::cout << "requete 1 recue" << std::endl;
            buffer->readFromBuffer(15, reply);
            if (network.request1.empty())
                network.request1.push_back(std::vector<uint8_t>());
            network.request1.back().push_back(opCode);
            network.request1.back().insert(network.request1.back().end(), reply.begin(), reply.end());
            break;
        case 2:
            std::cout << "requete 2 recue" << std::endl;
            buffer->readFromBuffer(13, reply);
            if (network.request2.empty())
                network.request2.push_back(std::vector<uint8_t>());
            network.request2.back().push_back(opCode);
            network.request2.back().insert(network.request2.back().end(), reply.begin(), reply.end());
            break;
        case 3:
            std::cout << "requete 3 recue" << std::endl;
            network.request3.clear();
            std::cout << "size requests 3: " << network.request3.size() << std::endl; 
            buffer->readFromBuffer(12, reply);
            if (network.request3.empty())
                network.request3.push_back(std::vector<uint8_t>());
            network.request3.back().push_back(opCode);
            network.request3.back().insert(network.request3.back().end(), reply.begin(), reply.end());
            break;
        case 4:
            std::cout << "requete 4 recue" << std::endl;
            if (network.request4.empty())
                network.request4.push_back(std::vector<uint8_t>());
            network.request4.back().push_back(opCode);
            break;
        case 7:
            std::cout << "requete 7 recue" << std::endl;
            buffer->readFromBuffer(8, reply);
            if (network.request7.empty())
                network.request7.push_back(std::vector<uint8_t>());
            network.request7.back().push_back(opCode);
            network.request7.back().insert(network.request7.back().end(), reply.begin(), reply.end());
            break;
        case 8:
            std::cout << "requete 8 recue" << std::endl;
            buffer->readFromBuffer(17, reply);
            if (network.request8.empty())
                network.request8.push_back(std::vector<uint8_t>());
            network.request8.back().push_back(opCode);
            network.request8.back().insert(network.request8.back().end(), reply.begin(), reply.end());
            break;
        case 9:
            std::cout << "requete 9 recue" << std::endl;
            buffer->readFromBuffer(4, reply);
            if (network.request9.empty())
                network.request9.push_back(std::vector<uint8_t>());
            network.request9.back().push_back(opCode);
            network.request9.back().insert(network.request9.back().end(), reply.begin(), reply.end());
            break;
        case 10:
            std::cout << "requete 10 recue" << std::endl;
            if (network.request10.empty())
                network.request10.push_back(std::vector<uint8_t>());
            network.request10.back().push_back(opCode);
            break;
        case 11:
            std::cout << "requete 11 recue" << std::endl;
            if (network.request11.empty())
                network.request11.push_back(std::vector<uint8_t>());
            network.request11.back().push_back(opCode);
            break;
        case 12:
            std::cout << "requete 12 recue" << std::endl;
            buffer->readFromBuffer(8, reply);
            if (network.request12.empty())
                network.request12.push_back(std::vector<uint8_t>());
            network.request12.back().push_back(opCode);
            network.request12.back().insert(network.request12.back().end(), reply.begin(), reply.end());
            break;
        case 13:
            std::cout << "requete 13 recue" << std::endl;
            buffer->readFromBuffer(1, reply);
            if (network.request13.empty())
                network.request13.push_back(std::vector<uint8_t>());
            network.request13.back().push_back(opCode);
            network.request13.back().insert(network.request13.back().end(), reply.begin(), reply.end());
            break;
        case 14:
            std::cout << "requete 14 recue" << std::endl;
            buffer->readFromBuffer(1, reply);
            if (network.request14.empty())
                network.request14.push_back(std::vector<uint8_t>());
            network.request14.back().push_back(opCode);
            network.request14.back().insert(network.request14.back().end(), reply.begin(), reply.end());
            break;
        case 15:
            std::cout << "requete 15 recue" << std::endl;
            if (network.request15.empty())
                network.request15.push_back(std::vector<uint8_t>());
            network.request15.back().push_back(opCode);
            break;
        case 22:
            std::cout << "requete 22 recue" << std::endl;
            buffer->readFromBuffer(1, reply);
            if (network.request22.empty())
                network.request22.push_back(std::vector<uint8_t>());
            network.request22.back().push_back(opCode);
            network.request22.back().insert(network.request22.back().end(), reply.begin(), reply.end());
            break;
        default:
            std::cout << "unknow request" << std::endl;
            break;
        }
        if (!network.sendRequest.empty()) {
            std::cout << "send request" << std::endl;
            IPacket *packet = new Packet();
            (*packet).pack(network.sendRequest.front());
            _tcpClient->send(*packet);
        }
    }
}
