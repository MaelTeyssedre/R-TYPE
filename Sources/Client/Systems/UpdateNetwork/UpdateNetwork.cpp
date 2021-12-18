
#include "UpdateNetwork.hpp"
#include "Constants.hpp"

rtype::UpdateNetwork::UpdateNetwork(ITCPClient* client, IUDPSocket* socket)
	: _tcpClient(client), _socket(socket) {}

void rtype::UpdateNetwork::operator()(Registry& r, SparseArray<components::network_s>& networks)
{
	(void)r;
	for (auto&& [network] : Zipper(networks))
	{
		uint8_t opCode = 0;
		_tcpClient->receive();
		std::shared_ptr<Buffer> buffer = _tcpClient->getBuffer();
		buffer->readFromBuffer(1, &opCode);
		switch (opCode)
		{
		case 1:
			network.request1.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(15, network.request1.back());
			break;
		case 2:
			network.request2.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(13, network.request2.back());
			break;
		case 3:
			network.request3.clear();
			network.request3.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(12, network.request3.back());
			break;
		case 4:
			network.request4.push_back(std::move(std::vector<uint8_t>{ opCode }));
			break;
		case 7:
			network.request7.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(8, network.request7.back());
			break;
		case 8:
			network.request8.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(17, network.request8.back());
			break;
		case 9:
			network.request9.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(4, network.request9.back());
			break;
		case 10:
			network.request10.push_back(std::move(std::vector<uint8_t>{ opCode }));
			break;
		case 11:
			network.request11.push_back(std::move(std::vector<uint8_t>{ opCode }));
			break;
		case 12:
			network.request12.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(8, network.request12.back());
			break;
		case 13:
			network.request13.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(1, network.request13.back());
			break;
		case 14:
			network.request14.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(1, network.request14.back());
			break;
		case 15:
			network.request15.push_back(std::move(std::vector<uint8_t>{ opCode }));
			break;
		case 16:
			network.request16.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(1, network.request16.back());
			break;
		case 17:
			network.request17.push_back(std::move(std::vector<uint8_t>{ opCode }));
			buffer->readFromBuffer(5, network.request17.back());
			break;
		case 22:
			network.request22.push_back(std::move(std::vector<uint8_t> {opCode}));
			buffer->readFromBuffer(1, network.request22.back());
			break;
		default:
			break;
		}
		if (!network.sendRequest.empty() && !network.sendRequest.front().empty()) {
			IPacket* packet = new Packet();
			packet->pack(network.sendRequest.front());
			if (packet->unpack().at(0) == 19)
				std::cout << "t" << std::endl;
			std::cout << "Sending: " << static_cast<int>(packet->unpack().at(0)) << " nb bytes: " << packet->unpack().size() << std::endl;
			_tcpClient->send(*packet);
			network.sendRequest.erase(network.sendRequest.begin());

		}
	}
}
