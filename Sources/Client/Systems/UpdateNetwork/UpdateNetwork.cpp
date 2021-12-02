
#include "UpdateNetwork.hpp"
#include "Constants.hpp"

rtype::UpdateNetwork::UpdateNetwork(ITCPClient *client, IUDPSocket *socket)
    : _tcpClient(client), _socket(socket) {}

void rtype::UpdateNetwork::operator()(Registry &r, SparseArray<components::network_s> &networks)
{
    static int t = 0;
    (void)r;
    for (auto &&[network] : Zipper(networks)) {
        std::uint8_t opCode = 0;
        std::vector<uint8_t> reply;
        _tcpClient->receive();
        std::shared_ptr<Buffer> buffer{_tcpClient->getBuffer()};
        if (!t) {
            buffer->cleanBuffer();
            t++;
        }
        buffer->readFromBuffer(1, &opCode);
        switch (opCode)
        {
        case 1:
            std::cout << "requete 1 recue" << std::endl;
            buffer->readFromBuffer(15, reply);
            network.request1.back().push_back(opCode);
            network.request1.back().insert(network.request1.back().end(), reply.begin(), reply.end());
            break;
        case 2:
            std::cout << "requete 2 recue" << std::endl;
            buffer->readFromBuffer(13, reply);
            network.request2.back().push_back(opCode);
            network.request2.back().insert(network.request2.back().end(), reply.begin(), reply.end());
            break;
        case 3:
            std::cout << "requete 3 recue" << std::endl;
            network.request3.clear();
            std::cout << "size requests 3: " << network.request3.size() << std::endl; 
            buffer->readFromBuffer(12, reply);
            network.request3.back().push_back(opCode);
            network.request3.back().insert(network.request3.back().end(), reply.begin(), reply.end());
            break;
        case 4:
            std::cout << "requete 4 recue" << std::endl;
            network.request4.back().push_back(opCode);
            break;
        case 7:
            std::cout << "requete 7 recue" << std::endl;
            buffer->readFromBuffer(8, reply);
            network.request7.back().push_back(opCode);
            network.request7.back().insert(network.request7.back().end(), reply.begin(), reply.end());
            break;
        case 8:
            std::cout << "requete 8 recue" << std::endl;
            buffer->readFromBuffer(17, reply);
            network.request8.back().push_back(opCode);
            network.request8.back().insert(network.request8.back().end(), reply.begin(), reply.end());
            break;
        case 9:
            std::cout << "requete 9 recue" << std::endl;
            buffer->readFromBuffer(4, reply);
            network.request9.back().push_back(opCode);
            network.request9.back().insert(network.request9.back().end(), reply.begin(), reply.end());
            break;
        case 10:
            std::cout << "requete 10 recue" << std::endl;
            network.request10.back().push_back(opCode);
            break;
        case 11:
            std::cout << "requete 11 recue" << std::endl;
            network.request11.back().push_back(opCode);
            break;
        case 12:
            std::cout << "requete 12 recue" << std::endl;
            buffer->readFromBuffer(8, reply);
            network.request12.back().push_back(opCode);
            network.request12.back().insert(network.request12.back().end(), reply.begin(), reply.end());
            break;
        case 13:
            std::cout << "requete 13 recue" << std::endl;
            buffer->readFromBuffer(1, reply);
            network.request13.back().push_back(opCode);
            network.request13.back().insert(network.request13.back().end(), reply.begin(), reply.end());
            break;
        case 14:
            std::cout << "requete 14 recue" << std::endl;
            buffer->readFromBuffer(1, reply);
            network.request14.back().push_back(opCode);
            network.request14.back().insert(network.request14.back().end(), reply.begin(), reply.end());
            break;
        case 15:
            std::cout << "requete 15 recue" << std::endl;
            network.request15.back().push_back(opCode);
            break;
        case 22:
            std::cout << "requete 22 recue" << std::endl;
            buffer->readFromBuffer(1, reply);
            network.request22.back().push_back(opCode);
            network.request22.back().insert(network.request22.back().end(), reply.begin(), reply.end());
            break;
        default:
            break;
        }
        if (!(network.sendRequest.empty())) {
            IPacket* packet = new Packet();
            packet->pack(network.sendRequest.front());
            _tcpClient->send(*packet);
            network.sendRequest.erase(network.sendRequest.begin());
        }
    }
}
