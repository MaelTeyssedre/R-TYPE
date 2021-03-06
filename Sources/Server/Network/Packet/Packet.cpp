#include "Packet.hpp"

size_t rtype::Packet::pack(std::vector<uint8_t> data)
{
    _packetSize = data.size();
    uint8_t opcode = (!data.empty()) ? data.at(0) : -1;
    int bytes = 0;
    switch (opcode)
    {
         case 1:
            if (data.size() != 16)
                throw std::invalid_argument("Pack.cpp -> pack(): case 1");
            for (int i = 0; i != 16; i++)
                _rawData.push_back(data[i]);
            bytes = 16;
            break;
        case 2:
            if (data.size() != 14)
                throw std::invalid_argument("Pack.cpp -> pack(): case 2");
            for (int i = 0; i != 14; i++)
                _rawData.push_back(data[i]);
            bytes = 14;
            break;
        case 3:
            if (data.size() != 13)
                throw std::invalid_argument("Pack.cpp -> pack(): case 3");
            for (int i = 0; i != 13; i++)
                _rawData.push_back(data[i]);
            bytes = 13;
            break;
        case 4:
            if (data.size() != 1)
                throw std::invalid_argument("Pack.cpp -> pack(): case 4");
            _rawData.push_back(data[0]);
            bytes = 1;
            break;
        case 5:
            if (data.size() != 6)
                throw std::invalid_argument("Pack.cpp -> pack(): case 5");
            for (int i = 0; i != 6; i++)
                _rawData.push_back(data[i]);
            bytes = 6;
            break;
        case 6:
            if (data.size() != 1)
                throw std::invalid_argument("Pack.cpp -> pack(): case 6");
            _rawData.push_back(data[0]);
            bytes = 1;
            break;
        case 7:
            if (data.size() != 9)
                throw std::invalid_argument("Pack.cpp -> pack(): case 7");
            for (int i = 0; i != 9; i++)
                _rawData.push_back(data[i]);
            bytes = 9;
            break;
        case 8:
            if (data.size() != 17)
                throw std::invalid_argument("Pack.cpp -> pack(): case 8");
            for (int i = 0; i != 17; i++)
                _rawData.push_back(data[i]);
            bytes = 17;
            break;
        case 9: {
            if (data.size() != 5)
                throw std::invalid_argument("Pack.cpp -> pack(): case 9");
            int value = data.at(1) | (data.at(2) << 8) | (data.at(3) << 16) | (data.at(4) << 24);
            for (int i = 0; i != 5 + value; i++)
                _rawData.push_back(data[i]);
            bytes = 5 + value;
            break;
        }
        case 10:
            if (data.size() != 1)
                throw std::invalid_argument("Pack.cpp -> pack(): case 10");
            _rawData.push_back(data[0]);
            bytes = 1;
            break;
        case 11:
            if (data.size() != 1)
                throw std::invalid_argument("Pack.cpp -> pack(): case 11");
            _rawData.push_back(data[0]);
            bytes = 1;
            break;
        case 12:
            if (data.size() != 2)
                throw std::invalid_argument("Pack.cpp -> pack(): case 12");
            for (int i = 0; i != 2; i++)
                _rawData.push_back(data[i]);
            bytes = 2;
            break;
        case 13:
            if (data.size() != 2)
                throw std::invalid_argument("Pack.cpp -> pack(): case 13");
            for (int i = 0; i != 2; i++)
                _rawData.push_back(data[i]);
            bytes = 2;
            break;
        case 14:
            if (data.size() != 2)
                throw std::invalid_argument("Pack.cpp -> pack(): case 14");
            for (int i = 0; i != 2; i++)
                _rawData.push_back(data[i]);
            bytes = 2;
                break;
        case 15:
            if (data.size() != 1)
                throw std::invalid_argument("Pack.cpp -> pack(): case 15");
            _rawData.push_back(data[0]);
            bytes = 1;
            break;
        case 16:
            if (data.size() != 9)
                throw std::invalid_argument("Pack.cpp -> pack(): case 16");
            for (int i = 0; i != 9; i++)
                _rawData.push_back(data[i]);
            bytes = 9;
            break;
        case 17:
            if (data.size() != 6)
                throw std::invalid_argument("Pack.cpp -> pack(): case 17");
            for (int i = 0; i != 6; i++)
                _rawData.push_back(data[i]);
            bytes = 6;
            break;
        case 18:
            if (data.size() != 1)
                throw std::invalid_argument("Pack.cpp -> pack(): case 18");
            _rawData.push_back(data[0]);
            bytes = 1;
            break;
         case 19:
            _rawData.push_back(data[0]);
            bytes = 1;
            break;
         case 20:
            _rawData.push_back(data[0]);
            bytes = 1;
            break;
         case 21:
            _rawData.push_back(data[0]);
            bytes = 1;
            break;
         case 22:
            if (data.size() != 2)
                throw std::invalid_argument("Pack.cpp -> pack(): case 22");
            for (int i = 0; i != 2; i++)
                _rawData.push_back(data[i]);
            bytes = 2;
            break;
         case 23:
            _rawData.push_back(data[0]);
            bytes = 1;
            break;
        default:
            bytes = 0;
            break;
    }
    return (bytes);
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
