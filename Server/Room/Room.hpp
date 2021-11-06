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

class Room { //pense a mettre une loop dans la room
    public:
        Room(int id);
        ~Room();
        void addPlayer(Player &); // comment tu comptes récupérer le player?
        std::vector<Player> getPlayerList() const; // je crois que la room va etre le "main" du thread , c'est bien ca?
        int getId() const;
    protected:
    private:
        std::vector<std::pair<std::string, std::string>> _roomBuffers;
        std::vector<Player> _playerList;
        int _id;

};

#endif /* !ROOM_HPP_ */
