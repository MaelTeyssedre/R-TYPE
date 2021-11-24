
#include "UpdateNetwork.hpp"
#include "Constants.hpp"

UpdateNetwork::UpdateNetwork(ITCPClient *client) : _tcpClient(client)
{
}

UpdateNetwork::~UpdateNetwork()
{
}

void UpdateNetwork::operator()(Registry &r,  SparseArray<components::network_t> &networks)
{
    (void)r;
    std::optional<components::network_t> &network = networks[rtype::constants::RESERVED_ID::NETWORK_UPDATE];
    std::shared_ptr<Buffer> buffer;
    std::uint8_t *opCode;
    std::vector<uint8_t> reply;

    if (network) {
        _tcpClient->receive();
        buffer = _tcpClient->getData();
        buffer->readFromBuffer(1, opCode);
        switch (*opCode)
        {
        case 7:
            buffer->readFromBuffer(8, reply);
            network.value().request7.back().push_back(*opCode);
            network.value().request7.back().emplace_back(reply);
            break;
        case 8:
            buffer->readFromBuffer(16, reply);
            network.value().request8.back().push_back(*opCode);
            network.value().request8.back().emplace_back(reply);
            break;
        case 9:
            buffer->readFromBuffer(4, reply);
            network.value().request9.back().push_back(*opCode);
            network.value().request9.back().emplace_back(reply);
            break;
        case 10:
            network.value().request10.back().push_back(*opCode);
            break;
        case 11:
            network.value().request11.back().push_back(*opCode);
            break;
        case 12:
            buffer->readFromBuffer(8, reply);
            network.value().request12.back().push_back(*opCode);
            network.value().request12.back().emplace_back(reply);
            break;
        case 13:
            buffer->readFromBuffer(1, reply);
            network.value().request13.back().push_back(*opCode);
            network.value().request13.back().emplace_back(reply);
            break;
        case 14:
            buffer->readFromBuffer(1, reply);
            network.value().request14.back().push_back(*opCode);
            network.value().request14.back().emplace_back(reply);
            break;
        case 15:
            buffer->readFromBuffer(0, reply);
            network.value().request15.back().push_back(*opCode);
            break;
        case 16:
            buffer->readFromBuffer(0, reply);
            network.value().request16.back().push_back(*opCode);
            break;
        case 17:
            buffer->readFromBuffer(8, reply);
            network.value().request17.back().push_back(*opCode);
            network.value().request17.back().emplace_back(reply);
            break;
        case 18:
            buffer->readFromBuffer(0, reply);
            network.value().request18.back().push_back(*opCode);
            break;
        case 19:
            buffer->readFromBuffer(0, reply);
            network.value().request19.back().push_back(*opCode);
            break;
        default:
            break;
        }
    }
}