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

    class Room {
        public:
            explicit Room() = default;
            explicit Room(size_t id);
            explicit Room(Room &);
            virtual ~Room() = default;
            size_t getId() const;
            std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> getRoomBuffer() const;
            Room& operator=(Room &room);
            void setRoomBuffer(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &);
        private:
            std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> _roomBuffers;
            size_t _id;

    };

#endif /* !ROOM_HPP_ */
