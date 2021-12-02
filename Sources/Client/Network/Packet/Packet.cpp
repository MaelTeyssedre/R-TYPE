#include "Packet.hpp"

size_t rtype::Packet::pack(std::vector<uint8_t> &data)
{
    _packetSize = data.size();
    uint8_t opcode = data.at(0);
    int bytes = 0;
    switch (opcode)
    {
        case 1:
            for (int i = 0; i != 16; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin(), data.begin() + 15);
            bytes = 16;
            break;
        case 2:
            for (int i = 0; i != 14; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin(), data.begin() + 13);
            bytes = 14;
            break;
        case 3:
            for (int i = 0; i != 13; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin(), data.begin() + 12);
            bytes = 13;
            break;
        case 4:
            _rawData.push_back(data[0]);
            data.erase(data.begin());
            bytes = 1;
            break;
        case 5:
            for (int i = 0; i != 6; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin(), data.begin() + 5);
            bytes = 6;
            break;
        case 6:
            for (int i = 0; i != 1; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin());
            bytes = 1;
            break;
        case 7:
            for (int i = 0; i != 9; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin(), data.begin() + 8);
            bytes = 9;
            break;
        case 8:
            for (int i = 0; i != 17; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin(), data.begin() + 16);
            bytes = 17;
            break;
        case 9: {
            int value = data.at(1) | (data.at(2) << 8) | (data.at(3) << 16) | (data.at(4) << 24);
            for (int i = 0; i != 5 + value; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin(), data.begin() + value - 1);
            bytes = 5 + value;
            break;
        }
        case 10:
            _rawData.push_back(data[0]);
            data.erase(data.begin());
            bytes = 1;
            break;
        case 11:
            _rawData.push_back(data[0]);
            data.erase(data.begin());
            bytes = 1;
            break;
        case 12:
            for (int i = 0; i != 9; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin(), data.begin() + 8);
            bytes = 9;
            break;
        case 13:
            for (int i = 0; i != 2; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin(), data.begin() + 1);
            bytes = 2;
            break;
        case 14:
            for (int i = 0; i != 2; i++)
                _rawData.push_back(data[i]);
            data.erase(data.begin(), data.begin() + 1);
            bytes = 2;
            break;
        case 15:
            _rawData.push_back(data[0]);
            data.erase(data.begin());
            bytes = 1;
            break;
        case 16:
            _rawData.push_back(data[0]);
            data.erase(data.begin());
            bytes = 1;
            break;
        case 17:
            _rawData.push_back(data[0]);
            data.erase(data.begin());
            bytes = 9;
            break;
        case 18:
            _rawData.push_back(data[0]);
            data.erase(data.begin());
            bytes = 1;
            break;
         case 19:
            _rawData.push_back(data[0]);
            data.erase(data.begin());
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