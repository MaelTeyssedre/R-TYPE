#include "Room.hpp"

rtype::Room::Room(size_t id)
{
    _id = id;
}

rtype::Room::Room(Room &room)
{
    _id = room._id;
    _roomBuffers = room._roomBuffers;
}

size_t rtype::Room::getId() const
{
    return _id;
}

std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> rtype::Room::getRoomBuffer() const
{
    return _roomBuffers;
}

void rtype::Room::setRoomBuffer(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer)
{
    _roomBuffers = roomBuffer;
}

rtype::Room &rtype::Room::operator=(Room &room)
{
    _id = room._id;
    _roomBuffers = room._roomBuffers;
    return *this;
}

void rtype::Room::run()
{
    Game game{_roomBuffers};
    game.run();
}
