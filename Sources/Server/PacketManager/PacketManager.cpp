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

auto rtype::PacketManager::sendToPlayer(rtype::PlayerData &player, std::vector<uint8_t> request) -> void
{
    player.getBufIn()->push_back(request);
}

auto rtype::PacketManager::managePacket() -> void
{
    if (_packetsIn.size() && _packetsIn.front()->unpack().size())
    {
        auto tmp = _packetsIn.front()->unpack();
        if (!tmp.empty())
        {
            if (tmp.at(0) == 18)
            {
                if (_roomList->size() <= 5 && !_findPlayer(_packetsIn.front()->getId()))
                    _createRoom(_packetsIn.front());
            }
            else if (tmp.at(0) == 19)
            {
                if (!_findPlayer(_packetsIn.front()->getId()) && _roomList->size() >= tmp[1] && _getNbPlayersInRoom(_packetsIn.front()->unpack().at(1)) < 4)
                    _joinRoom(_packetsIn.front());
            }
            else if (tmp.at(0) == 23)
            {
                _getRooms(_packetsIn.front());
            }
            else
            {
                sendToPlayer(*_findPlayer(_packetsIn.front()->getId()), tmp);
                //std::cerr << "Packet received from " << _packetsIn.front()->getId() << " is undefined size : " << tmp.size() << " | opcode : " << (int)(tmp.at(0)) << std::endl;
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

auto rtype::PacketManager::_findPlayer(size_t id) -> PlayerData*
{
   for (auto room : *_roomList) {
        for (auto player: room.first) {
            if (id == player.getId())
                return (&player);
        }
    }
   return (nullptr);
}

auto rtype::PacketManager::manageResponse() -> void
{
   static std::vector<size_t> dataRooms {};

   for (auto &i : _isCreateSended)
       if (!i.first) {
            IPacket* packet = new Packet();
            packet->setId(i.second);
            std::vector<uint8_t> vec{};
            vec.push_back((uint8_t)12);
            vec.push_back((uint8_t)_getRoomByPlayer(i.second));
            packet->pack(vec);
            _packetsOut.push_back(packet);
            i.first = true;
            _isCreateSended.erase(_isCreateSended.begin());
      }
   for (auto &i : _isJoinSended)
       if (!i.first) {
            IPacket* packet = new Packet();
            packet->setId(i.second);
            packet->pack(std::vector<uint8_t> {10});
            _packetsOut.push_back(packet);
            i.first = true;
            _isJoinSended.erase(_isGetSended.begin());
       }
    for (auto &i : _isGetSended)
       if (!i.first) {
            IPacket* packet = new Packet();
            packet->setId(i.second);
            std::vector<uint8_t> vec{};
            vec.push_back((uint8_t)17);
            for (auto i = 0; i < 5; i++) {
                bool indexExist = false;
                for (auto it : *_roomList) {
                    indexExist = (it.second == i) ? vec.push_back((uint8_t)i), true : indexExist;
                }
                if (!indexExist)
                    vec.push_back((uint8_t)6);
            }
            packet->pack(vec);
            _packetsOut.push_back(packet);
            i.first = true;
            _isGetSended.erase(_isGetSended.begin());
       }
}