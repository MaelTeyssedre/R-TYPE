/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** RoomManager
*/

#include <mutex>
#include "RoomManager.hpp"
#include "Room.hpp"

std::mutex mtx;

void RoomManager::manageRoom(int roomId)
{
    Room room(roomId);
    
    mtx.lock();
    while (_roomList.back().first != 4)
        if (_bufferIn.find("Player Connect") != std::string::npos) {
            room.addPlayer(Player());
            _roomList.back().first += 1;
        }
    _bufferOut = "Start Game";
    mtx.unlock();
}

RoomManager::RoomManager(std::string &bufferIn, std::string &bufferOut)
{
    _bufferIn = bufferIn;
    _bufferOut = bufferOut;
    _roomList.clear();
    _lastRoomId = 0;

}

RoomManager::~RoomManager()
{
    for (auto &room : _roomList) {
        room.second.join();
    }
}

void RoomManager::createRoom()
{
    std::thread room(&RoomManager::manageRoom, _lastRoomId);
    _roomList.push_back(std::make_pair(0, move(room)));
    _lastRoomId++;
}

void RoomManager::isRoomNeedeed()
{
    while (_bufferIn.find("Player Connect") != std::string::npos) {
        if (_roomList.size() == 0 || _roomList.back().first == 4)
            createRoom();
    }
    this->_bufferIn.clear();
}

void RoomManager::fillBufferIn(std::string &data)
{
    _bufferIn += data;
}