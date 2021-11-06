/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** RoomManager
*/

#include <mutex>
#include <iostream>
#include "RoomManager.hpp"
#include "Room.hpp"

std::mutex mtx;

void RoomManager::manageRoom(int roomId, IPC &ipc)
{
    std::lock_guard<std::mutex> lock(mtx);
    std::string code = "Connect";
    std::string data;
    Room room(roomId);

    while (room.getPlayerList().size() != 4) {
        data = ipc.takeData(code.size());
        if (data.find(code) != std::string::npos)
            room.addPlayer(Player());
        std::cout << "Room " << room.getId() << " has " << room.getPlayerList().size() << "players" << std::endl;
    }
}

RoomManager::RoomManager(std::string &bufferIn, std::string &bufferOut)
{
    _bufferIn = bufferIn;
    _bufferOut = bufferOut;
    _roomList.clear();
    _lastRoomId = 0;
}

RoomManager& RoomManager::operator=(RoomManager &roomManager)
{
    _bufferIn = roomManager._bufferIn;
    _bufferOut = roomManager._bufferOut;
    //_roomList.assign(roomManager._roomList.begin(), roomManager._roomList.end());
    _lastRoomId = roomManager._lastRoomId;
    return(*this);
}

RoomManager::RoomManager(RoomManager &roomManager)
{
    _bufferIn = roomManager._bufferIn;
    _bufferOut = roomManager._bufferOut;
    //_roomList.assign(roomManager._roomList.begin(), roomManager._roomList.end());
    _lastRoomId = roomManager._lastRoomId;
}

RoomManager::~RoomManager()
{
    for (auto &room : _roomList)
        room.second.join();
}

void RoomManager::createRoom(IPC &ipc)
{
    std::thread room(&RoomManager::manageRoom, this, _lastRoomId, ipc);

    _roomList.push_back(std::make_pair(0, move(room)));
    _lastRoomId++;
}

void RoomManager::isRoomNeedeed()
{
    IPC ipc("test");
    std::string code = "Connect";
    size_t pos = 0;

    while ((pos = _bufferIn.find(code)) != std::string::npos) {
        ipc.sendData(code);
        if (_roomList.size() == 0 || _roomList.back().first == 4)
            createRoom(ipc);
        _roomList.back().first += 1;
        _bufferIn.erase(pos, pos + code.length());
    }
    _bufferIn.clear();
}

void RoomManager::fillBufferIn(std::string &data)
{
    _bufferIn.append(data);
}