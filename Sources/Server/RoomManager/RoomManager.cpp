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

auto rtype::RoomManager::getIdToCreate() -> size_t
{
    if (!(_roomList->size()))
        return 0;
    for (auto i = 0; i < _roomList->size(); i++)
    {
        auto idAlreadyExit = false;
        for (auto j : *_roomList)
            idAlreadyExit = (j.second == i) ? true: idAlreadyExit;
        if (!idAlreadyExit)
            return i;
    }
    throw std::runtime_error("no free id");
}

auto rtype::RoomManager::createRoom() -> void
{
    auto id = getIdToCreate();
    _roomList->push_back(std::pair(std::vector<PlayerData>{}, id));
    _roomList->back().first.push_back(PlayerData(_idCreator->front()));
    _idCreator->clear();
    std::cout << "ICI" << std::endl;
    Room* room = new Room(&(_roomList->back().first));
}

auto rtype::RoomManager::joinRoom() -> void
{
    for (auto j : *_idJoiner)
        for (auto i : *_roomList)
            if (i.second == j.second)
                i.first.push_back(PlayerData(j.first));
    _idJoiner->clear();
}

void rtype::RoomManager::manageRoom()
{
    if (_idCreator->size())
        createRoom();
    if (_idJoiner->size())
        joinRoom();
}