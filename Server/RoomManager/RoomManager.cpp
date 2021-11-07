/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** RoomManager
*/

#include <mutex>
#include <iostream>
#include <sstream>
#include "RoomManager.hpp"
#include "Room.hpp"

RoomManager& RoomManager::operator=(RoomManager &roomManager)
{
//    _bufferIn = roomManager._bufferIn;
//    _bufferOut = roomManager._bufferOut;
    return(*this);
}

RoomManager::RoomManager(RoomManager &roomManager)
{
//    _bufferIn = roomManager._bufferIn;
}

RoomManager::~RoomManager()
{
    for (auto &room : _roomList)
        room.first.join();
}

void RoomManager::isRoom(size_t id)
{
    Room room(id);
}

void RoomManager::createRoom(std::string &packet)
{
    size_t pos = 0;
    size_t playerId = 0;
    std::vector<std::string> parsed;
    std::thread room(&RoomManager::isRoom, this, _roomList.size());
    std::vector<PlayerData> playerData;
    RoomData roomData;

    
    while ((pos = packet.find(" ")) != std::string::npos) {
        parsed.push_back(packet.substr(0, pos + 1));
        packet.erase(0, pos + 1);
    }
    parsed.push_back(packet.substr(0, packet.size()));
        packet.erase(0, packet.size());
    playerData.push_back(PlayerData(playerId));
    roomData.setRoomData(std::make_pair(_roomList.size(), playerData));
    playerId = std::stoi(parsed[1]);
    _roomList.push_back(std::make_pair(move(room), roomData));
}

std::string RoomManager::joinRoom(std::string &packet)
{
    size_t pos = 0;
    size_t roomId = 0;
    size_t playerId = 0;
    std::vector<std::string> parsed;
    std::string result = "";

    while ((pos = packet.find(" ")) != std::string::npos) {
        parsed.push_back(packet.substr(0, pos + 1));
        packet.erase(0, pos + 1);
    }
    parsed.push_back(packet.substr(0, packet.size()));
        packet.erase(0, packet.size());
    playerId = std::stoi(parsed[2]);
    roomId = std::stoi(parsed[1]);
    _roomList[roomId].second.getRoomData().second.push_back(PlayerData(playerId));
    result = std::to_string(playerId) + " OK " + std::to_string(roomId);
    return (result);
}

void RoomManager::addressToVec(Buffer &buffOut)
{
    std::vector<uint8_t> vec;
    std::string addressStr;
    void *address = static_cast<void*>(&_roomList);
    std::stringstream ss;

    ss << address;  
    addressStr = ss.str();
    std::cout << "The _roomList address is " << addressStr << std::endl;
    vec.assign(addressStr.begin(), addressStr.end());
    buffOut.putInBuffer(static_cast<uint16_t>(vec.size()), vec);
}

void RoomManager::isRoomNeedeed(std::vector<std::string> &packetList, Buffer &buffOut)
{
    std::vector<uint8_t> vec;
    std::string result = "";

    for (auto &packet : packetList) {
        std::cout << "I'm the Packet: " << packet << std::endl;
        std::cout << "I'm the PacketSize: " << packetList.size() << std::endl;
        if (packet.find("Join") != std::string::npos) {
            std::cout << "I'm Joining" << std::endl;
            result = joinRoom(packet);
            std::cout << "We're exactly: " << _roomList[0].second.getRoomData().second.size() << std::endl;
            vec.assign(result.begin(), result.end());
            buffOut.putInBuffer(static_cast<uint16_t>(vec.size()), vec);
        } else if (packet.find("Create") != std::string::npos) {
            std::cout << "I'm Creating: " << std::endl;
            createRoom(packet);
            std::cout << "I'm the RoomListSize: " << _roomList.size() << std::endl;
            addressToVec(buffOut);
        } else {
            result = "KO";
            vec.assign(result.begin(), result.end());
            buffOut.putInBuffer(static_cast<uint16_t>(vec.size()), vec);
        }
    }
}

void RoomManager::manageRoom(Buffer &buffIn, Buffer &buffOut)
{
    size_t pos = 0;
    uint16_t readSize = 27;
    std::vector<uint8_t> buff(27);
    std::vector<std::string> packetList;
    buffIn.readFromBuffer(readSize, buff);
    std::string str(buff.begin(), buff.end());

    while ((pos = str.find(";")) != std::string::npos) {
        packetList.push_back(str.substr(0, pos + 1));
        str.erase(0, pos + 1);

    }
    isRoomNeedeed(packetList, buffOut);
}