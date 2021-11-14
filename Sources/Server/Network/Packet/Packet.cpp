/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Packet
*/

#include "Packet.hpp"

//TODO convert to map<opcode, &function>

size_t Packet::pack(std::vector<uint8_t> &data)
{
    _packetSize = data.size();
    uint8_t opcode = data.at(0);
    if (opcode == 1) {
        for (int i = 0; i !=16; i++) {
            _rawData->push_back(data.at(i));
            data.erase(data.begin(), data.begin() + 16);
        }
        return (16);
    }
    if (opcode == 2) {
        for (int i = 0; i != 14; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 14);
        }
        return (14);
    }
    if (opcode == 3) {
        for (int i = 0; i !=13; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 13);
        }
        return (13);
    }
    if (opcode == 4) {
        for (int i = 0; i !=1; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 1);
        }
        return (1);
    }
    if (opcode == 5) {
        for (int i = 0; i !=6; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 6);
        }
        return (6);
    }
    if (opcode == 6) {
        for (int i = 0; i !=1; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 1);
        }
        return (1);
    }
    if (opcode == 7) {
        for (int i = 0; i !=9; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 9);
        }
        return (9);
    }
    if (opcode == 8) {
        for (int i = 0; i !=17; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 17);
        }
        return (17);
    }
    if (opcode == 9) {
        int value = data.at(1) | (data.at(2) << 8) | (data.at(3) << 16) | (data.at(4) << 24);
        std::cout << value << std::endl;
        for (int i = 0; i != 5 + value; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + value);
        }
        return (5 + value);
    }
    if (opcode == 10) {
        for (int i = 0; i !=1; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 1);
        }
        return (1);
    }
    if (opcode == 11) {
        for (int i = 0; i !=1; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 1);
        }
        return (1);
    }
    if (opcode == 12) {
        for (int i = 0; i !=9; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 9);
        }
        return (9);
    }
    if (opcode == 13) {
        for (int i = 0; i !=2; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 2);
        }
        return (2);
    }
    if (opcode == 14) {
        for (int i = 0; i !=2; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 2);
        }
        return (2);
    }
    if (opcode == 15) {
        for (int i = 0; i !=1; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 1);
        }
        return (1);
    }
    if (opcode == 16) {
        for (int i = 0; i != 9; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 9);
        }
        return (9);
    }
    if (opcode == 17) {
        for (int i = 0; i !=1; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 1);
        }
        return (1);
    }
    if (opcode == 18) {
        for (int i = 0; i !=1; i++) {
            _rawData->push_back(i);
            data.erase(data.begin(), data.begin() + 1);
        }
        return (1);
    }
    return (0);
}

std::shared_ptr<std::vector<uint8_t>> Packet::unpack()
{
    return (_rawData);
}