#include "PacketManager.hpp"

rtype::PacketManager::PacketManager(std::shared_ptr<std::vector<size_t>> idCreator,  std::shared_ptr<std::vector<std::pair<size_t, size_t>>> idJoiner, std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> roomList)
    : _idCreator(idCreator), _idJoiner(idJoiner), _roomList(roomList)
{
}

auto rtype::PacketManager::_createRoom(IPacket *packet) -> void
{
    _idCreator->push_back(packet->getId());
    _isCreateSended.push_back(std::pair(false, packet->getId()));
}

auto rtype::PacketManager::_joinRoom(IPacket *packet) -> void
{
    _idJoiner->push_back(std::pair(packet->getId(), packet->unpack().at(1)));
    _isJoinSended.push_back(std::pair(false, packet->getId()));
}

auto rtype::PacketManager::_getRooms(IPacket *packet) ->void
{
    _isGetSended.push_back(std::pair(false, packet->getId()));
}

auto rtype::PacketManager::sendToClient(rtype::PlayerData &player, std::vector<uint8_t> request) -> void
{
    player._mutexOut->lock();
    player.getBufOut()->push_back(request);
    player._mutexOut->unlock();
}

auto rtype::PacketManager::managePacket() -> void
{
    /*for (; _packetsIn.size();) {
        for (size_t i = 0; i < (*_roomList).size(); i++)
            for (size_t j = 0; j < (*_roomList)[i].size(); j++)
                if ((*_roomList)[i][j].getId() == _packetsIn.front()->getId())
                {
                    sendToClient((*_roomList)[i][j], _packetsIn.front()->unpack());
                    return;
                }*/
    if (_packetsIn.size() && _packetsIn.front()->unpack().size())
    {
        auto tmp = _packetsIn.front()->unpack();
        if (!tmp.empty())
        {
            if (tmp.at(0) == 18)
            {
                std::cout << "getted request 18" << std::endl;
                if (_roomList->size() <= 5 && !_findPlayer(_packetsIn.front()->getId())) //check value return
                    _createRoom(_packetsIn.front());
            }
            else if (tmp.at(0) == 19)
            {
                std::cout << "getted request 19" << std::endl;
                if (!_findPlayer(_packetsIn.front()->getId()) && _roomList->size() >= tmp[1] && _getNbPlayersInRoom(_packetsIn.front()->unpack().at(1)) < 4)
                    _joinRoom(_packetsIn.front());
            }
            else if (tmp.at(0) == 23)
            {
                std::cout << "getted request 23" << std::endl;
                _getRooms(_packetsIn.front());
            }
            else
            {
                std::cerr << "Packet received from " << _packetsIn.front()->getId() << " is undefined size : " << tmp.size() << " | opcode : " << (int)(tmp.at(0)) << std::endl;
            }
        }
        _packetsIn.pop();
    }
    
}

auto rtype::PacketManager::setBufferI(std::queue<IPacket *> *buffer) -> void
{
    for (; buffer && !buffer->empty();)
    {
        _packetsIn.push(buffer->front());
        buffer->pop();
    }
}

auto rtype::PacketManager::getRequestsToSend() -> std::vector<IPacket *> &
{
    return _packetsOut;
}

auto rtype::PacketManager::_setDataRoom() -> std::vector<size_t>
{
    std::vector<size_t> vec{};
    for (auto i : *_roomList) {
        vec.push_back(i.first.size());
    }
    return vec;
}

auto rtype::PacketManager::_getNbPlayersInRoom(size_t idRoom) -> size_t
{
    for (auto it : *_roomList)
        if (idRoom == it.second)
            return(it.first.size());
    throw std::invalid_argument("invalid id user");

}

auto rtype::PacketManager::_getRoomByPlayer(size_t id) -> size_t
{
    size_t idRoom = 0;

    for (auto room : *_roomList) {
        for (auto player: room.first) {
            if (id == player.getId())
                return (idRoom);
        }
        idRoom++;
    }
    throw std::invalid_argument("invalid id user");
}

auto rtype::PacketManager::_findPlayer(size_t id) -> bool
{
   for (auto room : *_roomList) {
        for (auto player: room.first) {
            if (id == player.getId())
                return (true);
        }
    }
   return (false);
}

auto rtype::PacketManager::manageResponse() -> void
{
   static std::vector<size_t> dataRooms {};

   for (auto &i : _isCreateSended)
       if (!i.first) {
           if (dataRooms.size() != _roomList->size()) {
               dataRooms = _setDataRoom();
               IPacket* packet = new Packet();
               packet->setId(i.second);
               std::vector<uint8_t> vec{};
               vec.push_back((uint8_t)12);
               vec.push_back((uint8_t)_getRoomByPlayer(i.second));
               packet->pack(vec);
               _packetsOut.push_back(packet);
           }
           i.first = true;
      }
   for (auto &i : _isJoinSended)
       if (!i.first) {
           if (dataRooms.size() != _roomList->size()) {
               dataRooms = _setDataRoom();
               IPacket* packet = new Packet();
               packet->setId(i.second);
               packet->pack(std::vector<uint8_t> {10});
               _packetsOut.push_back(packet);
           }
           i.first = true;
       }
    for (auto &i : _isGetSended)
       if (!i.first) {
           if (dataRooms.size() != _roomList->size()) {
               dataRooms = _setDataRoom();
               IPacket* packet = new Packet();
               packet->setId(i.second);
               std::vector<uint8_t> vec{};
               vec.push_back((uint8_t)17);
               for (auto it : *_roomList)
                    vec.push_back((uint8_t)it.second);
               packet->pack(vec);
               _packetsOut.push_back(packet);
           }
           i.first = true;
       }
}