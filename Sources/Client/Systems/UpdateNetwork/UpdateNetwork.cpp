
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
            buffer->readFromBuffer(15, reply);
            network.request1.back().push_back(opCode);
            network.request1.back().insert(network.request1.back().end(), reply.begin(), reply.end());
            break;
        case 2:
            buffer->readFromBuffer(13, reply);
            network.request2.back().push_back(opCode);
            network.request2.back().insert(network.request2.back().end(), reply.begin(), reply.end());
            break;
        case 3:
            network.request3.clear();
            buffer->readFromBuffer(12, reply);
            network.request3.back().push_back(opCode);
            network.request3.back().insert(network.request3.back().end(), reply.begin(), reply.end());
            break;
        case 4:
            network.request4.back().push_back(opCode);
            break;
        case 7:
            buffer->readFromBuffer(8, reply);
            network.request7.back().push_back(opCode);
            network.request7.back().insert(network.request7.back().end(), reply.begin(), reply.end());
            break;
        case 8:
            buffer->readFromBuffer(17, reply);
            network.request8.back().push_back(opCode);
            network.request8.back().insert(network.request8.back().end(), reply.begin(), reply.end());
            break;
        case 9:
            buffer->readFromBuffer(4, reply);
            network.request9.back().push_back(opCode);
            network.request9.back().insert(network.request9.back().end(), reply.begin(), reply.end());
            break;
        case 10:
            network.request10.back().push_back(opCode);
            break;
        case 11:
            network.request11.back().push_back(opCode);
            break;
        case 12:
            buffer->readFromBuffer(8, reply);
            network.request12.back().push_back(opCode);
            network.request12.back().insert(network.request12.back().end(), reply.begin(), reply.end());
            break;
        case 13:
            buffer->readFromBuffer(1, reply);
            network.request13.back().push_back(opCode);
            network.request13.back().insert(network.request13.back().end(), reply.begin(), reply.end());
            break;
        case 14:
            buffer->readFromBuffer(1, reply);
            network.request14.back().push_back(opCode);
            network.request14.back().insert(network.request14.back().end(), reply.begin(), reply.end());
            break;
        case 15:
            network.request15.back().push_back(opCode);
            break;
        case 22:
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
