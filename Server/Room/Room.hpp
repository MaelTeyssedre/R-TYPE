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

class Room { //pense a mettre une loop dans la room
    public:
        Room(size_t id);
        ~Room();
        int getId() const;
    protected:
    private:
        std::vector<std::pair<std::string, std::string>> _roomBuffers;
        int _id;

};

#endif /* !ROOM_HPP_ */
