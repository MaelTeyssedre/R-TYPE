
#include "UpdateNetwork.hpp"
#include "Constants.hpp"

UpdateNetwork::UpdateNetwork(ITCPServer *server, IUDPSocket *socket)
    : _tcpServer(server), _socket(socket) {}

void UpdateNetwork::operator()(Registry &r, SparseArray<components::network_s> &networks)
{
    (void)r;
}
