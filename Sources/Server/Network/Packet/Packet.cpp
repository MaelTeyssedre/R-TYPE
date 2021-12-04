#include "Packet.hpp"

size_t rtype::Packet::pack(std::vector<uint8_t> data)
{
    if (data.size())
        std::cout << "size of data " << data[0] << std::endl;
    _packetSize = data.size();
    for (int i = 0; i != data.size(); i++)
        _rawData.push_back(data[i]);
    return (data.size());
}

std::vector<uint8_t> rtype::Packet::unpack()
{
    return (_rawData);
}

void rtype::Packet::setId(size_t id)
{
    _id = id;
}

size_t rtype::Packet::getId()
{
    return (_id);
}

std::vector<uint8_t> rtype::Packet::getData()
{
    return (_rawData);
}
