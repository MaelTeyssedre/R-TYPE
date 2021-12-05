#include "PlayerData.hpp"

size_t rtype::PlayerData::getId(void) const
{
    return (_id);
}

auto rtype::PlayerData::getBufIn() -> std::shared_ptr<std::vector<std::vector<uint8_t>>>
{
    return _bufferIn;
}

auto rtype::PlayerData::getBufOut() -> std::shared_ptr<std::vector<std::vector<uint8_t>>>
{
    return _bufferOut;
}