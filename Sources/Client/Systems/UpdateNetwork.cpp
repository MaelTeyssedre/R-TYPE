
#include "UpdateNetwork.hpp"
#include "Constants.hpp"

UpdateNetwork::UpdateNetwork()
{
}

UpdateNetwork::~UpdateNetwork()
{
}

void UpdateNetwork::operator()(Registry &r,  SparseArray<components::network_t> &networks)
{
    (void)r;

    std::optional<components::network_t> &network = networks[rtype::constants::RESERVED_ID::NETWORK_UPDATE];
    std::vector<uint8_t> request;

    if (network) {
        tcpCLient.receive();
        request = TCPClient.getData();
        if (request.front() == "1")
            network.value().request1.push_back(request);
    }
}