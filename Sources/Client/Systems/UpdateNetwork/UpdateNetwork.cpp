
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
        std::shared_ptr<Buffer> buffer = _tcpClient->getBuffer();
        buffer->readFromBuffer(1, &opCode);
        switch (opCode)
        {
        case 1: {
            std::cout << "pushing 1" << std::endl;
            buffer->readFromBuffer(15, reply);
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request1.push_back(std::move(tmpBuf));
            network.request1.back().insert(network.request1.back().end(), reply.begin(), reply.end());
            break;
        }
        case 2: {
            std::cout << "pushing 2" << std::endl;
            buffer->readFromBuffer(13, reply);
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request2.push_back(std::move(tmpBuf));
            network.request2.back().insert(network.request2.back().end(), reply.begin(), reply.end());
            break;
        }
        case 3: {
            std::cout << "pushing 3" << std::endl;
            network.request3.clear();
            buffer->readFromBuffer(12, reply);
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request3.push_back(std::move(tmpBuf));
            network.request3.back().insert(network.request3.back().end(), reply.begin(), reply.end());
            break;
        }
        case 4: {
            std::cout << "pushing 4" << std::endl;
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request4.push_back(std::move(tmpBuf));
            break;
        }
        case 7: {
            std::cout << "pushing 7" << std::endl;
            buffer->readFromBuffer(8, reply);
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request7.push_back(std::move(tmpBuf));
            network.request7.back().insert(network.request7.back().end(), reply.begin(), reply.end());
            break;
        }
        case 8: {
            std::cout << "pushing 8" << std::endl;
            buffer->readFromBuffer(17, reply);
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request8.push_back(std::move(tmpBuf));
            network.request8.back().insert(network.request8.back().end(), reply.begin(), reply.end());
            break;
        }
        case 9: {
            std::cout << "pushing 9" << std::endl;
            buffer->readFromBuffer(4, reply);
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request9.push_back(std::move(tmpBuf));
            network.request9.back().insert(network.request9.back().end(), reply.begin(), reply.end());
            break;
        }
        case 10: {
            std::cout << "pushing 10" << std::endl;
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request10.push_back(std::move(tmpBuf));
            break;
        }
        case 11: {
            std::cout << "pushing 11" << std::endl;
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request11.push_back(std::move(tmpBuf));
            break;
        }
        case 12: {
            std::cout << "pushing 12" << std::endl;
            buffer->readFromBuffer(8, reply);
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request12.push_back(std::move(tmpBuf));
            network.request12.back().insert(network.request12.back().end(), reply.begin(), reply.end());
            break;
        }
        case 13: {
            std::cout << "pushing 13" << std::endl;
            buffer->readFromBuffer(1, reply);
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request13.push_back(std::move(tmpBuf));
            network.request13.back().insert(network.request13.back().end(), reply.begin(), reply.end());
            break;
        }
        case 14: {
            std::cout << "pushing 14" << std::endl;
            buffer->readFromBuffer(1, reply);
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request14.push_back(std::move(tmpBuf));
            network.request14.back().insert(network.request14.back().end(), reply.begin(), reply.end());
            break;
        }
        case 15: {
            std::cout << "pushing 15" << std::endl;
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request15.push_back(std::move(tmpBuf));
            break;
        }
        case 16: {
            std::cout << "pushing 16" << std::endl;
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            network.request16.push_back(std::move(tmpBuf));
            break;
        }
         case 17: {
            std::cout << "pushing 17" << std::endl;
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            buffer->readFromBuffer(5, tmpBuf);
            network.request17.push_back(std::move(tmpBuf));
            break;
        }
        case 22: {
            std::cout << "pushing 22" << std::endl;
            std::vector<uint8_t> tmpBuf{};
            tmpBuf.push_back(opCode);
            buffer->readFromBuffer(1, tmpBuf);
            network.request22.push_back(std::move(tmpBuf));
            break;
        }
        default:
            std::cout << "OPCODE : " << (int)opCode << std::endl;
            break;
        }
        if (!(network.sendRequest.empty()) && !network.sendRequest.front().empty()) {
            IPacket* packet = new Packet();
            packet->pack(network.sendRequest.front());
            std::cout << "Sending: " << static_cast<int>(packet->unpack().at(0)) << " nb bytes: " << packet->unpack().size() << std::endl;
            _tcpClient->send(*packet);
            network.sendRequest.erase(network.sendRequest.begin());

        }
    }
}
