/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Room
*/

#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <string>
#include <thread>
#include <vector>
#include "Buffer.hpp"

class Room { //pense a mettre une loop dans la room
    public:
        Room() = default;
        Room(size_t id);
        Room(Room &);
        ~Room();
        int getId() const;
        std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> getRoomBuffer() const;
        Room& operator=(Room &room);
        void setRoomBuffer(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &);

    protected:
    private:
        std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> _roomBuffers;
        int _id;

};

#endif /* !ROOM_HPP_ */
