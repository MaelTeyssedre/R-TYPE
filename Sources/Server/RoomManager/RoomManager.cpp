#include <mutex>
#include <iostream>
#include <sstream>
#include "RoomManager.hpp"
#include "Room.hpp"
#include <memory>
#include <array>
#include <optional>
#include <string>

rtype::RoomManager::RoomManager(std::shared_ptr<std::vector<std::vector<PlayerData>>> roomList, std::shared_ptr<Buffer> bufferIn, std::shared_ptr<Buffer> bufferOut)
{
    _roomList = roomList;
    _bufferIn = bufferIn;
    _bufferOut = bufferOut;
}

rtype::RoomManager::~RoomManager()
{
    for (size_t i = 0; i != _threadList.size(); i++)
        _threadList.at(i).join();
}

void rtype::RoomManager::runRoom(size_t id)
{
    Room room(id);
    room.run();
}

void rtype::RoomManager::createRoom(std::string &packet)
{
    size_t pos = 0;
    size_t playerId = 0;
    std::vector<std::string> parsed;
    std::shared_ptr<Buffer> buffIn(std::make_shared<Buffer>(Buffer(8192)));
    std::shared_ptr<Buffer> buffOut(std::make_shared<Buffer>(Buffer(8192)));
    std::thread room(&rtype::RoomManager::runRoom, this, _roomList->size());
    std::vector<PlayerData> playerData;
    std::string request = "Join ";
    while ((pos = packet.find(" ")) != std::string::npos)
    {
        parsed.push_back(packet.substr(0, pos + 1));
        packet.erase(0, pos + 1);
    }
    parsed.push_back(packet.substr(0, packet.size()));
    packet.erase(0, packet.size());
    playerId = std::stoi(parsed[1]);
    request += std::to_string(_roomList->size()) + " " + std::to_string(playerId);
    _threadList.push_back(move(room));
    _roomList->push_back(playerData);
    joinRoom(request);
}

std::string rtype::RoomManager::joinRoom(std::string &packet)
{
    size_t pos = 0;
    size_t roomId = 0;
    size_t playerId = 0;
    std::vector<std::string> parsed;
    std::shared_ptr<Buffer> buffIn(std::make_shared<Buffer>(Buffer(8192)));
    std::shared_ptr<Buffer> buffOut(std::make_shared<Buffer>(Buffer(8192)));
    std::shared_ptr<std::mutex> mutexIn(std::make_shared<std::mutex>());
    std::shared_ptr<std::mutex> mutexOut(std::make_shared<std::mutex>());
    std::string result = "";
    while ((pos = packet.find(" ")) != std::string::npos)
    {
        parsed.push_back(packet.substr(0, pos + 1));
        packet.erase(0, pos + 1);
    }
    parsed.push_back(packet.substr(0, packet.size()));
    packet.erase(0, packet.size());
    playerId = std::stoi(parsed[2]);
    roomId = std::stoi(parsed[1]);
    if (_roomList->at(roomId).size() > 3)
        return ("KO");
    _roomList->at(roomId).push_back(PlayerData(playerId, buffIn, buffOut, mutexIn, mutexOut));
    result = std::to_string(playerId) + " OK " + std::to_string(roomId);
    return (result);
}

void rtype::RoomManager::redirectRequest(std::vector<std::string> &packetList)
{
    std::vector<uint8_t> vec;
    std::string result = "";
    for (auto &packet : packetList)
        if (packet.find("Join") != std::string::npos)
        {
            result = joinRoom(packet);
            vec.assign(result.begin(), result.end());
            _bufferOut->putInBuffer(static_cast<uint16_t>(vec.size()), vec);
        }
        else if (packet.find("Create") != std::string::npos)
            createRoom(packet);
        else
        {
            result = "KO";
            vec.assign(result.begin(), result.end());
            _bufferOut->putInBuffer(static_cast<uint16_t>(vec.size()), vec);
        }
}

void rtype::RoomManager::manageRoom()
{
    size_t pos = 0;
    uint16_t readSize = 64;
    std::vector<uint8_t> buff(8192);
    std::vector<std::string> packetList;
    _bufferIn->readFromBuffer(readSize, buff);
    std::string str(buff.begin(), buff.end());
    while ((pos = str.find(";")) != std::string::npos)
    {
        packetList.push_back(str.substr(0, pos + 1));
        str.erase(0, pos + 1);
    }
    redirectRequest(packetList);
}