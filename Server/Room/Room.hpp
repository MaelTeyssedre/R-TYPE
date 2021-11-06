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
#include "Player.hpp"

class Room {
    public:
        Room(int id);
        ~Room();
        void addPlayer(Player &);
        std::vector<Player> getPlayerList() const;
        int getId() const;
    protected:
    private:
        std::vector<std::pair<std::string, std::string>> _roomBuffers;
        std::vector<Player> _playerList;
        int _id;

};

#endif /* !ROOM_HPP_ */
