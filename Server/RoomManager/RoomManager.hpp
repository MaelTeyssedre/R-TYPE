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

class RoomManager {
    public:
        RoomManager(std::string &, std::string &);
        ~RoomManager();
        void manageRoom(int);
        void isRoomNeedeed();
        void createRoom();
        void fillBufferIn(std::string &);
    protected:
    private:
    int _lastRoomId;
    std::string _bufferIn;
    std::string _bufferOut;
    std::vector<std::pair<int, std::thread>> _roomList;

};

#endif /* !ROOMMANAGER_HPP_ */
