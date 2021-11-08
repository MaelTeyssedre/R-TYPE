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

RoomManager::RoomManager(std::shared_ptr<std::vector<std::pair<std::thread, RoomData>>> roomList,  std::shared_ptr<Buffer> bufferIn,  std::shared_ptr<Buffer> bufferOut)
{
    _roomList = roomList;
    _bufferIn = bufferIn;
    _bufferOut = bufferOut;
}

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
    for (size_t i = 0; i != _roomList->size(); i++)
        _roomList->at(i).first.join();
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
    std::shared_ptr<Buffer> buffIn(std::make_shared<Buffer>(Buffer(8192)));
    std::shared_ptr<Buffer> buffOut(std::make_shared<Buffer>(Buffer(8192)));
    std::thread room(&RoomManager::isRoom, this, _roomList->size());
    std::vector<PlayerData> playerData;
    RoomData roomData;
    std::string request = "Join ";

    while ((pos = packet.find(" ")) != std::string::npos) {
        parsed.push_back(packet.substr(0, pos + 1));
        packet.erase(0, pos + 1);
    }
    parsed.push_back(packet.substr(0, packet.size()));
        packet.erase(0, packet.size());
    playerId = std::stoi(parsed[1]);
    request += std::to_string(0) + " " + std::to_string(playerId);
    roomData.setRoomData(std::make_pair(_roomList->size(), playerData));
    _roomList->push_back(std::make_pair(move(room), roomData));
    joinRoom(request);
}

std::string RoomManager::joinRoom(std::string &packet)
{
    size_t pos = 0;
    size_t roomId = 0;
    size_t playerId = 0;
    std::vector<std::string> parsed;
    std::shared_ptr<Buffer> buffIn(std::make_shared<Buffer>(Buffer(8192)));
    std::shared_ptr<Buffer> buffOut(std::make_shared<Buffer>(Buffer(8192)));
    std::string result = "";

    while ((pos = packet.find(" ")) != std::string::npos) {
        parsed.push_back(packet.substr(0, pos + 1));
        packet.erase(0, pos + 1);
    }
    parsed.push_back(packet.substr(0, packet.size()));
        packet.erase(0, packet.size());
    playerId = std::stoi(parsed[2]);
    roomId = std::stoi(parsed[1]);
    //std::cout << "RoomList Size = " << _roomList->size() << std::endl;
    _roomList->at(roomId).second.getRoomData().second.push_back(PlayerData(playerId, buffIn, buffOut));
    result = std::to_string(playerId) + " OK " + std::to_string(roomId);
    return (result);
}
/*
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
}*/

void RoomManager::isRoomNeedeed(std::vector<std::string> &packetList)
{
    std::vector<uint8_t> vec;
    std::string result = "";

    for (auto &packet : packetList) {
        //std::cout << "I'm the Packet: " << packet << std::endl;
        //std::cout << "I'm the PacketSize: " << packetList.size() << std::endl;
        if (packet.find("Join") != std::string::npos) {
            //std::cout << "I'm Joining" << std::endl;
            result = joinRoom(packet);
            //std::cout << "We're exactly: " << _roomList->at(0).second.getRoomData().second.size() << std::endl;
            vec.assign(result.begin(), result.end());
            _bufferOut->putInBuffer(static_cast<uint16_t>(vec.size()), vec);
        } else if (packet.find("Create") != std::string::npos) {
            //std::cout << "I'm Creating: " << std::endl;
            createRoom(packet);
            //std::cout << "We're exactly: " << _roomList->at(0).second.getRoomData().second.size() << std::endl;

            //std::cout << "I'm the RoomListSize: " << _roomList->size() << std::endl;
        } else {
            result = "KO";
            vec.assign(result.begin(), result.end());
            _bufferOut->putInBuffer(static_cast<uint16_t>(vec.size()), vec);
        }
    }
}

void RoomManager::manageRoom()
{
    size_t pos = 0;
    uint16_t readSize = 4096;
    std::vector<uint8_t> buff(8192);
    std::vector<std::string> packetList;
    _bufferIn->readFromBuffer(readSize, buff);
    std::string str(buff.begin(), buff.end());

    while ((pos = str.find(";")) != std::string::npos) {
        packetList.push_back(str.substr(0, pos + 1));
        str.erase(0, pos + 1);
    }
    isRoomNeedeed(packetList);
}