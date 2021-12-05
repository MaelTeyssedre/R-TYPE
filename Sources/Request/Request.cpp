#include "Request.hpp"

size_t rtype::Request::pack(std::vector<uint8_t> data)
{
    _packetSize = data.size();
    for (int i = 0; i != data.size(); i++)
        _rawData.push_back(data[i]);
    return (data.size());
}

std::vector<uint8_t> rtype::Request::unpack()
{
    return (_rawData);
}

void rtype::Request::setId(size_t id)
{
    _id = id;
}

size_t rtype::Request::getId()
{
    return (_id);
}

std::vector<uint8_t> rtype::Request::getData()
{
    return (_rawData);
}
