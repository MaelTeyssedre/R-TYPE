#include <mutex>
#include <iostream>
#include <sstream>
#include "RoomManager.hpp"
#include "Room.hpp"
#include <memory>
#include <array>
#include <optional>
#include <string>

rtype::RoomManager::RoomManager(std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> roomList, std::shared_ptr<std::vector<size_t>> idCreator, std::shared_ptr<std::vector<std::pair<size_t, size_t>>> idJoiner)
    : _roomList(roomList), _idCreator(idCreator), _idJoiner(idJoiner) {}

auto rtype::RoomManager::getIdToCreate()->size_t
{
    for (int i = 0; i < 5; i++)
    {
        bool idExist = false;
        for (auto j : *_roomList)
            if (j.second == i + 1)
            {
                idExist = true;
                break;
            }
        if (idExist)
            continue;
        return i + 1;
    }
    return 0;
}

auto rtype::RoomManager::createRoom() -> void
{
    _roomList->push_back(std::pair(std::vector<PlayerData>{}, getIdToCreate()));
    _roomList->back().first.push_back(PlayerData(_idCreator->front()));
    _idCreator->erase(_idCreator->begin());
    Room* room = new Room(&(_roomList->back().first));
}

auto rtype::RoomManager::joinRoom() -> void
{
    for (auto j : *_idJoiner)
        for (auto i : *_roomList)
            if (i.second == j.second)
                i.first.push_back(PlayerData(j.first));
    _idJoiner->erase(_idJoiner->begin());
}

void rtype::RoomManager::manageRoom()
{
    if (!_idCreator->empty())
        createRoom();
    if (!_idJoiner->empty())
        joinRoom();
}