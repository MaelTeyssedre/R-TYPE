/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** RoomManager
*/

#ifndef ROOMMANAGER_HPP_
#define ROOMMANAGER_HPP_

#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <memory>
#include "Buffer.hpp"
#include "PlayerData.hpp"
#include "RoomData.hpp"

class RoomManager {
    public:
        RoomManager() = default;
        RoomManager(RoomManager &);
        RoomManager& operator=(RoomManager &);
        ~RoomManager();
        std::string joinRoom(std::string &);
        void manageRoom(Buffer &, Buffer &);
        void isRoomNeedeed(std::vector<std::string> &, Buffer &);
        void createRoom(std::string &packet);
        void isRoom(size_t id);
        void RoomManager::addressToVec(Buffer &);
    protected:
    private:
        std::vector<std::pair<std::thread, RoomData>> _roomList;
        //std::vector<roomInfo> _roomList;
        // Vector de -> int nb_players_in_room, std::thread room thread, mutex buffIn, Buffer buffIn, mutex buffOut, Buffer buffOut
        //std::vector<std::pair<int, std::thread>> _roomList;
};

#endif /* !ROOMMANAGER_HPP_ */
